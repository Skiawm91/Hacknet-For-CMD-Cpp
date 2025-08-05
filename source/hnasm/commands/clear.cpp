#include "cmds.h"

void HNScriptASM::clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}