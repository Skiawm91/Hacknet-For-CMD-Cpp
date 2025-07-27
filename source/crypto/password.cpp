#include <iostream>
#include <string>

#ifdef _WIN32
#include <conio.h>  // Windows 用於 _getch()
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);             // 取得當前終端設定
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);           // 關閉緩衝區與回顯
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);    // 套用新設定
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);    // 還原設定
    return ch;
}
#endif

std::string pwdtext;  // 全域變數，儲存輸入的密碼

void readPassword(const std::string& rawtext) {
    pwdtext.clear();  // 清空舊密碼
    std::cout << rawtext;  // 顯示提示文字

    while (true) {
        char ch =
#ifdef _WIN32
            _getch();
#else
            getch();
#endif
        if (ch == '\n' || ch == '\r') {
            std::cout << std::endl;
            break;
        } else if (ch == 127 || ch == 8) {  // Backspace
            if (!pwdtext.empty()) {
                pwdtext.pop_back();
                std::cout << "\b \b";
            }
        } else if (isprint(ch)) {
            pwdtext += ch;
            std::cout << '*';
        }
    }
}