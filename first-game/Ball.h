#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private:

public:
    Ball();
    Ball(float radius, sf::Vector2f position, sf::Color color);
    void Display(sf::RenderWindow & window);
    void Update(sf::Time dt);

private:

    static constexpr float PIXELS_PER_METER = 25.f;

    sf::CircleShape ball;
    sf::Vector2f pos;
    sf::Vector2f vel;
};

