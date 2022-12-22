#include "player.h"

float gravity = 7.f;

Player::Player() {

}

void Player::Start(Vector2f StartPosition, Texture tex) {
    position = StartPosition;

    texture = tex;

    sprite = Sprite(texture, IntRect(0, 0, texture.getSize().x, texture.getSize().y / 9));
    
    sprite.setPosition(position);
    sprite.setScale(2, 2);

    velocity = Vector2f(0, 0);

    UpdateCollisionBox();
}
void Player::SetPosition(Vector2f pos) {
    position = pos;
    sprite.setPosition(position);
}

void Player::SetVelocity(Vector2f vel) {
    velocity = vel;
}

Sprite& Player::GetSprite() {
    return sprite;
}

Vector2f Player::GetPosition() {
    return position;
}

Rect<float> Player::GetCollisionBox() {
    return collisionBox;
}

void Player::Jump() {
    if (isCollide) {
        velocity.y = -15.f;
        isCollide = false;
        return;
    }
}

void Player::UpdateCollisionBox() {
    collisionBox.left = position.x;
    collisionBox.top = position.y;
    collisionBox.width = sprite.getTextureRect().width * sprite.getScale().x;
    collisionBox.height = sprite.getTextureRect().height * sprite.getScale().y;
}

void Player::Collide(FloatRect collider) {
    if (!GetCollisionBox().intersects(collider)) {
        return;
    }

    SetPosition(Vector2f(GetPosition().x, collider.top - GetSprite().getTextureRect().height * sprite.getScale().y));
    velocity.y = 0;
    isCollide = true;


        
}

bool Player::CollideEnemy(FloatRect collider) {
    if (!GetCollisionBox().intersects(collider)) {
        return false;
    }

    return true;
}

int Player::GameOver() {
        
}

// Update Loop
void Player::Update() {

    velocity.y += gravity / 15;

    position += velocity;

    if (animationState > 5) animationState = 0;
    if (animationTimer <= 0) {
        animationState++;
        animationTimer = 7;
    }
    animationTimer--;

    sprite.setTextureRect(IntRect(0 + (texture.getSize().x / 9) * animationState, 0, texture.getSize().x / 9, texture.getSize().y));
    sprite.setPosition(position);

    UpdateCollisionBox();
}