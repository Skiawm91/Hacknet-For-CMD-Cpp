#include "ASMScript.h"

void HNScript::CLEAR(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}