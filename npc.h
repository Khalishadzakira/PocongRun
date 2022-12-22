#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
class Grave {
private:
	Vector2f position;

	Texture texture;
	Sprite sprite;

	FloatRect collisionBox;

	float speed;

	int animationState = 0;
	int animationTimer = 5;

public:
	Grave();
	void Start(Vector2f position, Texture& tex);

	FloatRect GetCollisionBox() { return collisionBox; }
	Sprite& GetSprite() { return sprite; };
	void SetSpeed(float s) { speed = s; }

	void UpdateCollisionBox();
	void Update();
};

