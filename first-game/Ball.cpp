#include "Ball.h"


Ball::Ball()
    : Ball(15.f, { 0.f, 0.f }, sf::Color::White)
{
}

Ball::Ball(float radius, sf::Vector2f position, sf::Color color)
{
    ball.setRadius(radius);
    ball.setPosition(position);
    ball.setFillColor(color);

}

void Ball::Display(sf::RenderWindow& window)
{
    window.draw(ball);
}

void Ball::Update(sf::Time dt)
{
    // meter space
    vel.y += -9.8f * dt.asSeconds();

    // down the screen is positive. very annoying
    // invert pos update to fix?
    pos -= vel * dt.asSeconds();

    // pixel space?
    ball.setPosition(pos * PIXELS_PER_METER);

}



