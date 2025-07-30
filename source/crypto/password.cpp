#include "crypto.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
char _getch() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif
using namespace std;

string pwdtext;

void HidePwd(const string& rawtext) {
    pwdtext.clear();
    cout << rawtext;
    while (true) {
        char ch =
        _getch();
        if (ch == '\n' || ch == '\r') {
            cout << endl;
            break;
        } else if (ch == 127 || ch == 8) {
            if (!pwdtext.empty()) {
                pwdtext.pop_back();
                cout << "\b \b";
            }
        } else if (isprint(ch)) {
            pwdtext += ch;
            cout << '*';
        }
    }
}