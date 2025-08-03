// Disable keys by GPT
#define _HAS_STD_BYTE 0
#include "manageInput.h"
#include <thread>
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#endif

void KeyBlocker::disable(const std::vector<int>& keys) {
    blockedKeys = keys;
    blocking = true;
    std::thread(&KeyBlocker::inputLoop, this).detach();
}

void KeyBlocker::disable(int key) {
    disable(std::vector<int>{key});
}

void KeyBlocker::enable() {
    blocking = false;
}

bool KeyBlocker::isBlocking() const {
    return blocking;
}

#ifdef __APPLE__ // macOS or Unix-like
// 設定終端為非 canonical mode（即時輸入、不等待 Enter）
void setNonBlockingInput(bool enable) {
    static struct termios oldt, newt;
    static bool configured = false;

    if (enable && !configured) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // 關掉輸入緩衝與輸出
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // 非阻塞
        configured = true;
    } else if (!enable && configured) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, 0);
        configured = false;
    }
}
#endif

void KeyBlocker::inputLoop() {
#ifdef _WIN32
    while (blocking) {
        if (_kbhit()) {
            int key = _getch();
            for (int blocked : blockedKeys) {
                if (key == blocked) {
                    // 阻止輸出
                    break;
                }
            }
        }
        Sleep(10);
    }
#else
    setNonBlockingInput(true);
    while (blocking) {
        fd_set set;
        struct timeval timeout = {0, 10000}; // 10ms
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);

        if (select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout) > 0) {
            char ch;
            if (read(STDIN_FILENO, &ch, 1) > 0) {
                for (int blocked : blockedKeys) {
                    if ((int)ch == blocked) {
                        // 吃掉，不輸出
                        break;
                    }
                }
            }
        }
    }
    setNonBlockingInput(false);
#endif
}