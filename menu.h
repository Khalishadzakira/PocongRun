#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenu {
private:
	RenderWindow* window;
	int width, height;

public:
	MainMenu(RenderWindow* win, int w, int h);
	int Start();
};

class GameOver {
private:
	RenderWindow* window;
	int width, height;

public:
	GameOver(RenderWindow* win, int w, int h);
	int Start();
};

#endif
