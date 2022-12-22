#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <deque>
#include <stdio.h>

#include "player.h"
#include "npc.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	int width, height;

    Player player;

public:
	Game(RenderWindow* win, int w, int h);
	int Start();

};

class Platform {
private:
    Texture texture;
    RectangleShape shape;
    Vector2f position;
    Rect<float> collisionBox;

    int speed;

public:
    Platform(int w, int h, int x) {
        shape = RectangleShape(Vector2f(w, h));
        shape.setFillColor(sf::Color::Green);

        position = Vector2f(x, 560 - h);
        shape.setPosition(position);

        collisionBox.left = position.x;
        collisionBox.top = position.y;
        collisionBox.width = shape.getSize().x;
        collisionBox.height = shape.getSize().y;
    }

    RectangleShape GetShape() {
        return shape;
    }

    Vector2f GetPosition() {
        return position;
    }

    Rect<float> GetCollisionBox() {
        return collisionBox;
    }

    void SetSpeed(int val) {
        speed = val;
    }

    void UpdateCollisionBox() {
        collisionBox.left = position.x;
        collisionBox.top = position.y;
        collisionBox.width = shape.getSize().x;
        collisionBox.height = shape.getSize().y;
    }

    void Update() {
        position.x -= speed;
        shape.setPosition(position);

        UpdateCollisionBox();
    }
};

#endif