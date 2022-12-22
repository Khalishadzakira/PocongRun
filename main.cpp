#include <SFML/Graphics.hpp>

#include "game.h"
#include "menu.h"

using namespace sf;

int width = 960, height = 540;



int main()
{
    // Init Window
    RenderWindow window(VideoMode(width, height), "Game");

    // Init State
    int state = 0; // 0 = Main Menu | 1 = Game | 2 = Game Over

    Game game(&window, width, height);
    MainMenu mainMenu(&window, width, height);
    GameOver gameOver(&window, width, height);

    while (window.isOpen())
    {
        switch (state) {
        case 0:
            state = mainMenu.Start();
            break;

        case 1:
            state = game.Start();
            break;

        case 2:
            state = gameOver.Start();
            break;

        }   
    }

    return 0;
}