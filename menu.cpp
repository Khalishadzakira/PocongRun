#include "menu.h"

MainMenu::MainMenu(RenderWindow* win, int w, int h) {
	window = win;

	width = w;
	height = h;
}

int MainMenu::Start() {
    // Texts
    Font robotoRegular;
    robotoRegular.loadFromFile("Fonts/Roboto-Regular.ttf");

    Text text("Press Space to Start", robotoRegular);

    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.f,
        text.getLocalBounds().top + text.getLocalBounds().height / 2.f
    );
    text.setPosition(width / 2.f, height / 2.f);

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) {
                // Window Closed
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
            {
                switch (event.key.code)
            case Keyboard::Space:
                {
                    return 1;
                }

            }
            }
        }

        window->clear();
        window->setFramerateLimit(60);

        window->draw(text);

        window->display();
    }
}

GameOver::GameOver(RenderWindow* win, int w, int h) {
    window = win;

    width = w;
    height = h;
}

int GameOver::Start() {
    // Texts
    Font robotoBold;
    robotoBold.loadFromFile("Fonts/Roboto-Bold.ttf");

    Text text("Game Over", robotoBold);

    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2.f,
                    text.getLocalBounds().top + text.getLocalBounds().height/2.f
    );
    text.setPosition(width / 2.f, height / 2.f);

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) {
                // Window Closed
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
            {
                switch (event.key.code)
            case Keyboard::Space:
                {
                    return 0 ;
                }

            }
            }
        }

        window->clear();
        window->setFramerateLimit(60);

        window->draw(text);

        window->display();
    }
}