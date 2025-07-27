#define _HAS_STD_BYTE 0
#include "utils.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void Avast() {
    cout << "Starting Avast 1.0..." << endl;
    cout << "[Avast] Running antivirus scan..." << endl;
    Sleep(1000);
    cout << "[Avast] Scanning for viruses..." << endl;
    Sleep(6000);
    cout << "[Avast] No viruses found." << endl;
    Sleep(1000);
}