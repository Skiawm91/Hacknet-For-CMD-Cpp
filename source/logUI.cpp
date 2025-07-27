#define _HAS_STD_BYTE 0
#include "logUI.h"
#include "hnasm/hnasm.h"
#include "crypto/crypto.h"
#include "boot/boot.h"
#include "cmd.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <fstream>
#include <filesystem>
#include <sstream>
#include <algorithm>
using namespace std;

string name;

void LogUI() {
    extern string input;
    extern string shatext;
    int chse = 0;
    string shapwd, tgshapwd;
    while(true) {
        HNASM("ui.chns", "LOGO");
        HNASM("ui.chns", "USER");
        try {chse = stoi(input);} catch (const invalid_argument) {chse = 0;}
        switch(chse) {
            case 1:
                HNASM("logUI/login.chns", "NAME");
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                name = input;
                {
                    ifstream file("config/" + name + "/pw.hnud");
                    if (!file) {HNASM("logUI/login.chns", "ERROR");}
                    else {
                        string line;
                        getline(file, line);
                        istringstream iss(line);
                        iss >> tgshapwd;
                        HNASM("logUI/login.chns", "PASSWD");
                        SHA256Encrypt(input);
                        shapwd = shatext;
                        if (shapwd == tgshapwd) {
                            Boot();
                            return;
                        } else {
                            HNASM("logUI/login.chns", "ERROR");
                        }
                    }
                }
                break;
            case 2:
                HNASM("logUI/register.chns", "NAME");
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                name = input;
                {
                    while(true) {
                        if (filesystem::exists("config/" + name) && filesystem::is_directory("config" + name)) {
                            HNASM("logUI/register.chns", "USEDNAME");
                        } else {
                            if (!filesystem::exists("config")) {
                                filesystem::create_directory("config");
                            }
                            filesystem::create_directory("config/" + name);
                            string pwd[2];
                            HNASM("logUI/register.chns", "PASSWD");
                            pwd[0] = input;
                            HNASM("logUI/register.chns", "CONFIRM");
                            pwd[1] = input;
                            if (pwd[0] == pwd[1]) {
                                SHA256Encrypt(pwd[1]);
                                shapwd = shatext;
                                ofstream file("config/" + name + "/pw.hnud");
                                if (file.is_open()) {
                                    file << shapwd << endl;
                                    file.close();
                                }
                                HNASM("logUI/register.chns", "SUCCESS");
                                break;
                            } else {
                                HNASM("logUI/register.chns", "INVCONFIRM");
                            }
                        }
                    }
                }
                break;
            case 3:
                Boot();
                return;
            case 4:
                return;
            default:
                break;
        }
    }
}