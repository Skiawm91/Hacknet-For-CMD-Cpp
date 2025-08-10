#define _HAS_STD_BYTE 0
#include "misc/manageInput.h"
#include "audio.h"
#include "logUI.h"
#include "hnasm/hnasm.h"
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <unistd.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#endif
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <atomic>
#include "porthack.h"
using namespace std;

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleTitleA("Hacknet For CMD");
    #elif __APPLE__
    char path[PATH_MAX];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        char path_copy[PATH_MAX];
        strncpy(path_copy, path, PATH_MAX);
        path_copy[PATH_MAX - 1] = '\0';
        char* dir = dirname(path_copy);
        chdir(dir);
    }
    cout << "\033]0;Hacknet For CMD\007";
    #endif
    static ManageInput mi;
    int chse;
    extern string input;
    StopAudio();
    PlayAudio("AmbientDroneClipped.wav");
    while(true) {
        chse = 0;
        HNASM("ui.chns", "LOGO");
        HNASM("ui.chns", "HOME");
        mi.clearButtons();
        mi.addButton("PLAY", 2, 9, 20, 3);
        mi.addButton("QUIT", 2, 18, 20, 3);
        mi.mInput([&](const string& buttonName) {
            if (buttonName == "PLAY") {
                chse = 1;
            } else if (buttonName == "QUIT") {
                chse = 4;
            }
        });
        while (runningMouse) {
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        mi.stopAll();
        switch(chse) {
            case 1:
                LogUI();
                break;
            case 4:
                {
                    string yn;
                    #ifdef _WIN32
                    system("cls");
                    #elif __APPLE__
                    system("clear");
                    #endif
                    while(true) {
                        cout << "Are you sure to quit Hacknet? (y/n)\n";
                        cout << "choose: ";
                        cin >> yn;
                        if (yn=="y") {
                            return 0;
                        } else if (yn=="n") {
                            break;
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}