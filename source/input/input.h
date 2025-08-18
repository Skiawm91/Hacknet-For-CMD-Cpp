// What TM this shitty code!!!
#pragma once
#include <vector>
#include <atomic>
#include <string>
#include <functional>
#include <thread>
using namespace std;

extern atomic<bool> escDetected; // FUCKIKKIJGNIKCK
extern atomic<bool> runningMouse;
extern atomic<bool> runningKb;
extern atomic<bool> runningPwd;

class ManageInput {
public:
    void keyDisable(const vector<int>& keys);
    void keyDisable(int key);
    void keyEnable();
    bool isBlocking() const;
    using Callback = function<void(const string&)>;
    void kbInput(const string& prompt, Callback cb, int exitCode);
    void stopKbInput();
    void pwdInput(const string &prompt, Callback cb, int exitCode);
    void stopPwdInput();
    void clearButtons();
    void addButton(const string& name, int x, int y, int w, int h);
    void mInput(Callback cb);
    void stopMInput();
    void stopAll() {
        stopKbInput();
        stopPwdInput();
        stopMInput();
    };
private:
    vector<int> blockedKeys;
    atomic<bool> blocking{false};
    void inputLoop();

    struct Button {
        string name;
        int x, y, width, height;
    };
    vector<Button> button;
    thread mInputThread;

    bool pointInButton(int px, int py, const Button& b) const;
    void runListener(Callback cb);

    thread kbInputThread;
    thread pwdInputThread;

#ifdef _WIN32
    void kbWindowsInput(const string& prompt, Callback cb, int exitCode);
    void pwdWindowsInput(const string &prompt, Callback cb, int exitCode);
#else
    void kbMacInput(const string& prompt, Callback cb, int exitCode);
    void pwdMacInput(const string& prompt, Callback cb, int exitCode);
#endif
};
