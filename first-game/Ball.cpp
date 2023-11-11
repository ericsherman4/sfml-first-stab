#include "Ball.h"
#include "math.h"


Ball::Ball()
    : Ball(30.f, { 50, 50.f }, sf::Color::White)
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

void Ball::TestCollision(const Ball& other_ball)
{
    static const float double_radius2 = 4 * radius * radius;
    sf::Vector2f diff = other_ball.pos - pos;
    float length_sq = diff.x * diff.x + diff.y * diff.y;
    if (length_sq < double_radius2)
    {
        ball.setFillColor(sf::Color::Green);
        // diff is from center to center.
        // want the ball to move 2*radius - diff backwards.
        // 2*radius - diff in vector form.
        // direction is opposite of diff.
        sf::Vector2f normalized_diff( diff / sqrt(length_sq));
        normalized_diff *= -(2*radius - sqrt(length_sq));
        pos = pos + normalized_diff;
        
        ball.setPosition(pos);
    }
}



