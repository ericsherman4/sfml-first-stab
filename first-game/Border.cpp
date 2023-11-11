#include "Border.h"

// topleft position includes the border. 
// size includes border as borader expands inward.
Border::Border(sf::Vector2f topleft, sf::Vector2f size, float thickness)
    : border(size)
{
    border.setFillColor(sf::Color::Black);
    border.setPosition(topleft);
    border.setOutlineThickness(-thickness);
    border.setOutlineColor(sf::Color::Cyan);

    // determine the inner bounding box, should just be size accounted for
    // position offset.
    auto bounding_box = border.getGlobalBounds();
    bounding_box.left += thickness;
    bounding_box.width -= thickness;
    bounding_box.height -= thickness;
    bounding_box.top += thickness;
    inner_container = bounding_box;

}

sf::Rect<float> Border::GetRect() const
{
    return inner_container;
}

void Border::Display(sf::RenderWindow& window) const
{
    window.draw(border);
}

void Border::Update(sf::Time dt)
{
}
