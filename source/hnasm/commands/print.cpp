#include "cmds.h"
#include <iostream>
using namespace std;

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