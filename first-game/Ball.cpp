#include "Ball.h"


Ball::Ball()
    : Ball(5.f, { 50, 50.f }, sf::Color::White)
{
}

Ball::Ball(float radius_in, sf::Vector2f center_pos, sf::Color color)
{
    ball.setRadius(radius_in);
    ball.setFillColor(color);

    const sf::Vector2 rad_vec(radius_in, radius_in);

    // set the origin to be the center
    // passed in value is offset from top left corner.
    ball.setOrigin(rad_vec);

    vel.x = 100.0f;
    vel.y = 50.0f;

    // Update position
    pos = center_pos;
    ball.setPosition(pos);

    radius = radius_in;

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
    auto box = border.GetRect();
    if ((box.height - pos.y) <= radius)
    {
        pos.y = box.height - radius;
        ball.setPosition(pos);
        ball.setFillColor(sf::Color::Red);
    }
    if (box.width - pos.x <= radius)
    {
        pos.x = box.width - radius;
        ball.setPosition(pos);
        ball.setFillColor(sf::Color::Yellow);
    }
}



