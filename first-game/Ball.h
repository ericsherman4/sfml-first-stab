#pragma once

#include <SFML/Graphics.hpp>
#include "Border.h"

class Ball
{
private:

public:
    Ball();
    void Init(sf::Vector2f center_pos, sf::Vector2f prev_pos_in, sf::Color color);
    void Display(sf::RenderWindow & window);
    void Update(float dt);
    void TestCollision(const Border& border);
    void TestCollision(Ball& other_ball);
    static void Ball_Collision(Ball& ball1, Ball& ball2);


private:

    bool initialized;
    sf::CircleShape ball;
    sf::Vector2f curr_pos;
    sf::Vector2f prev_pos;

public: 
    static const sf::Vector2f GRAV;
    static constexpr float RADIUS = 4.f;
    static constexpr float GRAV_CONST = 40.f;
};

