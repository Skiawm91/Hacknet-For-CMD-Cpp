#include <windows.h>
#include <iostream>
#include <string>
#include <limits>
#include "tutorial.h"
#include "cmd.h"
#include "porthack.h"
using namespace std;

void Tutorial() {
    SetConsoleTitleA("Hacknet Tutorial");
    string yn;
    string cmd;
    system("cls");
    Sleep(2000);
    cout << "-----���b��l��FailSafe�Ҧ�-----\n" << endl;
    Sleep(3000);
    cout << "�o��Ƥ���l...��ڷQ�������٭n����...\n";
    Sleep(3000);
    cout << "��F �ѤF�ۧڤ��� �ڪ��W�l�sGigaByte ��A�ݨ�o�h�T���� �N��ڤw�g���F...\n" << endl;
    Sleep(3000);
    cout << "...";
    Sleep(3000);
    system("cls");
    PlaySound(NULL, NULL, 0);
    PlaySound(TEXT("sounds\\tutorial.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Sleep(1000);
    while(true) {
        system("cls");
        cout << "Tutorial Mode\n"
              << endl
              << "�A�{�b�B��M�I����!\n"
              << "�Хγ̧֪��t�ק����о�!\n"
              << "�p�G�ǳƦn�F�п�Jy �n���L�оǽп�Jskip\n"
              << endl;
        cout << "choose: ";
        cin >> yn;
        if (yn=="y") {
            while(true) {
                system("cls");
                cout << "Tutorial Mode\n"
                      << endl
                      << "�J�I�L�H�׺ݸ˸m�N�|�H�Ϥ��إ���D�k��358��\n"
                      << "�q�{�b�}�l ���ۤv���欰�t�d�a!\n"
                      << "�p�G�ǳƦn�F�п�Jy�~��\n"
                      << endl;
                cout << "choose: ";
                cin >> yn;
                if (yn=="y") {
                    system("cls");
                    cout << "���b�PD3f4ult's PC�إߦw���s�u..." << endl;
                    Sleep(2000);
                    cout << "�w�s��" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �A�n �ڬOBit���U�� �{�b�и�̧ڤ@�B�@�B�ާ@ �ާ@���A�N�Ƿ|�F...�T�����@" << endl;
                    Sleep(1000);
                    cout << "[D3f4ult] ���� �b�U����Jmysvr" << endl;
                    while(true) {
                        cout << "[root] ~$ ";
                        getline(cin, cmd);
                        if (cmd=="mysvr") {
                            cout << "���b�s����ڪ����A��..." << endl;
                            Sleep(2000);
                            cout << "����" << endl;
                            cout << "\n";
                            break;
                        } else {
                            cout << "���O���~!" << endl;
                            cout << "\n";
                            cout << "[D3f4ult] �p�G�J��o�ر��p �A�ݭn�A��J�@�����O �Ϊ̿�Jhelp�M�D���U" << endl;
                        }
                    }
                    cout << "[D3f4ult] �ݨ�o�ӥN��s�u���\" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �p�G�ݨ�o�ӥN��s�u����" << endl;
                    cout << "\n";
                    cout << "���b�s����ڪ����A��..." << endl;
                    cout << "�w���h�s�u!" << endl;
                    cout << "\n";
                    Sleep(2000);
                    cout << "[D3f4ult] �ݭn���s�s�u�@��" << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] ���O�j���������p���O�s�u���\" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] ���U�ӿ�Jscan" << endl;
                    while(true) {
                        cout << "[myserver] ~$ ";
                        getline(cin, cmd);
                        if (cmd=="scan") {
                            cout << "�H�U�O�ثe�b�Ϻ��W�䪺�쪺�q��or���A��\n"
                                 << "1. Jhon's Server (192.168.45.2)\n"
                                 << "2. Hoyiqiang's NAS (192.168.31.4)\n"
                                 << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] ���ۿ�Jcnt 1 cnt�N�O�s�u 1�N�O�q�����s��" << endl;
                    while(true) {
                        cout << "[myserver] $~ ";
                        getline(cin, cmd);
                        if (cmd=="cnt 1") {
                            cout << "���b�s����Jhon's Server..." << endl;
                            cout << "����" << endl;
                            Sleep(1000);
                            cout << "\n";
                            break;
                        }
                    }
                    cout << "[D3f4ult] ���̿�Jinfo" << endl;
                    while(true) {
                        cout << "[John's Server] $~ ";
                        getline(cin, cmd);
                        if (cmd=="info") {
                            cout << endl
                                << "Server Info\n"
                                << endl
                                << "server IP:192.168.45.2\n";
                            Sleep(2000);
                            cout << "server files:(Unknown)" << endl;
                            Sleep(2000);
                            cout << "ping:103ms" << endl;
                            Sleep(2000);
                            break;
                        }
                    }
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("sounds\\tutorial2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    cout << endl
                         << "\"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
                         << "\"  |_ _| \\| |/ __/ _ \\|  \\/  |_ _| \\| |/ __|  / __/ _ \\| \\| | \\| | __/ __|_   _|_ _/ _ \\| \\| |\n"
                         << "\"   | || .` | (_| (_) | |\\/| || || .` | (_ | | (_| (_) | .` | .` | _| (__  | |  | | (_) | .` |\n"
                         << "\"  |___|_|\\_|\\___\\___/|_|  |_|___|_|\\_|\\___|  \\___\\___/|_|\\_|_|\\_|___\\___| |_| |___\\___/|_|\\_|\n"
                         << "\"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
                         << endl;
                    cout << "[D3f4ult] �n�a...�ݨӳo�Ӧ��A�����򥻸�Ƥ����ڭ̬� �ڭ̥u�n�j��fu,4fm3y xul4x�F..." << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] what??? yp3ak7�^��??? �ڪ���y4���1u04t/6�ýX�F???" << endl;
                    Sleep(2000);
                    cout << "[hacker]: ������!!! �A���q���w�g�Q�ڴx���F!!!" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] ���...huiogrbeijpa �^��..." << endl;
                    Sleep(3000);
                    cout << "[hacker]: ��A�ۧڤ��Ф@�U �ڥs�j�� �ڬO���R�q�������a �]���w���q�� �Ӳ{�b�����p�N�O�ڷd�� ��������!!!" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �A��gp6ak7...�n�ou;4��???" << endl;
                    Sleep(2000);
                    cout << "[hacker]: �]���ڷQ����A���H�����ܯ�O��awa" << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] �J�M5k4u;4...���Nao6��k�F... ��! �ΧO����k�ѨM�o�����M��!" << endl;
                    cout << "(�^��A���q�� �ˬdlog �ݬݥL���s�u�ܸ�)" << endl;
                    while(true) {
                        cout << "[Jhon's Server] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="mysvr") {
                            break;
                        }
                    }
                    while(true) {
                        cout << "[myserver] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="ls") {
                            cout << "home\n"
                                 << "log\n"
                                 << "bin\n"
                                 << "sys\n";
                        } else if (cmd=="cd log") {
                            cout << "[hacker] shell bypassed\n"
                                 << "[hacker] firewall solved\n"
                                 << "[hacker] OPEN PORT:22\n"
                                 << "[hacker] OPEN PORT:25\n"
                                 << "[hacker] OPEN PORT:21\n"
                                 << "[hacker] OPEN PORT:80\n";
                            break;
                        } else if (cmd=="cd bin") {
                            cout << "-Empty-" << endl;
                        } else if (cmd=="cd sys") {
                            cout << "x-server.sys\n"
                                 << "os-config.sys\n"
                                 << "bootcfg.dll\n"
                                 << "netcfgx.dll\n";
                        }
                    }
                    cout << "[D3f4ult] �n�F! ����scan �d�d�ݲ{�bhacker���s���O�h��!" << endl;
                    while(true) {
                        cout << "[mysvr] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="scan") {
                            break;
                        }
                    }
                    cout << "�H�U�O�ثe�b�Ϻ��W�䪺�쪺�q��or���A��\n"
                          << "1. Jhon's Server (192.168.45.2)\n"
                          << "2. Hoyiqiang's NAS (192.168.31.4)\n"
                          << "3. huirohbuhrupieahiui (666.666.666.666)\n"
                          << endl;
                    Sleep(2000);
                    cout << "echo [D3f4ult] ����cnt 3" << endl;
                    while(true) {
                        cout << "[myserver] $~ ";
                        getline(cin, cmd);
                        if (cmd=="cnt 3") {
                            break;
                        }
                    }
                    cout << "echo [D3f4ult] �n! �{�b��Jporthack�b�J�L���q��!" << endl;
                    while(true) {
                        cout << "[huirohbuhrupieahiui] $~ ";
                        getline(cin, cmd);
                        if (cmd=="porthack") {
                            cout << "{PortHack} running..." << endl;
                            PortHack();
                            Sleep(2000);
                            cout << "[D3f4ult] �ְ�...�w�gdj94�Ӥ��ΤF!" << endl;
                            Sleep(5000);
                            cout << "{PortHack} done!" << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] �ܦn! �{�b��Jrm *�R���q��gl4���Ҧ���� (���O�A���q��)" << endl;
                    while(true) {
                        cout << "[huirohbuhrupieahiui] $~ C:/";
                        getline(cin, cmd);
                        if (cmd=="rm *") {
                            cout << "deleting..." << endl;
                            Sleep(3000);
                            cout << "done!" << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] �D�`�n �ש󧹦��F!" << endl;
                    Sleep(2000);
                    cout << "[hacker]: �i�c...�A��njo6ru ���ܯ�O���dk3u3�o��j???" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] ������ �{�b�A�ܦ��ýX�F!" << endl;
                    Sleep(2000);
                    cout << endl
                         << "\"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
                         << "\"  |_ _| \\| |/ __/ _ \\|  \\/  |_ _| \\| |/ __|  / __/ _ \\| \\| | \\| | __/ __|_   _|_ _/ _ \\| \\| |\n"
                         << "\"   | || .` | (_| (_) | |\\/| || || .` | (_ | | (_| (_) | .` | .` | _| (__  | |  | | (_) | .` |\n"
                         << "\"  |___|_|\\_|\\___\\___/|_|  |_|___|_|\\_|\\___|  \\___\\___/|_|\\_|_|\\_|___\\___| |_| |___\\___/|_|\\_|\n"
                         << "\"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
                         << endl;
                    cout << "[�������s�u]: ���������ڳ��L" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �A�O��???" << endl;
                    Sleep(2000);
                    cout << "[�������s�u]: �ڬO�o�ӹC�����гy��:���j" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] ���O�� �A�V�i�ӷF��???" << endl;
                    Sleep(2000);
                    cout << "[�������s�u]: �ڭn�i�D�A�̨�� �ڦb�A�̪��q���̩�F���forkbomb" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] what?????" << endl;
                    Sleep(2000);
                    cout << "[hacker]: what??????????????" << endl;
                    Sleep(2000);
                    cout << "[�������s�u]: �L�F5��� �o��forkbomb�N�|�z�� �A�q���W���Ҧ���Ƴ��|����" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �A������n�o�˰�???" << endl;
                    Sleep(2000);
                    cout << "[�������s�u]: �]���ڷQ����@���������F ._." << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] �����*!!!!!!!!!!" << endl;
                    Sleep(1000);
                    cout << "[hacker]: what the f***" << endl;
                    Sleep(1000);
                    cout << "(�{�Ǥw�Q�j���)" << endl;
                    Sleep(1000);
                    cout << "[hacker]: (�w���_�s�u)" << endl;
                    Sleep(1000);
                    cout << "[�������s�u]: �N�o��! �W��!" << endl;
                    Sleep(2000);
                    system("cls");
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("sounds\\DreamHead.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    cout << "Demo (�ݨ�о�) �N��o�̵����F �᭱�ڷ|�~��o��s\n"
                          << "�P�¦U��C���ժ���!\n"
                          << endl;
                    string homes;
                    while(true) {
                        cout << "�^��D���(home) ���}(exit) :";
                        cin >> homes;
                        if (homes=="home") {
                            break;
                        } else if (homes=="exit"){
                            string chse="2\n";
                            break;
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