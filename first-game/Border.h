#pragma once

#include <SFML/Graphics.hpp>

class Border
{
private:
public:
    void Display(sf::RenderWindow& window);
    void Update(sf::Time dt);
    Border(sf::Vector2f topleft, sf::Vector2f size, float thickness);

private:
    sf::RectangleShape rect;
};

