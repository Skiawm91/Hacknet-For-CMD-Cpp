#define _HAS_STD_BYTE 0
#include "boot.h"
#include "../hnasm/hnasm.h"
#include "informations/infos.h"
#include "utilities/utils.h"
#include "../noobornonoob.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void Boot() {
    HNASM("ui.chns", "LOGO");
    HNASM("ui.chns", "NULL");
    string block = "=";
    string loading = "";
    for (int i = 1; i <= 100; ++i) {
        if (i % 10 == 0) {loading += block;}
        if (i == 100) {cout << "\rProgress: [" << loading << "] " << i << "% " << flush;}
        else {cout << "\rProgress: [" << loading << ">" "] " << i << "% " << flush;}
        Sleep(rand() % 501);
    }
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    cout << "Loading BIOS..." << endl;
    Sleep(1000);
    OSInfo();
    cout << "BIOS loaded successfully." << endl;
    Sleep(2000);
    CPUInfo();
    cout << "Loading operating system..." << endl;
    Sleep(3000);
    cout << "Operating system loaded successfully." << endl;
    Sleep(1000);
    cout << "Starting services..." << endl;
    cout << "Services initializing..." << endl;
    Network();
    Avast();
    Sleep(3000);
    cout << "Services started." << endl;
    Sleep(2000);
    cout << "\n\n";
    cout << "Booting complete." << endl;
    Sleep(3000);
    Noobornonoob();
    return;
}