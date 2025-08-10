#define _HAS_STD_BYTE 0
#include "manageInput.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include <iostream>
#include <atomic>

atomic<bool> runningKb;
atomic<bool> escDetected(false);

void ManageInput::kbInput(const string& prompt, Callback cb, int exitCode) {
    ManageInput::stopKbInput();
    runningKb = true;
#ifdef _WIN32
    kbInputThread = thread(&ManageInput::kbWindowsInput, this, prompt, cb, exitCode);
#else
    kbInputThread = thread(&ManageInput::kbMacInput, this, prompt, cb, exitCode);
#endif
}

#ifdef _WIN32
void ManageInput::kbWindowsInput(const string& prompt, Callback cb, int exitCode) {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    cout << prompt << flush;
    string buffer;

    while (runningKb) {
        escDetected = false;
        INPUT_RECORD record;
        DWORD eventsRead = 0;
        if (ReadConsoleInput(hStdin, &record, 1, &eventsRead) && eventsRead == 1) {
            if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
                char ch = record.Event.KeyEvent.uChar.AsciiChar;
                if (ch == exitCode) {
                    escDetected = true;
                    break;
                }
                if (ch == '\r') {
                    cout << endl;
                    cb(buffer);
                    buffer.clear();
                    break;
                } else if (ch == '\b') {
                    if (!buffer.empty()) {
                        buffer.pop_back();
                        cout << "\b \b" << flush;
                    }
                } else if (ch >= 32) {
                    buffer.push_back(ch);
                    cout << ch << flush;
                }
            }
        }
    }

    SetConsoleMode(hStdin, mode);
    runningKb = false;
}
#else
void ManageInput::kbMacInput(const string& prompt, Callback cb, int exitCode) {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    cout << prompt << flush;
    string buffer;
    while (runningKb) {
        escDetected = false;
        char ch = 0;
        ssize_t r = read(STDIN_FILENO, &ch, 1);
        if (r <= 0) continue;
        if (ch == exitCode) {
            escDetected = true;
            break;
        }
        if (ch == '\n' || ch == '\r') {
            cout << endl;
            cb(buffer);
            buffer.clear();
            break;
        } else if (ch == 127 || ch == '\b') {
            if (!buffer.empty()) {
                buffer.pop_back();
                cout << "\b \b" << flush;
            }
        } else if (ch >= 32) {
            buffer.push_back(ch);
            cout << ch << flush;
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    runningKb = false;
}
#endif

void ManageInput::stopKbInput() {
    if (!runningKb) return;
    runningKb = false;
    if (kbInputThread.joinable()) kbInputThread.join();
}