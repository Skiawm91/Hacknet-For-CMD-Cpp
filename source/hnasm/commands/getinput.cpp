#include "cmds.h"
#include "../../crypto/crypto.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input;

void GETINPUT(const string& content) {
    cout << content;
    getline(cin, input);
}

void GETINPUTR(const string& content) {
    cout << "\033[F";
    cout << "\033[2K";
    cout << content;
    getline(cin, input);
}

void GETINPUTPWD(const string& content) {
    readPassword(content);
}

void GETINPUTPWDR(const string& content) {
    readPassword("\r" + content);
}