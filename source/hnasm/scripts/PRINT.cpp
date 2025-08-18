#define _HAS_STD_BYTE 0
#include "ASMScript.h"
#include "../../misc/manageInput.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void HNScript::PRINT(const string& content) {
    if (content.empty()) {
        cout << endl;
    } else {
        cout << content << endl;
    }
}

void HNScript::PRINTR(const string& content) {
    if (content.empty()) {
        cout << "\r";
    } else {
        cout << "\r" << content;
    }
}

void HNScript::PRINTWFW(const string& content) {
    vector<string> text;
    istringstream iss(content);
    string word;
    while (iss >> word) {
        if (word == "␣") {
            text.push_back(" ");
        } else {
            text.push_back(word);
        }
    }
    srand((unsigned int)time(nullptr));
    for (const string& t : text) {
        cout << t << flush;
        Sleep(rand() % 21 + 30);
    }
    cout << endl;
}