#define _HAS_STD_BYTE 0
#include "infos.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#ifdef __APPLE__
#include <sys/sysctl.h>
#endif
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

#ifdef _WIN32
// Pre get "OS Name"/"OS Verion" by ChatGPT
wstring getRegValue(const wchar_t* keyName) {
    HKEY hKey;
    wchar_t buf[256] = {0};
    DWORD size = sizeof(buf);
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                      L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                      0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return 0;
    }
    if (RegQueryValueExW(hKey, keyName, nullptr, nullptr, (LPBYTE)buf, &size) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return 0;
    }
    RegCloseKey(hKey);
    return buf;
}

DWORD GetRegDWORDValue(const wchar_t* name) {
    HKEY hKey;
    DWORD data = 0;
    DWORD size = sizeof(data);
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                      L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                      0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return 0;
    if (RegQueryValueExW(hKey, name, nullptr, nullptr, (LPBYTE)&data, &size) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return 0;
    }
    RegCloseKey(hKey);
    return data;
}
#elif __APPLE__
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

void OSInfo() {
    cout << "Getting system information..." << endl;
    #ifdef _WIN32
    for (int i = 1; i <= 5; ++i) {
        system("systeminfo > nul");
    }
    if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 22000) {
        wcout << L"OS Name: Windows 11" << endl;
    } else if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 10240 && _wtoi(getRegValue(L"CurrentBuildNumber").c_str()) < 22000) {
        wcout << L"OS Name: Windows 10" << endl;
    } else if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 9600 && _wtoi(getRegValue(L"CurrentBuildNumber").c_str()) < 10240) {
        wcout << L"OS Name: Windows 8.1" << endl;
    } else {
        OSVERSIONINFOEXW osvi = { sizeof(osvi) };
        GetVersionExW((OSVERSIONINFOW*)&osvi);
        wcout << L"OS Version: " << osvi.dwMajorVersion << L"." << osvi.dwMinorVersion << endl;
    }
    wcout << L"OS Version: " << GetRegDWORDValue(L"CurrentMajorVersionNumber") << "." << GetRegDWORDValue(L"CurrentMinorVersionNumber") << endl;
    #elif __APPLE__
    cout << "OS Name: Mac OS X" << endl;
    cout << "OS Version: " << getSysctlString("kern.osproductversion") << endl;
    cout << "OS Arch: " << getSysctlString("hw.machine") << endl;
    #endif
}