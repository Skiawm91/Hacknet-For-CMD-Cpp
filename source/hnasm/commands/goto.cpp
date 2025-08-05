#include "cmds.h"
#include "../hnasm.h"
#include <sstream>
#include <string>
using namespace std;

void HNScriptASM::gotob(const string& targetFile, const string& content) {
    istringstream iss(content);
    string partName;
    iss >> partName;
    HNASM(targetFile, partName);
}