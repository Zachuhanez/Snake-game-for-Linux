#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

void Symbol(int L, int arr[][2], int x, int y)
{
    for(int i = 1; i < L; i++)
    {
        if(arr[i][0] == x && arr[i][1] == y)
        {
            cout << '@';
            break;
        }
        if(arr[0][0] == x && arr[0][1] == y)
        {
            cout << "*";
            break;
        }
        if(i == L - 1)
        {
            cout << " ";
        }
    }
}
void Draw(int arr[][2], int L, int width = 0, int height = 0)
{
    for(int y2 = 0; y2 <= height; y2++)
    {
        if (y2 == 0 || y2 == height)
        {
            for(int i = 0; i <= width; i++)
            {
                cout << "#";
            }
            cout << '#' << endl;
        }
        else
        {
            cout << "#";
            for(int x2 = 1; x2 <= width; x2++)
            {
                Symbol(L, arr, x2, y2);
            }
            cout << '#' << endl;
        }
    }
}

int main()
{
    srand(time(0));
    GAME:
    int NewELement[2];
    char v = ' ', v2 = v;
    int TailL = 5;
    bool GameOver = false;
    int MaxX = 25, MaxY = 25;
    int tail[1000][2]{{rand()%MaxX, rand()%MaxY}, {20, 20}, {19, 20}, {18, 20}, {17, 20}};
    int PlayerX = 20, PlayerY = 20;

    while (!GameOver)
    {
        system("clear");
        if(PlayerX == MaxX || PlayerY == MaxY || PlayerY == 0 || PlayerX == 0)
        {
            GameOver = true;
            break;
        }

        for(int i = 2; i < TailL; i++)
        {
            if(PlayerX == tail[i][0])
            {
                if(PlayerY == tail[i][1])
                {
                    GameOver = true;
                }
            }
        }

        cout << "Score = " << TailL - 5 << endl;
        Draw(tail, TailL, MaxX, MaxY);
        if(tail[0][0] == 0 || tail[0][1] == 0)
        {
            if(tail[0][0] == 0)
            {
                while(tail[0][0] == 0)
                {
                    tail[0][0] = rand()%MaxX;
                }
            }
            if(tail[0][1] == 0)
            {
                while(tail[0][1] == 0)
                {
                    tail[0][1] = rand()%MaxY;
                }
            }
        }
        if(_kbhit())
        {
            v2 = getch();
            if(v2 == 'w' && v != 's') { v = 'w'; }
            if(v2 == 's' && v != 'w') { v = 's'; }
            if(v2 == 'a' && v != 'd') { v = 'a'; }
            if(v2 == 'd' && v != 'a') { v = 'd'; }
        }

        this_thread::sleep_for(chrono::milliseconds(150));

        if(v == 'w')      { PlayerY--; }
        else if(v == 's') { PlayerY++; }
        else if(v == 'a') { PlayerX--; }
        else if(v == 'd') { PlayerX++; }

        v2 = v;

        if(v == 'w' || v == 's' || v == 'a' || v == 'd')
        {
            NewELement[0] = tail[TailL - 1][0];
            NewELement[1] = tail[TailL - 1][1];
            for(int i = TailL; i > 1; i--)
            {
                tail[i][0] = tail[i-1][0];
                tail[i][1] = tail[i-1][1];
            }
            tail[1][0] = PlayerX;
            tail[1][1] = PlayerY;
        }

        if(PlayerX == tail[0][0] && PlayerY == tail[0][1])
        {
            TailL++;
            tail[TailL - 1][0] = NewELement[0];
            tail[TailL - 1][1] = NewELement[1];

            tail[0][0] = rand()%MaxX;
            tail[0][1] = rand()%MaxY;
        }
    }
    if(GameOver)
    {
        system("clear");
        cout << "Score = " << TailL - 5 << endl;
        cout << "#####     #     ##   ## #####\n" << "#        # #    # # # # #\n" << "#  ##   #   #   #  #  # #####\n" << "#   #  #######  #     # #\n" << "##### #       # #     # #####\n" << endl << "##### #       # ###### #####\n" << "#   #  #     #  #      #   #\n" << "#   #   #   #   ###### #####\n" << "#   #    # #    #      #  #\n" << "#####     #     ###### #   #\n" << endl << "q - quit | other - restart\n";
        char s = getch();
        if(s == 'q') { cout << "Good luck!" << endl; }
        else         { goto GAME;                    }
    }
}
