#include "ASMScript.h"
#include "../hnasm.h"
#include <sstream>
#include <string>
using namespace std;

void HNScript::GOTO(const string& targetFile, const string& content) {
    istringstream iss(content);
    string partName;
    iss >> partName;
    HNASM(targetFile, partName);
}