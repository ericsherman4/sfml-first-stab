#include "Ball.h"


Ball::Ball()
    : Ball(50.f, { 50, 50.f }, sf::Color::White)
{
}

Ball::Ball(float radius, sf::Vector2f center_pos, sf::Color color)
{
    ball.setRadius(radius);
    ball.setFillColor(color);

    const sf::Vector2 rad_vec(radius, radius);

    // set the origin to be the center
    // passed in value is offset from top left corner.
    ball.setOrigin(rad_vec);

    // Update position
    pos = center_pos;
    ball.setPosition(pos);

}

void Ball::Display(sf::RenderWindow& window)
{
    window.draw(ball);
}

void Ball::Update(sf::Time dt)
{
    // down the screen is positive. very annoying
    // but right is default positive.
    // invert y calculation and only y calculation. x is fine.
    vel.y -= -9.8f * PIXELS_PER_METER * dt.asSeconds();
    pos += vel * dt.asSeconds();
    ball.setPosition(pos);

}

void Ball::TestCollision(const Border& border)
{
    //if()
    
}



