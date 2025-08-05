#pragma once
#undef goto
#include <string>
using namespace std;
class HNScriptASM {
    public:
        void clear();
        void wait(const string& content);
        void print(const string& content);
        void printr(const string& content);
        void printwfw(const string& content);
        void playaudio(const string& content);
        void getinput(const string& content);
        void getinputr(const string& content);
        void getinputpwd(const string& content);
        void getinputpwdr(const string& content);
        void gotob(const string& targetFile, const string& content); // FUCKING GOTO
};