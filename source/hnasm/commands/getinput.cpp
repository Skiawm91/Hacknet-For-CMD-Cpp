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
#include <future>
using namespace std;

string input;
ManageInput mi;

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
    input.clear();
    mi.kbInput(content, [](const string& text) {
        input = text;
    }, 27);
}

void HNScriptASM::getinputr(const string& content) {
    input.clear();
    #ifdef _WIN32
    OTTF2K();
    #else
    cout << "\033[F\033[2K";
    #endif
    mi.kbInput(content, [](const string& text){
        input = text;
    }, 27);
}

void HNScriptASM::getinputpwd(const string& content) {
    input.clear();
    mi.pwdInput(content, [](const string& pwdText) {
        input = pwdText;
    }, 27);
    mi.stopPwdInput();
}

void HNScriptASM::getinputpwdr(const string& content) {
    input.clear();
    #ifdef _WIN32
    OTTF2K();
    #else
    cout << "\033[F\033[2K";
    #endif
    mi.pwdInput(("\r" + content), [](const string& pwdText) {
        input = pwdText;
    }, 27);
}