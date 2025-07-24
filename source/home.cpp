#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "boot/boot.h"
#include "hnasm/hnasm.h"
#include "porthack.h"
using namespace std;

int main(){
    while(true) {
        string fileName, beginPart;
        cin >> fileName;
        cin >> beginPart;
        HNASM(fileName, beginPart);
    }
    SetConsoleTitleA("Hacknet");
    int chse;
    PlaySound(TEXT("assets/musics/AmbientDroneClipped.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    while(true) {
        system("cls");
        cout << "\n\n\n\n\n"
             << "               �i�i��  �i�i��  �i�i�i�i�i��   �i�i�i�i�i��  �i�i��  �i�i�� �i�i�i��  �i�i�� �i�i�i�i�i�i�i�� �i�i�i�i�i�i�i�i��\n"
             << "               �i�i��  �i�i�� �i�i�ݢ����i�i�� �i�i�ݢ����i�i�� �i�i�� �i�i���� �i�i�i�i�� �i�i�� �i�i�ݢ��������� �㢤���i�i�ݢ�����\n"
             << "               �i�i�i�i�i�i�i�� �i�i�i�i�i�i�i�� �i�i��  �㢤�� �i�i�i�i�i����  �i�i�ݢi�i�ߢi�i�� �i�i�i�i�i��      �i�i��   \n"
             << "               �i�i�ݢ����i�i�� �i�i�ݢ����i�i�� �i�i��  �i�i�� �i�i�ݢ��i�i��  �i�i����i�i�i�i�� �i�i�ݢ�����      �i�i��   \n"
             << "               �i�i��  �i�i�� �i�i��  �i�i�� ��i�i�i�i�i���� �i�i�� ��i�i�� �i�i�� ��i�i�i�� �i�i�i�i�i�i�i��    �i�i��   \n"
             << "               �㢤��  �㢤�� �㢤��  �㢤��  �㢤��������  �㢤��  �㢤�� �㢤��  �㢤���� �㢤������������    �㢤��   \n"
             << "                [C++ Edition by Skiawm91]\n"
             << "\n\n\n\n\n\n\n"
             << "                             1) Play\n"
             << "                             2) Settings\n"
             << "                             3) Quit Hacknet\n"
             << "\n\n\n\n\n\n\n\n";
            cout << "choose: ";
        cin >> chse;
        switch(chse) {
            case 1:
                Boot();
            case 3:
                string yn;
                system("cls");
                while(true) {
                    cout << "Are you sure to quit Hacknet? (y/n)\n";
                    cout << "choose: ";
                    cin >> yn;
                    if (yn=="y") {
                        return 0;
                    } else if (yn=="n") {
                        break;
                    }
                }
        }
    }
    return 0;
}