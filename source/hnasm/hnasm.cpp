#include "hnasm.h"
#include "commands/cmds.h"
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

extern string playerName;

void HNASM(const string& fileName, const string& partName) {
    string scriptPath = "assets/scripts/" + fileName;
    ifstream file(scriptPath);
    string line;
    string command, content;
    bool readcmd = partName.empty();
    while(getline(file, line)) {
        if (line==("BEGIN_" + partName)) {readcmd=true;}
        if (!partName.empty() && line==("END_" + partName)) {break;}
        if (readcmd) {
            command.clear();
            content.clear();
            HNScriptASM hnasm;
            istringstream got(line);
            got >> command;
            getline(got, content);
            if (!content.empty() && content[0] == ' ') {content = content.substr(1);}
            content = regex_replace(content, regex(R"(\$\{PLAYER\})"), playerName); // replace
            if (command=="WAIT") {hnasm.wait(content);}
            else if (command=="CLEAR") {hnasm.clear();}
            else if (command=="PRINT") {hnasm.print(content);}
            else if (command=="PRINTR") {hnasm.printr(content);}
            else if (command=="PRINTWFW") {hnasm.printwfw(content);}
            else if (command=="PLAYAUDIO") {hnasm.playaudio(content);}
            else if (command=="GETINPUT") {hnasm.getinput(content);}
            else if (command=="GETINPUTR") {hnasm.getinputr(content);}
            else if (command=="GETINPUTPWD") {hnasm.getinputpwd(content);}
            else if (command=="GETINPUTPWDR") {hnasm.getinputpwdr(content);}
            else if (command=="GOTO") {hnasm.gotob(fileName, content);}
        }
    }
}