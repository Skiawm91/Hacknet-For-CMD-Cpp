#include "tutorial.h"
#include "input/input.h"
#include "hnasm/hnasm.h"
#include "audio.h"
#include "cmd.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include <atomic>
using namespace std;

void Pause() {
    int chse;
    while (true) {
        if (escDetected) {
            cout << "1) Continue, 2) Quit, > ";
            cin >> chse;
            if (chse = 1) {break;} else if (chse = 2) {return;}
        }
        this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Tutorial() {
    thread(Pause).detach();
    ManageInput mi;
    extern string input;
    int chse = 0;
    string cmd;
    mi.keyDisable(13);
    HNASM("tutorial/failsafe.chns", "FAILSAFE");
    HNASM("tutorial/tutorial.chns", "CHANGESONG");
    HNASM("tutorial/tutorial.chns", "TUTORIAL1");
    while(true) {
        mi.keyEnable();
        HNASM("tutorial/tutorial.chns", "TR1CHSE");
        try {chse = stoi(input);} catch (const invalid_argument& e) {chse = 0;}
        if (chse == 1) {
            mi.keyDisable(13);
            HNASM("tutorial/tutorial.chns", "TUTORIAL2");
            while(true) {
                mi.keyEnable();
                HNASM("tutorial/tutorial.chns", "TR2CHSE");
                try {chse = stoi(input);} catch (const invalid_argument& e) {chse = 0;}
                if (chse == 1) {
                    mi.keyDisable(13);
                    HNASM("tutorial/story.chns", "INITIAL");
                    HNASM("tutorial/story.chns", "MYSVR");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "MYSVRCMD");
                        cmd = input;
                        if (cmd=="mysvr") {
                            mi.keyDisable(13);
                            HNASM("tutorial/story.chns", "CNTMYSVR");
                            break;
                        } else {
                            mi.keyDisable(13);
                            HNASM("tutorial/story.chns", "CMDINV");
                        }
                    }
                    HNASM("tutorial/story.chns", "EXPLIFERR");
                    HNASM("tutorial/story.chns", "SCAN1");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "SCAN1CMD");
                        cmd = input;
                        if (cmd=="scan") {
                            mi.keyDisable(13);
                            HNASM("tutorial/scan.chns", "1");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "CNT1");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "CNT1CMD");
                        cmd = input;
                        if (cmd=="cnt 1") {
                            mi.keyDisable(13);
                            HNASM("tutorial/story.chns", "CNTJOHNSVR");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "GETINFO");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "GETINFOCMD");
                        cmd = input;
                        if (cmd=="info") {
                            mi.keyDisable(13);
                            HNASM("tutorial/info.chns", "JOHNSVR");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "GETHACKED");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "GETHACKEDCMD");
                        cmd = input;
                        if (cmd=="mysvr") {
                            mi.keyDisable(13);
                            HNASM("tutorial/story.chns", "CNTMYSVR");
                            break;
                        }
                    }
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "BACKMYSVRCMD");
                        cmd = input;
                        if (cmd=="ls") {
                            mi.keyDisable(13);
                            HNASM("tutorial/cd.chns", "LS");
                        } else if (cmd=="cd log") {
                            mi.keyDisable(13);
                            HNASM("tutorial/cd.chns", "LOG");
                            break;
                        } else if (cmd=="cd bin") {
                            mi.keyDisable(13);
                            HNASM("tutorial/cd.chns", "BIN");
                        } else if (cmd=="cd sys") {
                            mi.keyDisable(13);
                            HNASM("tutorial/cd.chns", "SYS");
                        }
                    }
                    HNASM("tutorial/story.chns", "SCAN2");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "SCAN2CMD");
                        cmd = input;
                        if (cmd=="scan") {
                            mi.keyDisable(13);
                            HNASM("tutorial/scan.chns", "2");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "CNT3");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "CNT3CMD");
                        cmd = input;
                        if (cmd=="cnt 3") {
                            mi.keyDisable(13);
                            HNASM("tutorial/story.chns", "CNTHACKER");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "PRTHACK");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "PRTHACKCMD");
                        cmd = input;
                        if (cmd=="porthack") {
                            mi.keyDisable(13);
                            HNASM("tutorial/porthack.chns", "RUN");
                            thread(HNASM, "tutorial/porthack.chns", "HACK").detach();
                            HNASM("tutorial/story.chns", "PRTHACK2");
                            HNASM("tutorial/porthack.chns", "DONE");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "RM");
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "RMCMD");
                        cmd = input;
                        if (cmd=="rm *") {
                            mi.keyDisable(13);
                            HNASM("tutorial/rm.chns", "RM*");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "ENDING");
                    HNASM("tutorial/story.chns", "END");
                    string homes;
                    while(true) {
                        mi.keyEnable();
                        HNASM("tutorial/story.chns", "ENDCHOOSE");
                        transform(input.begin(), input.end(), input.begin(), ::tolower);
                        homes = input;
                        if (homes=="home") {
                            StopAudio();
                            PlayAudio("AmbientDroneClipped.wav");
                            break;
                        } else if (homes=="exit"){
                            exit(1);
                        }
                    }
                    return;
                } else if (chse == 2) {
                    Cmd();
                    break;
                }
            }
        }
    }
}