// Mac audio play/stop by GPT
#define _HAS_STD_BYTE 0
#include "audio.h"
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>
#include <atomic>
#include <thread>
#include <chrono>
#endif
#include <string>
using namespace std;

#ifdef _WIN32
void PlayAudio(const string& soundFile) {
    PlaySoundA(("assets/musics/" + soundFile).c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void StopAudio() {
    PlaySoundA(NULL, NULL, 0);
}
#elif __APPLE__
static atomic<bool> keepPlaying(false);
static thread playerThread;

struct PlayerContext {
    ExtAudioFileRef audioFile = nullptr;
    AudioQueueRef queue = nullptr;
    UInt64 packetPos = 0;
    AudioStreamPacketDescription* packetDescs = nullptr;
    UInt32 maxPacketSize = 0;
    UInt32 numPacketsToRead = 1024;
};

static void AQOC(void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer) {
    PlayerContext* ctx = (PlayerContext*)inUserData;
    if (!keepPlaying.load()) {
        AudioQueueStop(ctx->queue, false);
        return;
    }
    UInt32 numPackets = ctx->numPacketsToRead;
    AudioBufferList bufferList;
    bufferList.mNumberBuffers = 1;
    bufferList.mBuffers[0].mData = inBuffer->mAudioData;
    bufferList.mBuffers[0].mDataByteSize = ctx->maxPacketSize * numPackets;
    OSStatus status = ExtAudioFileRead(ctx->audioFile, &numPackets, &bufferList);
    if (status != noErr || numPackets == 0) {
        ExtAudioFileSeek(ctx->audioFile, 0);
        numPackets = ctx->numPacketsToRead;
        status = ExtAudioFileRead(ctx->audioFile, &numPackets, &bufferList);
        if (status != noErr || numPackets == 0) {
            inBuffer->mAudioDataByteSize = 0;
            AudioQueueEnqueueBuffer(inAQ, inBuffer, 0, nullptr);
            return;
        }
    }
    inBuffer->mAudioDataByteSize = bufferList.mBuffers[0].mDataByteSize;
    AudioQueueEnqueueBuffer(inAQ, inBuffer, 0, nullptr);
}

static void playerFunc(string filepath) {
    PlayerContext ctx = {};
    CFURLRef fileURL = CFURLCreateFromFileSystemRepresentation(nullptr, (const UInt8*)filepath.c_str(), (CFIndex)filepath.size(), false);
    if (ExtAudioFileOpenURL(fileURL, &ctx.audioFile) != noErr) {
        CFRelease(fileURL);
        return;
    }
    CFRelease(fileURL);
    AudioStreamBasicDescription format = {};
    UInt32 size = sizeof(format);
    ExtAudioFileGetProperty(ctx.audioFile, kExtAudioFileProperty_FileDataFormat, &size, &format);
    AudioQueueNewOutput(&format, AQOC, &ctx, nullptr, nullptr, 0, &ctx.queue);

    UInt32 maxPacketSize = 0;
    size = sizeof(maxPacketSize);
    ExtAudioFileGetProperty(ctx.audioFile, kExtAudioFileProperty_ClientMaxPacketSize, &size, &maxPacketSize);
    ctx.maxPacketSize = maxPacketSize;
    UInt32 bufferByteSize = maxPacketSize * ctx.numPacketsToRead;
    ctx.packetDescs = nullptr;
    for (int i = 0; i < 3; ++i) {
        AudioQueueBufferRef buffer;
        AudioQueueAllocateBuffer(ctx.queue, bufferByteSize, &buffer);
        AQOC(&ctx, ctx.queue, buffer);
    }
    AudioQueueStart(ctx.queue, nullptr);
    while (keepPlaying.load())
    this_thread::sleep_for(chrono::milliseconds(100));
    AudioQueueStop(ctx.queue, true);
    AudioQueueDispose(ctx.queue, true);
    ExtAudioFileDispose(ctx.audioFile);
}

void PlayAudio(const string& soundFile) {
    if (keepPlaying.load()) return;
    keepPlaying = true;
    playerThread = thread(playerFunc, "assets/musics/" + soundFile);
}

void StopAudio() {
    if (!keepPlaying.load()) return;
    keepPlaying = false;
    if (playerThread.joinable()) playerThread.join();
}
#endif