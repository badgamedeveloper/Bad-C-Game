#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <MMSystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")

void endScreen();
void gameOver();
void ending();

using namespace std;

int main()
{
    srand(time(NULL));
    int damage;
    char movement2;
    int playerHP = 250;
    int enemyHP = 250;
    int roll;
    int enemyRoll;
    char replay;
    int dropRoll;
    int potionCount = 25;
    int o = 1;
    int levelCount = 1;
    bool gameOverCond = 0;
    int playBossMusic = 0;

    system("mode 200, 100");
    SMALL_RECT WinRect = {0, 0, 200, 100};
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

    char version;
    char start;

    cout << "\n\n\n\n\n\n                                                                                     ";
    string question = "Hey. Welcome to...\n\n\n\n                                                                      Actually, first of all, which do you prefer?\n\n\n\n\n\n\n                                                                  (0) Plants                              (1) Animals\n\n\n\n\n                                                                  Your input : ";
    int i = 0;

    // Generates a question before the game - Determines the storyline
    while(question[i] != '\0')
    {
        if(question[i] == ' ')
        {
            cout << question[i];
            i++;
        }
        else
        {
            cout << question[i];
            Sleep(50);
            i++;
        }
    };
    for(int x = 0; x < 1; x++)
        {
            cin >> version;

            if(version != '0' && version != '1')
            {
                cout << "                                                                  Invalid input, try again : ";
                x = -1;
            }
    }
    // Loads the title screen
    system("CLS");
    if(version == '0')
    {
        cout << "\n\n\n\n\n                                                                                         ANIMAL INVASION\n\n\n\n\n                                                                                       Input 1 to play" << endl;
    }
    else if(version == '1')
    {
        cout << "\n\n\n\n\n                                                                                         ATTACK OF THE VEGGIES\n\n\n\n\n                                                                                       Input 1 to play" << endl;
    }
    cout << "\n\n\n                                                                                       Input : ";
    for(int beg = 0; beg < 1; beg++)
    {
        cin >> start;
        if(start != '1')
        {
            cout << "\n                                                                                       Invalid input, try again : ";
            beg = -1;
        }
    }
    system("CLS");
    // Displays beginning story and instructions
    char next;

    if(version == '0')
    {
        cout << "\n\n\n\n\n                                                                     The eeeeevill animals have stolen the imperial botanical crown!!!\n                                                                     YOU have been tasked by the Grand Botanical Emperor to retake the great crown for the EMPIRE!!!.\n                                                                     The crown is believed to be behind a labyrinth created by the EEEEEVILL Animals\n                                                                     Good luck, brave crusader.\n\n                                                                           Input 1 to continue : ";
    }
    if(version == '1')
    {
        cout << "\n\n\n\n\n                                                                     The eeeeevill plants have stolen the imperial zoological crown!!\n                                                                     YOU have been tasked by the Great Zoological Emperor to retake the great crown for the EMPIRE!!!.\n                                                                     The crown is believed to be behind a labyrinth created by the EEEEEVILL Plants.\n                                                                     Good luck, brave crusader.\n\n                                                                           Input 1 to continue : ";
    }
    cin >> next;

    char controls[5][90] = {
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'W', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', '_', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'A', ' ', ' ', ' ', '|', ' ', 'S', ' ', ' ', ' ', '|', ' ', 'D', ' ', ' ', ' ', '|'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '|'}
                            };


        system("CLS");
        cout << "\n\n\n\n\n                                                                         Instructions\n                                                                         ------------\n\n\n\n";
        for(int r = 0; r < 5; r++)
        {
            for(int c = 0; c < 90; c++)
            {
                cout << controls[r][c];
            }
            cout << endl;
        }
        cout << "\n\n\n                                                           Input WASD to move around the maze.\n\n                                                            Input 1 to continue : ";
        for(int x2 = 0; x2 < 1; x2++)
        {
            cin >> next;
            if(next != '1')
            {
                cout << "                                                                  Invalid input, try again : ";
                x2 = -1;
            }
        }
        system("CLS");

        int oldPlayerXPosit = 29;
        int oldPlayerYPosit = 0;
        int newPlayerXPosit;
        int newPlayerYPosit;
        char movement;
        char maze[42][51] = {    // r c
                                {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219},
                                {219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219},
                                {219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219},
                                {219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219},
                                {219, 219, 219, 219, 219, 219, 219, ' ', 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219, 219, 219, ' ', 219},
                                {254, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 'X'},
                                {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                                {219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
                                {219, ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219},
                                {219, ' ', 219, 219, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, ' ', 219, 219, 219, 219, 219, ' ', 219},
                                {219, ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', 219},
                                {219, ' ', 219, 219, 219, 219, 219, 219, 219, ' ', 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, 219, 219},
                                {219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219},
                                {219, 219, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, ' ', 219, 219, 219, 219, 219, ' ', 219, ' ', 219},
                                {219, ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', 219},
                                {219, ' ', 219, 219, 219, 219, 219, ' ', ' ', ' ', 219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219},
                                {219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', ' ', ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219},
                                {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 'X', 219}
                            };

    // Loads the maze
    if(gameOverCond == 0)
    {
    for(int x = 0; x < 1; x++)
    {
        PlaySound(NULL, NULL, 0);
        if((levelCount - 1) % 2 != 0 || levelCount == 1)
        {
        if(levelCount % 2 == 1)
        {
        for(int r = 0; r < 31; r++)
        {
            cout << "                                                                     ";
            for(int c = 0; c < 30; c++)
            {
                cout << maze[r][c];
            }
            cout << endl;
        }
        }
        else
        {
            cout << "\n\n\n" << endl;
            for(int r = 31; r < 42; r++)
        {
            cout << "                                                                        ";
            for(int c = 0; c < 51; c++)
            {
                cout << maze[r][c];
            }
            cout << endl;
        }
        }
        cout << "                                                                       Level: " << levelCount << endl;
        cout << "                                                                       Input your movement : ";
        cin >> movement;
        if(movement == 'W' || movement == 'w')
        {
            if(maze[oldPlayerXPosit - 1][oldPlayerYPosit] == 219)
            {
                cout << "try again" << endl;
            }
            else if(maze[oldPlayerXPosit - 1][oldPlayerYPosit] == ' ')
            {
                maze[oldPlayerXPosit - 1][oldPlayerYPosit] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerXPosit = oldPlayerXPosit - 1;
            }
            else
            {
                maze[oldPlayerXPosit - 1][oldPlayerYPosit] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerXPosit = oldPlayerXPosit - 1;
                system("CLS");
                cout << "                                                                                 You have finished the level!" << endl << endl;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                o = 90;
                if(levelCount % 2 == 0)
                {
                    oldPlayerXPosit = 29;
                    oldPlayerYPosit = 0;
                }
                else
                {
                    oldPlayerXPosit = 31;
                    oldPlayerYPosit = 1;
                }
                maze[oldPlayerXPosit][oldPlayerYPosit] = 254;
                levelCount++;
            }
        }
        if(movement == 'D' || movement == 'd')
        {
            if(maze[oldPlayerXPosit][oldPlayerYPosit + 1] == 219)
            {
                cout << "try again" << endl;
            }
            else if(maze[oldPlayerXPosit][oldPlayerYPosit + 1] == ' ')
            {
                maze[oldPlayerXPosit][oldPlayerYPosit + 1] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerYPosit = oldPlayerYPosit + 1;
            }
            else
            {
                maze[oldPlayerXPosit][oldPlayerYPosit + 1] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerYPosit = oldPlayerYPosit + 1;
                system("CLS");
                cout << "                                                                                 You have finished the level" << endl << endl;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                o = 90;
                if(levelCount % 2 == 0)
                {
                    oldPlayerXPosit = 29;
                    oldPlayerYPosit = 0;
                }
                else
                {
                    oldPlayerXPosit = 31;
                    oldPlayerYPosit = 1;
                }
                maze[oldPlayerXPosit][oldPlayerYPosit] = 254;
                levelCount++;
            }
        }
        if(movement == 'S' || movement == 's')
        {
            if(maze[oldPlayerXPosit + 1][oldPlayerYPosit] == 219)
            {
                cout << "try again" << endl;
            }
            else if(maze[oldPlayerXPosit + 1][oldPlayerYPosit] == ' ')
            {
                maze[oldPlayerXPosit + 1][oldPlayerYPosit] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerXPosit = oldPlayerXPosit + 1;
            }
            else
            {
                maze[oldPlayerXPosit + 1][oldPlayerYPosit] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerXPosit = oldPlayerXPosit + 1;
                system("CLS");
                cout << "                                                                                 You have finished the level" << endl << endl;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                o = 90;
                if(levelCount % 2 == 0)
                {
                    oldPlayerXPosit = 29;
                    oldPlayerYPosit = 0;
                }
                else
                {
                    oldPlayerXPosit = 31;
                    oldPlayerYPosit = 1;
                }
                maze[oldPlayerXPosit][oldPlayerYPosit] = 254;
                levelCount++;
            }
        }
        if(movement == 'A' || movement == 'a')
        {
            if(maze[oldPlayerXPosit][oldPlayerYPosit - 1] == 219)
            {
                cout << "try again" << endl;
            }
            else if(maze[oldPlayerXPosit][oldPlayerYPosit - 1] == ' ')
            {
                maze[oldPlayerXPosit][oldPlayerYPosit - 1] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerYPosit = oldPlayerYPosit - 1;
            }
            else
            {
                maze[oldPlayerXPosit][oldPlayerYPosit - 1] = 254;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                oldPlayerYPosit = oldPlayerYPosit - 1;
                system("CLS");
                cout << "                                                                                 You have finished the level" << endl << endl;
                o = 90;
                maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                if(levelCount % 2 == 0)
                {
                    oldPlayerXPosit = 29;
                    oldPlayerYPosit = 0;
                }
                else
                {
                    oldPlayerXPosit = 31;
                    oldPlayerYPosit = 1;
                }
                maze[oldPlayerXPosit][oldPlayerYPosit] = 254;
                levelCount++;
            }
        }
        if(o != 90)
        {
        int battle = (rand() % 10) + 1;
        system("CLS");
        if(battle == 4)
        {
            int playerHP = 250;
            int enemyHP = 250;
            PlaySound(TEXT("EnemyBattle.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            for(int z = 0; z < 1; z++)
            {
                for(int x = 0; x < 1; x++)
                {
                    cout << "\n\n\n\n\n                                                                                 1-ATK 2-DFD 3-POT (count = " << potionCount << ") 4-RUN\n\n\n\n\n                                                                             HP = " << playerHP << "          ENEMY HP = " << enemyHP << "\n\n\n                                                                                       Input : ";
                    cin >> movement2;

                    switch(movement2)
                    {
                        case '1' :
                        system("CLS");
                        damage = (rand() % 10) + 30;
                        enemyHP = enemyHP - damage;
                        cout << "\n\n                                                                            You attacked the enemy! " << damage << " damage" << endl;
                            break;
                        case '2' :
                        system("CLS");
                        roll = rand() % 100;
                            if(roll >= 85)
                            {
                                cout << "\n\n                                                                            You failed to block the enemy's attack!" << endl;
                                break;
                            }
                            else
                            {
                                cout << "\n\n                                                                            You blocked the enemy's attack!" << endl;
                                break;
                            }
                        case '3' :
                        system("CLS");
                        if(potionCount > 0)
                        {
                            playerHP = playerHP + 100;
                            cout << "\n\n                                                                            You drank a potion! Gained 100 HP" << endl;
                            potionCount--;
                        }
                        else
                        {
                            cout << "\n\n                                                                            You have no potions!" << endl;
                        }
                            break;
                        case '4' :
                        system("CLS");
                        roll = rand() % 100;
                            if(roll <= 75)
                            {
                                cout << "\n\n                                                                            Couldn't get away!" << endl;
                                break;
                            }
                            else
                            {
                                enemyHP = 0;
                                cout << "\n\n                                                                            You ran away!" << endl;
                                endScreen();
                                cout << "\n\n                                                                                   Input any key to continue :" << endl;
                                cin >> replay;
                                if(replay == 'y' || replay == 'Y')
                                {
                                    x = -1;
                                    playerHP = 250;
                                    enemyHP = 250;
                                    system("CLS");
                                }
                                break;
                            }
                        default :
                        system("CLS");
                        cout << "\n\n                                                                                    Invalid move, try again!" << endl;
                        enemyRoll = rand() % 3;
                                if(enemyRoll < 3)
                                {
                                    enemyRoll = (rand() % 10) + 30;
                             int battle = (rand() % 5) + 1;       playerHP = playerHP - enemyRoll;
                                    cout << "\n                                                                            Enemy attacks! " << enemyRoll << " damage " << endl;
                                }
                                else
                                {
                                    enemyRoll = (rand() % 10) + 15;
                                    playerHP = playerHP - enemyRoll;
                                    enemyHP = enemyHP + enemyRoll;
                                    cout << "\n                                                                            Enemy drains your HP and gains " << enemyRoll << " HP! You lose " << enemyRoll << " HP!" << endl;
                                }
                    }
                }
                    if(enemyHP != 0)
                    {
                        for(int y = 0; y < 1; y++)
                        {
                            if(movement2 == '1' || movement2 == '2' || movement2 == '3' || movement2 == '4')
                            {
                                if(movement2 == '2')
                                {
                                    if(roll >= 85)
                                    {
                                        enemyRoll = rand() % 3;
                                        if(enemyRoll < 3)
                                        {
                                            enemyRoll = (rand() % 10) + 30;
                                            playerHP = playerHP - enemyRoll;
                                            cout << "\n                                                                            Enemy attacks! " << enemyRoll << " damage " << endl;
                                        }
                                        else
                                        {
                                            enemyRoll = (rand() % 10) + 15;
                                            playerHP = playerHP - enemyRoll;
                                            enemyHP = enemyHP + enemyRoll;
                                            cout << "\n                                                                            Enemy drains your HP and gains " << enemyRoll << " HP! You lose " << enemyRoll << " HP!" << endl;
                                        }
                                    }
                                }
                                if(movement2 == '1' || movement2 == '3' || movement2 == '4')
                                {
                                    enemyRoll = (rand() % 3) + 1;
                                    if(enemyRoll < 3)
                                    {
                                        enemyRoll = (rand() % 10) + 30;
                                        playerHP = playerHP - enemyRoll;
                                        cout << "\n                                                                            Enemy attacks! " << enemyRoll << " damage " << endl;
                                    }
                                    else if(enemyRoll == 3)
                                    {
                                        enemyRoll = (rand() % 10) + 15;
                                        playerHP = playerHP - enemyRoll;
                                        enemyHP = enemyHP + enemyRoll;
                                        cout << "\n                                                                            Enemy drains your HP and gains " << enemyRoll << " HP! You lose " << enemyRoll << " HP!" << endl;
                                    }
                                    else
                                    {
                                        cout << endl;
                                    }
                                }

                            }
                        }
                    if(playerHP <= 0)
                    {
                        gameOver();
                        cout << "\n\n                                                                                     Input any key to play again : \n\n\n                                                                                       Input : ";
                        cin >> replay;
                        if(replay == '1')
                        {
                            playerHP = 250;
                            enemyHP = 250;
                            maze[oldPlayerXPosit][oldPlayerYPosit] = ' ';
                            if((levelCount - 1) % 3 != 0)
                            {
                                maze[29][0] = 254;
                            }
                            else
                            {
                                maze[31][1] = 254;
                            }

                            system("CLS");
                        }
                    }
                    else if(enemyHP <= 0)
                    {
                        PlaySound(NULL, NULL, 0);
                        dropRoll = rand() % 100;
                        if(dropRoll <= 65)
                        {
                            potionCount++;
                            cout << "                                                                                     The enemy dropped an potion!";
                        }
                        cout << "\n\n                                                                                     Input 1 to continue : \n\n\n                                                                                       Input : ";
                        cin >> replay;
                    }
                    else if(playerHP > 0 && enemyHP >0)
                    {
                        z = -1;
                    }
                }
            }
        }
        system("CLS");
    }
    x = -1;
    o = 1;
    }
    else
    {
        if(playBossMusic = 0)
        {
            PlaySound(TEXT("finalbossv1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            playBossMusic = 1;
        }
            cout << "                                                                                 THE BOSS APPEARED!!!" << endl;
            int playerHP = 250;
            int bossHP = 750;
            int bossRoll;
            for(int z = 0; z < 1; z++)
            {
                for(int x = 0; x < 1; x++)
                {
                    cout << "\n\n\n\n\n                                                                                 1-ATK 2-DFD 3-POT (count = " << potionCount << ") 4-RUN\n\n\n\n\n                                                                             HP = " << playerHP << "          BOSS HP = " << bossHP << "\n\n\n                                                                                       Input : ";
                    cin >> movement2;

                    switch(movement2)
                    {
                        case '1' :
                        system("CLS");
                        damage = (rand() % 10) + 30;
                        bossHP = bossHP - damage;
                        cout << "\n\n                                                                            You attacked the boss! " << damage << " damage" << endl;
                            break;
                        case '2' :
                        system("CLS");
                        damage = 0;
                        roll = rand() % 100;
                            if(roll >= 85)
                            {
                                cout << "\n\n                                                                            You failed to block the boss's attack!" << endl;
                                break;
                            }
                            else
                            {
                                cout << "\n\n                                                                            You blocked the boss's attack!" << endl;
                                break;
                            }
                        case '3' :
                        system("CLS");
                        damage = 0;
                        if(potionCount > 0)
                        {
                            playerHP = playerHP + 100;
                            cout << "\n\n                                                                            You drank a potion! Gained 100 HP" << endl;
                            potionCount--;
                        }
                        else
                        {
                            cout << "\n\n                                                                            You have no potions!" << endl;
                        }
                            break;
                        case '4' :
                        system("CLS");
                        roll = rand() % 100;
                        damage = 0;
                            if(roll <= 100)
                            {
                                cout << "\n\n                                                                            Couldn't get away!" << endl;
                                break;
                            }
                            else
                            {
                                bossHP = 0;
                                cout << "\n\n                                                                            You ran away!" << endl;
                                endScreen();
                                cout << "\n\n                                                                                   wanna play again? (Y/N)" << endl;
                                cin >> replay;
                                if(replay == 'y' || replay == 'Y')
                                {
                                    x = -1;
                                    playerHP = 250;
                                    bossHP = 750;
                                    system("CLS");
                                }
                                break;
                            }
                        default :
                        system("CLS");
                        cout << "\n\n                                                                                    Invalid move, try again!" << endl;
                        bossRoll = (rand() % 30)+1;
                                if(bossRoll < 13)
                                {
                                    bossRoll = (rand() % 10) + 30;
                             int battle = (rand() % 5) + 1;       playerHP = playerHP - bossRoll;
                                    cout << "\n                                                                            Boss attacks! " << bossRoll << " damage " << endl;
                                }
                                else if(bossRoll < 19)
                                {
                                    bossRoll = (rand() % 10) + 15;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP + bossRoll;
                                    cout << "\n                                                                            Boss drains your HP and gains " << bossRoll << " HP! You lose " << bossRoll << " HP!" << endl;
                                }
                                else if (bossRoll < 25)
                                {
                                    bossRoll = (rand() % 10) + 45;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP - 0.25 * bossRoll;
                                    cout << "\n                                                                            Boss attacks your HP and takes " << 0.25 * bossRoll << " HP in recoil! You lose " << bossRoll << " HP!" << endl;
                                }
                                else
                                {
                                    bossRoll = damage * 2;
                                    playerHP = playerHP - bossRoll;
                                    if(damage == 0)
                                    {
                                        cout << "\n                                                                            Boss tries to counter your attack. . . but it fails!" << endl;
                                    }
                                    else
                                    {
                                        cout << "\n                                                                            Boss counters your attack and doubles it back! You lose " << bossRoll << " HP!" << endl;
                                    }
                                }
                    }
                }
                    if(bossHP != 0)
                    {
                        for(int y = 0; y < 1; y++)
                        {
                            if(movement2 == '1' || movement2 == '2' || movement2 == '3' || movement2 == '4')
                            {
                                if(movement2 == '2')
                                {
                                    if(roll >= 85)
                                    {
                                        bossRoll = (rand() % 30)+1;
                                if(bossRoll < 13)
                                {
                                    bossRoll = (rand() % 10) + 30;
                                    int battle = (rand() % 5) + 1;
                                    playerHP = playerHP - bossRoll;
                                    cout << "\n                                                                            Boss attacks! " << bossRoll << " damage " << endl;
                                }
                                else if(bossRoll < 19)
                                {
                                    bossRoll = (rand() % 10) + 15;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP + bossRoll;
                                    cout << "\n                                                                            Boss drains your HP and gains " << bossRoll << " HP! You lose " << bossRoll << " HP!" << endl;
                                }
                                else if (bossRoll < 25)
                                {
                                    bossRoll = (rand() % 10) + 45;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP - 0.25 * bossRoll;
                                    cout << "\n                                                                            Boss attacks your HP and takes " << 0.25 * bossRoll << " HP in recoil! You lose " << bossRoll << " HP!" << endl;
                                }
                                else
                                {
                                    bossRoll = damage * 2;
                                    playerHP = playerHP - bossRoll;
                                    if(damage == 0)
                                    {
                                        cout << "\n                                                                            Boss tries to counter your attack. . . but it fails!" << endl;
                                    }
                                    else
                                    {
                                        cout << "\n                                                                            Boss counters your attack and doubles it back! You lose " << bossRoll << " HP!" << endl;
                                    }
                                }
                                    }
                                }
                                if(movement2 == '1' || movement2 == '3' || movement2 == '4')
                                {
                                    bossRoll = (rand() % 30)+1;
                                if(bossRoll < 13)
                                {
                                    bossRoll = (rand() % 10) + 30;
                             int battle = (rand() % 5) + 1;
                                    playerHP = playerHP - bossRoll;
                                    cout << "\n                                                                            Boss attacks! " << bossRoll << " damage " << endl;
                                }
                                else if(bossRoll < 19)
                                {
                                    bossRoll = (rand() % 10) + 15;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP + bossRoll;
                                    cout << "\n                                                                            Boss drains your HP and gains " << bossRoll << " HP! You lose " << bossRoll << " HP!" << endl;
                                }
                                else if (bossRoll < 25)
                                {
                                    bossRoll = (rand() % 10) + 45;
                                    playerHP = playerHP - bossRoll;
                                    bossHP = bossHP - 0.25 * bossRoll;
                                    cout << "\n                                                                            Boss attacks your HP and takes " << 0.25 * bossRoll << " HP in recoil! You lose " << bossRoll << " HP!" << endl;
                                }
                                else
                                {
                                    bossRoll = damage * 2;
                                    playerHP = playerHP - bossRoll;
                                    if(damage == 0)
                                    {
                                        cout << "\n                                                                            Boss tries to counter your attack. . . but it fails!" << endl;
                                    }
                                    else
                                    {
                                        cout << "\n                                                                            Boss counters your attack and doubles it back! You lose " << bossRoll << " HP!" << endl;
                                    }
                                }
                                }

                            }
                        }
                    if(playerHP <= 0)
                    {
                        gameOver();
                        cout << "\n\n                                                                                     Input 1 to respawn\n\n\n                                                                                       Input : ";
                        cin >> replay;
                        if(replay == '1')
                        {
                            playBossMusic = 0;
                            z = -1;
                            playerHP = 250;
                            bossHP = 750;
                            system("CLS");
                        }
                    }
                    else if(bossHP <= 0)
                    {
                        ending();
                        cout << "\n\n                                                                                     Would you like to play again? (Y/N)\n\n\n                                                                                       Input : ";
                        cin >> replay;
                        if(replay == 'y' || replay == 'Y')
                        {
                            z = 0;
                            x = -1;
                            playerHP = 250;
                            bossHP = 750;
                            system("CLS");
                        }
                    }
                    else if(playerHP > 0 && bossHP >0)
                    {
                        z = -1;
                    }
                }
            }
        }
    }
    }
    return 0;
    }
void endScreen()
{
    cout << "\n\n\n\n\n                                                                                       The enemy has been defeated!" << endl;
}
void gameOver()
{
    PlaySound(TEXT("GameOverFinal.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    cout << "\n\n\n\n\n                                                                                       Game Over!" << endl;
}
void ending()
{
    system("CLS");
    PlaySound(TEXT("FinaleTheme.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    cout << "\n\n\n\n\n                                                                                       The Empire's great treasures have been retrieved thanks to YOU, brave crusader!!!";
    cout << "                                                                                       The Grand Emperor congratulates you for your great struggles. You have been awarded the status of Grand Knight of the Empire!";
    cout << "                                                                                       We, on behalf of the Grand Emperor, bid you farewell and good tidings in your future Adventures!";
}
