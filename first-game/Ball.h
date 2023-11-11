#pragma once

#include <SFML/Graphics.hpp>
#include "Border.h"

class Ball
{
private:

public:
    Ball();
    Ball(float radius, sf::Vector2f center_pos, sf::Color color);
    void Display(sf::RenderWindow & window);
    void Update(sf::Time dt);
    void TestCollision(const Border& border);
    void TestCollision(const Ball& other_ball);

private:

    static constexpr float PIXELS_PER_METER = 25.f;
    sf::CircleShape ball;
    sf::Vector2f pos;
    sf::Vector2f vel;
    float radius;
};

