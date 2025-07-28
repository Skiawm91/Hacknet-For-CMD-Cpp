#define _HAS_STD_BYTE 0
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <string>
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
#elif _WIN32
string GetArchitectureName(WORD arch) {
    switch (arch) {
        case PROCESSOR_ARCHITECTURE_INTEL:   return "x86";
        case PROCESSOR_ARCHITECTURE_ARM:     return "arm";
        case PROCESSOR_ARCHITECTURE_IA64:    return "ia64";
        case PROCESSOR_ARCHITECTURE_AMD64:   return "amd64";
        case PROCESSOR_ARCHITECTURE_ARM64:   return "arm64";
        case PROCESSOR_ARCHITECTURE_UNKNOWN: return "unknown";
        default: return "Other (" + to_string(arch) + ")";
    }
}
#endif

void CPUInfo() {
    cout << "Checking CPU..." << endl;
    cout << "CPU diagnostics is running..." << endl;
    #ifdef _WIN32
    SYSTEM_INFO si;
    GetNativeSystemInfo(&si);
    WORD arch = si.wProcessorArchitecture;
    string name = GetArchitectureName(arch);
    #endif
    Sleep(1000);
    #ifdef _WIN32
    cout << "Arch: " << name << endl;
    wcout << L"Cores: " << si.dwNumberOfProcessors << endl;
    #elif __APPLE__
    cout << "Cores: " << getSysctlInt("hw.ncpu") << endl;
    #endif
    Sleep(2000);
}