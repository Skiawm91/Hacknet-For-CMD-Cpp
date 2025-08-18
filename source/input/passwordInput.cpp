// By new GPT-5
#define _HAS_STD_BYTE 0
#include "input.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <iostream>
#include <atomic>

atomic<bool> runningPwd;
// escDetected set in keyboardInput.cpp

void ManageInput::pwdInput(const string& prompt, Callback cb, int exitCode) {
    ManageInput::stopPwdInput();
    runningPwd = true;
#ifdef _WIN32
    pwdInputThread = thread(&ManageInput::kbWindowsInput, this, prompt, cb, exitCode);
#else
    pwdInputThread = thread(&ManageInput::kbMacInput, this, prompt, cb, exitCode);
#endif
}

#ifdef _WIN32
void ManageInput::pwdWindowsInput(const string& prompt, Callback cb, int exitCode) {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    cout << prompt << flush;
    string buffer;

    while (runningPwd) {
        escDetected = false;
        INPUT_RECORD record;
        DWORD eventsRead = 0;
        if (ReadConsoleInput(hStdin, &record, 1, &eventsRead) && eventsRead == 1) {
            if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
                char ch = record.Event.KeyEvent.uChar.AsciiChar;
                if (ch == exitCode) {
                    escDetected = false;
                    break;
                }
                if (ch == '\r') {
                    cout << endl;
                    cb(buffer);
                    buffer.clear();
                    runningPwd = false;
                    break;
                } else if (ch == '\b') {
                    if (!buffer.empty()) {
                        buffer.pop_back();
                        cout << "\b \b" << flush;
                    }
                } else if (ch >= 32) {
                    buffer.push_back(ch);
                    cout << "*" << flush;  // 改這裡，輸出*
                }
            }
        }
    }

    SetConsoleMode(hStdin, mode);
    runningPwd = false;
}
#else
void ManageInput::pwdMacInput(const string& prompt, Callback cb, int exitCode) {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    cout << prompt << flush;
    string buffer;
    while (runningPwd) {
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
            runningPwd = false;
            break;
        } else if (ch == 127 || ch == '\b') {
            if (!buffer.empty()) {
                buffer.pop_back();
                cout << "\b \b" << flush;
            }
        } else if (ch >= 32) {
            buffer.push_back(ch);
            cout << "*" << flush;  // 改這裡，輸出*
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    runningPwd = false;
}
#endif

void ManageInput::stopPwdInput() {
    if (!runningPwd) return;
    runningPwd = false;
    if (pwdInputThread.joinable()) pwdInputThread.join();
}