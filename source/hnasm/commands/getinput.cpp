#define _HAS_STD_BYTE 0
#include "cmds.h"
#include "../../crypto/crypto.h"
#include "../../misc/manageInput.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input;

#ifdef _WIN32
void OTTF2K() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    if (csbi.dwCursorPosition.Y > 0) {
        COORD pos = { 0, csbi.dwCursorPosition.Y - 1 };
        DWORD written;
        FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, pos, &written);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, csbi.dwSize.X, pos, &written);
        SetConsoleCursorPosition(hConsole, pos);
    }
}
#endif

void HNScriptASM::getinput(const string& content) {
    extern string text;
    Input(content);
    input = text;
}

void HNScriptASM::getinputr(const string& content) {
    extern string text;
    #ifdef _WIN32
    OTTF2K();
    #else
    cout << "\033[F\033[2K";
    #endif
    Input(content);
    input = text;
}

void HNScriptASM::getinputpwd(const string& content) {
    HidePwd(content);
}

void HNScriptASM::getinputpwdr(const string& content) {
    HidePwd("\r" + content);
}