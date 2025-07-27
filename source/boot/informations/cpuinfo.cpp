#define _HAS_STD_BYTE 0
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#ifdef __APPLE__
#include <sys/sysctl.h>
#endif
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

#ifdef __APPLE__
inline string getSysctlString(const char* name) {
    size_t size = 0;
    sysctlbyname(name, nullptr, &size, nullptr, 0);
    char* value = new char[size];
    sysctlbyname(name, value, &size, nullptr, 0);
    string result(value);
    delete[] value;
    return result;
}

inline int getSysctlInt(const char* name) {
    int value = 0;
    size_t size = sizeof(value);
    sysctlbyname(name, &value, &size, nullptr, 0);
    return value;
}
#endif

void CPUInfo() {
    cout << "Checking CPU..." << endl;
    cout << "CPU diagnostics is running..." << endl;
    #ifdef _WIN32
    SYSTEM_INFO si;
    GetNativeSystemInfo(&si);
    #endif
    Sleep(1000);
    #ifdef _WIN32
    wcout << L"Arch: " << si.wProcessorArchitecture << endl;
    wcout << L"Cores: " << si.dwNumberOfProcessors << endl;
    #elif __APPLE__
    cout << "Cores: " << getSysctlInt("hw.ncpu") << endl;
    #endif
    Sleep(2000);
}