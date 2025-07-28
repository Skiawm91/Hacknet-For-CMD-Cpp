#define _HAS_STD_BYTE 0
#include "cmds.h"
#include "../../crypto/crypto.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input;

void OTTF2K() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD charsWritten;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    SHORT targetY = csbi.dwCursorPosition.Y - 1;
    if (targetY < 0) return;
    COORD startPos = {0, targetY};
    DWORD width = csbi.dwSize.X;
    FillConsoleOutputCharacter(hConsole, ' ', width, startPos, &charsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, width, startPos, &charsWritten);
    SetConsoleCursorPosition(hConsole, startPos);
}

void GETINPUT(const string& content) {
    cout << content;
    getline(cin, input);
}

void GETINPUTR(const string& content) {
    #ifdef _WIN32
    OTTF2K();
    # else
    cout << "\033[F";
    cout << "\033[2K";
    #endif
    cout << content;
    getline(cin, input);
}

void GETINPUTPWD(const string& content) {
    HidePwd(content);
}

void GETINPUTPWDR(const string& content) {
    HidePwd("\r" + content);
}