#define _HAS_STD_BYTE 0
#include "crypto.h"
#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
#elif __APPLE__
#include <CommonCrypto/CommonDigest.h>
#endif
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string shatext;

#ifdef _WIN32
void SHA256Encrypt(const string& rawtext) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    BYTE hash[32];
    DWORD hashLen = 32;
    if(!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
    }
    if(!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
        CryptReleaseContext(hProv, 0);
    }
    if(!CryptHashData(hHash, (BYTE*)rawtext.c_str(), rawtext.size(), 0)) {
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
    }
    if(CryptGetHashParam(hHash, HP_HASHVAL, hash, &hashLen, 0)) {
        stringstream ss;
        for(DWORD i = 0; i < hashLen; i++)
            ss << hex << setw(2) << setfill('0') << (int)hash[i];
        shatext = ss.str();
    }
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
}
#elif __APPLE__
void SHA256Encrypt(const string& rawtext) {
    unsigned char hash[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(rawtext.c_str(), (CC_LONG)rawtext.size(), hash);
    stringstream ss;
    for(int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++)
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    shatext = ss.str();
}
#endif