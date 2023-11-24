#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

class Ball
{
private:

public:
    Ball();
    void Init(sf::Vector2f center_pos, sf::Vector2f prev_pos_in, sf::Color color);
    void Display(sf::RenderWindow & window);
    void Update(float dt);
    void TestCollision(Ball * other_ball);
    bool GetInitialized();

    sf::Vector2f curr_pos;

private:

    bool initialized;
    sf::CircleShape ball;
    sf::Vector2f prev_pos;

public: 
    static const sf::Vector2f GRAV;
    static constexpr float RADIUS = CONFIG_BALL_RADIUS;
};

