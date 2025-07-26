#include "cmds.h"
#include "../../audio.h"
#include <string>
#ifdef _WIN32
#include <windows.h>
#undef PlaySound
#endif
#include <sstream>
using namespace std;

void PLAYAUDIO(const string& content) {
    string arg1;
    istringstream args(content);
    args >> arg1;
    StopAudio();
    PlayAudio(arg1);
}