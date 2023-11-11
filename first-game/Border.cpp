#include "Border.h"

Border::Border(sf::Vector2f topleft, sf::Vector2f size, float thickness)
    : rect(size)
{
    rect.setFillColor(sf::Color::Black);
    rect.setPosition(topleft + sf::Vector2f(thickness, thickness));
    rect.setOutlineThickness(thickness);
    rect.setOutlineColor(sf::Color::Cyan);
}

void Border::Display(sf::RenderWindow& window)
{
    window.draw(rect);
}

void Border::Update(sf::Time dt)
{
}
