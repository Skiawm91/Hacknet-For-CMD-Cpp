#define _HAS_STD_BYTE 0
#include "input.h"
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <CoreGraphics/CoreGraphics.h>
#include <unistd.h>
#endif
#include <iostream>
#include <atomic>

std::atomic<bool> runningMouse;

void ManageInput::clearButtons() {
    button.clear();
}

void ManageInput::addButton(const string& name, int x, int y, int w, int h) {
    button.push_back({name, x, y, w, h});
}

void ManageInput::mInput(Callback cb) {
    ManageInput::stopMInput();
    runningMouse = true;
    mInputThread = std::thread(&ManageInput::runListener, this, cb);
}

bool ManageInput::pointInButton(int px, int py, const Button& b) const {
    return px >= b.x && px < b.x + b.width &&
           py >= b.y && py < b.y + b.height;
}

void ManageInput::runListener(Callback cb) {
#ifdef _WIN32
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prevMode;
    GetConsoleMode(hIn, &prevMode);
    SetConsoleMode(hIn, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
    INPUT_RECORD ir;
    DWORD readCount;
    while (runningMouse) {
        if (ReadConsoleInput(hIn, &ir, 1, &readCount) && readCount == 1) {
            if (ir.EventType == MOUSE_EVENT) {
                auto& me = ir.Event.MouseEvent;
                if (me.dwEventFlags == 0 && (me.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
                    int consoleX = me.dwMousePosition.X;
                    int consoleY = me.dwMousePosition.Y;
                    for (auto& b : button) {
                        if (pointInButton(consoleX, consoleY, b)) {
                            if (cb) cb(b.name);
                            runningMouse = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    SetConsoleMode(hIn, prevMode);
#elif __APPLE__
    while (runningMouse) {
        CGEventRef event = CGEventCreate(NULL);
        CGPoint loc = CGEventGetLocation(event);
        CGEventType eventType = CGEventGetType(event);
        CFRelease(event);
        if (eventType == kCGEventLeftMouseDown) {
            for (auto& b : button) {
                if (pointInButton(loc.x, loc.y, b)) {
                    std::cout << "Button pressed: " << b.name << "\n";
                    if (cb) cb(b.name);
                    runningMouse = false;
                    usleep(200000);
                    break;
                }
            }
        }
        usleep(10000);
    }
#endif
}

void ManageInput::stopMInput() {
    if (!runningMouse) return;
    runningMouse = false;
    if (mInputThread.joinable())
        mInputThread.join();
}
