#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "boot.h"
using namespace std;

int main(){
    SetConsoleTitleA("Hacknet");
    string chse;
    PlaySound(TEXT("sounds/AmbientDroneClipped.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
             << "                             1) �D����\n"
             << "                             2) ���}Hacknet\n"
             << "\n\n\n\n\n\n\n\n\n";
            cout << "choose: ";
        cin >> chse;
        if (chse=="1") {
            Boot();
        } else if (chse=="2") {
            string yn;
            system("cls");
            while(true) {
                cout << "�T�w�n���}Hacknet��? (y/n)\n";
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