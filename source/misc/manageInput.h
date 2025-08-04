#pragma once
#include <vector>
#include <atomic>
#include <string>
using namespace std;
#ifndef KEYBLOCKER_H
#define KEYBLOCKER_H
class KeyBlocker {
public:
    void disable(const vector<int>& keys);
    void disable(int key);
    void enable();
    bool isBlocking() const;
private:
    vector<int> blockedKeys;
    atomic<bool> blocking{false};
    void inputLoop();
};
#endif
void HidePwd(const string& prompt);
void Input(const string& prompt);