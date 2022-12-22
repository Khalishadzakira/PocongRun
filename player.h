#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

using namespace sf;
class Player {
private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    Rect<float> collisionBox;
    bool isCollide = false;
    int animationState = 0;
    int animationTimer = 5;

public:
    Player();
    void Start(Vector2f StartPosition, Texture tex);
    void SetPosition(Vector2f pos);
    void SetVelocity(Vector2f vel);
    Sprite& GetSprite();
    Vector2f GetPosition();
    Rect<float> GetCollisionBox();
    void Jump();
    void Dash();
    void UpdateCollisionBox();
    void Collide(FloatRect collider);
    bool CollideEnemy(FloatRect collider);
    int GameOver();
    void Update();
};

#endif