#include <iostream>
#include <thread>
#include <Windows.h>
#include "RectangleShape.h"
#include "KeyBoard.h"
#include "MainWindow.h"
#include "Game.h"

using namespace std;

int main()
{
    while (true)
    {
        MainWindow win(25, 50);
        Game game(&win);
        KeyBoard keyboard;

        while (!game.isEndOfGame)
        {
            game.update();
            win.clear(' ');
            game.draw();
            win.display();
            
            this_thread::sleep_for(chrono::milliseconds(16));
        }
        
        system("cls");
        if (game.isWin)
            cout << "You won!" << endl;
        else
            cout << "You lose!" << endl;

        cout << "Score: " << game.score->score << endl;
        cout << "Press a key to restart" << endl;
        this_thread::sleep_for(chrono::seconds(1));

        system("pause");
    }
    

    return 0;
}