#pragma once

#include <SFML/Graphics.hpp>

class Border
{
private:
public:
    void Display(sf::RenderWindow& window) const;
    void Update(sf::Time dt);
    Border(sf::Vector2f topleft, sf::Vector2f size, float thickness);
    sf::Rect<float> GetRect() const;

private:
    sf::RectangleShape border;
    sf::Rect<float> inner_container;
};

