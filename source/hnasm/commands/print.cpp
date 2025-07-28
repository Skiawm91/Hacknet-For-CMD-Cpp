#define _HAS_STD_BYTE 0
#include "cmds.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void PRINT(const string& content) {
    if (content.empty()) {
        cout << endl;
    } else {
        cout << content << endl;
    }
}

void PRINTR(const string& content) {
    if (content.empty()) {
        cout << "\r";
    } else {
        cout << "\r" << content;
    }
}

void PRINTWFW(const string& content) {
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
    for (const string& t : text) {
        cout << t;
        Sleep(rand() % 21 + 30);
    }
    cout << endl;
}