#include "Border.h"

// topleft position includes the border. 
// size includes border as borader expands inward.
Border::Border(sf::Vector2f topleft, sf::Vector2f size, float thickness)
    : border(size)
{

    // determine the inner bounding box size.
    // THIS WILL JUST RETURN DIMENSIONS, does  not account for positon.
    auto bounding_box = border.getGlobalBounds();
    bounding_box.left += thickness + topleft.x;
    bounding_box.width = bounding_box.width - thickness + topleft.x;
    bounding_box.height = bounding_box.height - thickness + topleft.y;
    bounding_box.top += thickness + topleft.y;
    inner_container = bounding_box;

    border.setFillColor(sf::Color::Black);
    border.setPosition(topleft);
    border.setOutlineThickness(-thickness);
    border.setOutlineColor(sf::Color::Black);



}

sf::Rect<float> Border::GetRect() const
{
    return inner_container;
}

void Border::Display(sf::RenderWindow& window) const
{
    window.draw(border);
}

