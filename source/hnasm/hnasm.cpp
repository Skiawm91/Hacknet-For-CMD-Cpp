#include "hnasm.h"
#include "commands/cmds.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

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
            istringstream got(line);
            got >> command;
            getline(got, content);
            if (!content.empty() && content[0] == ' ') {content = content.substr(1);}
            if (command=="WAIT") {WAIT(content);}
            else if (command=="CLEAR") {CLEAR();}
            else if (command=="PRINT") {PRINT(content);}
            else if (command=="PRINTR") {PRINTR(content);}
            else if (command=="PRINTWFW") {PRINTWFW(content);}
            else if (command=="PLAYAUDIO") {PLAYAUDIO(content);}
            else if (command=="GETINPUT") {GETINPUT(content);}
            else if (command=="GETINPUTR") {GETINPUTR(content);}
            else if (command=="GETINPUTPWD") {GETINPUTPWD(content);}
            else if (command=="GETINPUTPWDR") {GETINPUTPWDR(content);}
        }
    }
}