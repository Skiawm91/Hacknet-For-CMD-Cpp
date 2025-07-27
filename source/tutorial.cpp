#include "tutorial.h"
#include "hnasm/hnasm.h"
#include "audio.h"
#include "cmd.h"
#include <string>
#include <algorithm>
using namespace std;

#ifndef _WIN32
void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void Tutorial() {
    extern string input;
    string yn;
    string cmd;
    HNASM("tutorial/failsafe.chns", "FAILSAFE");
    HNASM("tutorial/tutorial.chns", "CHANGESONG");
    while(true) {
        HNASM("tutorial/tutorial.chns", "TUTORIAL1");
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        yn = input;
        if (yn=="y") {
            while(true) {
                HNASM("tutorial/tutorial.chns", "TUTORIAL2");
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                yn = input;
                if (yn=="y") {
                    HNASM("tutorial/story.chns", "INITIAL");
                    HNASM("tutorial/story.chns", "MYSVR");
                    while(true) {
                        HNASM("tutorial/story.chns", "MYSVRCMD");
                        cmd = input;
                        if (cmd=="mysvr") {
                            HNASM("tutorial/story.chns", "CNTMYSVR");
                            break;
                        } else {
                            HNASM("tutorial/story.chns", "CMDINV");
                        }
                    }
                    HNASM("tutorial/story.chns", "EXPLIFERR");
                    HNASM("tutorial/story.chns", "SCAN1");
                    while(true) {
                        HNASM("tutorial/story.chns", "SCAN1CMD");
                        cmd = input;
                        if (cmd=="scan") {
                            HNASM("tutorial/scan.chns", "1");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "CNT1");
                    while(true) {
                        HNASM("tutorial/story.chns", "CNT1CMD");
                        cmd = input;
                        if (cmd=="cnt 1") {
                            HNASM("tutorial/story.chns", "CNTJOHNSVR");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "GETINFO");
                    while(true) {
                        HNASM("tutorial/story.chns", "GETINFOCMD");
                        cmd = input;
                        if (cmd=="info") {
                            HNASM("tutorial/info.chns", "JOHNSVR");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "GETHACKED");
                    while(true) {
                        HNASM("tutorial/story.chns", "GETHACKEDCMD");
                        cmd = input;
                        if (cmd=="mysvr") {
                            HNASM("tutorial/story.chns", "CNTMYSVR");
                            break;
                        }
                    }
                    while(true) {
                        HNASM("tutorial/story.chns", "BACKMYSVRCMD");
                        cmd = input;
                        if (cmd=="ls") {
                            HNASM("tutorial/cd.chns", "LS");
                        } else if (cmd=="cd log") {
                            HNASM("tutorial/cd.chns", "LOG");
                            break;
                        } else if (cmd=="cd bin") {
                            HNASM("tutorial/cd.chns", "BIN");
                        } else if (cmd=="cd sys") {
                            HNASM("tutorial/cd.chns", "SYS");
                        }
                    }
                    HNASM("tutorial/story.chns", "SCAN2");
                    while(true) {
                        HNASM("tutorial/story.chns", "SCAN2CMD");
                        cmd = input;
                        if (cmd=="scan") {
                            HNASM("tutorial/scan.chns", "2");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "CNT3");
                    while(true) {
                        HNASM("tutorial/story.chns", "CNT3CMD");
                        cmd = input;
                        if (cmd=="cnt 3") {
                            HNASM("tutorial/story.chns", "CNTHACKER");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "PRTHACK");
                    while(true) {
                        HNASM("tutorial/story.chns", "PRTHACKCMD");
                        cmd = input;
                        if (cmd=="porthack") {
                            HNASM("tutorial/porthack.chns", "RUN");
                            HNASM("tutorial/porthack.chns", "HACK");
                            HNASM("tutorial/story.chns", "PRTHACK2");
                            HNASM("tutorial/porthack.chns", "DONE");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "RM");
                    while(true) {
                        HNASM("tutorial/story.chns", "RMCMD");
                        cmd = input;
                        if (cmd=="rm *") {
                            HNASM("tutorial/rm.chns", "RM*");
                            break;
                        }
                    }
                    HNASM("tutorial/story.chns", "ENDING");
                    HNASM("tutorial/story.chns", "END");
                    string homes;
                    while(true) {
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
                } else if (yn=="n") {
                    Cmd();
                    break;
                }
            }
        } else if (yn=="skip") {
            Cmd();
            break;
        }
    }
}