#pragma once

#include <SFML/Graphics.hpp>
#include "Border.h"

class Ball
{
private:

public:
    Ball();
    void Init(sf::Vector2f vel_in, sf::Vector2f center_pos, sf::Color color);
    void Display(sf::RenderWindow & window);
    void Update(sf::Time dt);
    void TestCollision(const Border& border);
    void TestCollision(Ball& other_ball);

private:
    static constexpr float PIXELS_PER_METER = 1.f;
    static constexpr float RADIUS = 30.0f;

    bool initialized;
    sf::CircleShape ball;
    sf::Vector2f pos;
    sf::Vector2f vel;
};

