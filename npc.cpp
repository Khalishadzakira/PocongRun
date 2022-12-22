#include "npc.h"

Grave::Grave() {

}

void Grave::Start(Vector2f position, Texture& tex) {
	this->position = position;

	texture = tex;
	sprite = Sprite(tex, IntRect(0, 0, texture.getSize().x, texture.getSize().y));

	sprite.setPosition(position);

	UpdateCollisionBox();
}

void Grave::UpdateCollisionBox() {
	collisionBox.left = position.x;
	collisionBox.top = position.y;
	collisionBox.width = sprite.getTextureRect().width;
	collisionBox.height = sprite.getTextureRect().height;
}

void Grave::Update() {
	position.x -= speed;
	sprite.setPosition(position);

	sprite.setTextureRect(IntRect(0, 0, texture.getSize().x, texture.getSize().y));

	UpdateCollisionBox();
}