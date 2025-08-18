#include <iostream>
// #include <string>
#include "cmd.h"
using namespace std;

void Cmd() {
    system("cls");
    cout << "==================================\n"
         << endl
         << "CMD User Interface Coming Soon!\n"
         << endl
         << "==================================";
    #ifdef _WIN32
    system("pause > nul");
    #else
    system("read -p");
    #endif
    // string command;
    // cout << "@122.21.33.118> ";
    // getline(cin, command); 
}