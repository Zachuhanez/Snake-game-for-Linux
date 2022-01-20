#include "Point.cpp"
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    system("clear");
    cout << "      ____  ____         _____  ___   ____\n"
         << "     |     |    | |\\   |   |   |   \\ |    | |\n"
         << "     |     |    | | \\  |   |   |___/ |    | |\n"
         << "     |     |    | |  \\ |   |   |\\    |    | |\n"
         << "     |____ |____| |   \\|   |   | \\   |____| |____\n"
         << endl
         << endl
         << endl
         << "                     _____\n"
         << "                    |     |\n"
         << "                    |  W  |  -  Up\n"
         << "               _____|_____|_____\n"
         << "              |     |     |     |\n"
         << "              |  A  |  S  |  D  |  -  Right\n"
         << "              |_____|_____|_____|\n"
         << "                 |     |\n"
         << "                 |     |___Down\n"
         << "                 |\n"
         << "                 |___Left\n";
    this_thread::sleep_for(chrono::milliseconds(2800));
    system("clear");
    srand(time(0));

    GAME:
    int NewELement[2];
    char v = ' ', v2 = v;
    int TailL = 5;
    Point Player(20,20);
    bool progress = true;
    int MaxX = 40, MaxY = 40;
    int tail[1000][2]{{rand()%MaxX, rand()%MaxY}, {20, 20}, {19, 20}, {18, 20}, {17, 20}};

    while (true)
    {
        system("clear");
        if(Player.x == MaxX + 1 || Player.y == MaxY || Player.y == 0 || Player.x == 0)
        {
            progress = false;
            break;
        }

        for(int i = 2; i < TailL; i++)
        {
            if(Player.x == tail[i][0])
            {
                if(Player.y == tail[i][1])
                {
                    progress = false;
                }
            }
        }

        cout << "Score = " << TailL - 5 << endl;
        Player.Draw(tail, TailL, MaxX, MaxY);
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
            if(v2 == 'q')
            {
                progress = false;
                break;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(150));

        if(v == 'w')      { Player.y--; }
        else if(v == 's') { Player.y++; }
        else if(v == 'a') { Player.x--; }
        else if(v == 'd') { Player.x++; }

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
            tail[1][0] = Player.x;
            tail[1][1] = Player.y;
        }

        //if player eat apple it makes tail longer and create new element
        if(Player.x == tail[0][0] && Player.y == tail[0][1])
        {
            TailL++;
            tail[TailL - 1][0] = NewELement[0];
            tail[TailL - 1][1] = NewELement[1];

            tail[0][0] = rand()%MaxX;
            tail[0][1] = rand()%MaxY;
        }
        if(progress == false) { break; }
    }
    if(!progress)
    {
        system("clear");
        cout << "Score = " << TailL - 5 << endl;
        cout << "#####     #     ##   ## #####\n"
             << "#        # #    # # # # #\n"
             << "#  ##   #   #   #  #  # #####\n"
             << "#   #  #######  #     # #\n"
             << "##### #       # #     # #####\n"
             << endl
             << "##### #       # ###### #####\n"
             << "#   #  #     #  #      #   #\n"
             << "#   #   #   #   ###### #####\n"
             << "#   #    # #    #      #  #\n"
             << "#####     #     ###### #   #\n"
             << endl
             << "q - quit | other - restart\n";
        char s = getch();
        if(s == 'q') { cout << "Good luck!" << endl; }
        else         { goto GAME;                    }
    }
    else
    {
        system("clear");
        cout << "Score = " << TailL - 5 << endl;
        cout << "#   # ##### #   #\n"
             << " # #  #   # #   #\n"
             << "  #   #   # #   #\n"
             << "  #   #   # #   #\n"
             << "  #   #####  ### \n"
             << endl
             << "#     #  ##### #   #\n"
             << "#  #  #  #   # ##  #\n"
             << "#  #  #  #   # # # #\n"
             << "# # # #  #   # #  ##\n"
             << " #   #   ##### #   #\n"
             << endl
             << "q - quit | other - restart\n";
        char s = getch();
        if(s == 'q') { cout << "Good luck!" << endl; }
        else         { goto GAME;                    }
    }
}
