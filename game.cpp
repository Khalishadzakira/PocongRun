#include "game.h"

Game::Game(RenderWindow* win, int w, int h) {
	window = win;

    width = w;
    height = h;
}

int Game::Start() {
    // Load Textures
    Texture textureGhost, textureBat;
    textureGhost.loadFromFile("Sprites/ghost.png");
    textureBat.loadFromFile("Sprites/grave.png");

    // Init Player
    player.Start(Vector2f(width / 2 - 48, 300), textureGhost);

    // Init Platform
    FloatRect platformCollision(0, 480, 960, 40);

    int runSpeed = 5;

    // Background
    Texture bgTex;
    bgTex.loadFromFile("Sprites/bg.jpeg");

    Sprite bg(bgTex, IntRect(0, 0, 550, 314));
    bg.setScale(960.f / 550.f, 540.f / 314.f);

    // Platform Timer
    int timer = 0;

    // Init NPC
    std::deque<Grave> graves;

    // NPC Timer
    int spawnTimer = 250;

    // Score
    int score = 0;

    // Texts
    Font robotoBold;
    robotoBold.loadFromFile("Fonts/Roboto-Bold.ttf");

    Text scoreText("Score : " + score, robotoBold);

    // Music
    Music music;
    music.openFromFile("Sounds/music.ogg");
    music.setVolume(50);
    music.play();

    while (window->isOpen()) // game loop
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
                switch (event.key.code)
                {
                case Keyboard::Space:
                    player.Jump();
                    break;
                }
            break;

            
            }
        }        

        // Spawn NPC
        if (spawnTimer <= 0) {
            Grave g;
            g.Start(Vector2f(width + 20, 380), textureBat);

            graves.push_back(g);
            spawnTimer = rand() % 100 + 250; //Reset Timer
        }
        spawnTimer--;

        window->clear();
        window->setFramerateLimit(60);

        window->draw(bg);

        // Update Player
        player.Update();

        // Platform Collision
        player.Collide(platformCollision);

        // Update NPC
        for (int i = 0; i < graves.size(); i++) {
            graves[i].SetSpeed(runSpeed);
            graves[i].Update();

            if (player.CollideEnemy(graves[i].GetCollisionBox())) return 2;

            window->draw(graves[i].GetSprite());
        }

        // Update Score
        score++;
        scoreText.setString("Score : " + std::to_string(score));

        // Draw
        window->draw(player.GetSprite());

        window->draw(scoreText);

        window->display();
    }

    return 2;
}