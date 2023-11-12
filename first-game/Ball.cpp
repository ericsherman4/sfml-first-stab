#include "Ball.h"
#include "math.h"


Ball::Ball(sf::Vector2f vel_in, sf::Vector2f center_pos)
    : Ball(vel_in, center_pos, sf::Color::White)
{
}


Ball::Ball(sf::Vector2f vel_in, sf::Vector2f center_pos, sf::Color color)
{
    ball.setRadius(RADIUS);
    ball.setFillColor(color);

    // set the origin to be the center
    // passed in value is offset from top left corner.
    ball.setOrigin({RADIUS, RADIUS});

    vel = vel_in;

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
    vel.x += PIXELS_PER_METER * dt.asSeconds();
    pos += vel * dt.asSeconds();
    ball.setPosition(pos);

}

void Ball::TestCollision(const Border& border)
{
    auto box = border.GetRect();
    if ((box.height - pos.y) <= RADIUS)
    {
        pos.y = box.height - RADIUS;
        ball.setPosition(pos);
        ball.setFillColor(sf::Color::Red);
    }
    if (box.width - pos.x <= RADIUS)
    {
        pos.x = box.width - RADIUS;
        ball.setPosition(pos);
        ball.setFillColor(sf::Color::Yellow);
    }
}

void Ball::TestCollision(Ball& other_ball)
{
    sf::Vector2f diff = other_ball.pos - pos;
    float length = sqrt(diff.x * diff.x + diff.y * diff.y);
    const float DOUBLE_RAD = RADIUS * 2;
    if (length < DOUBLE_RAD)
    {
        ball.setFillColor(sf::Color::Green);
        // diff is from center to center.
        // want the ball to move 2*radius - diff backwards.
        // 2*radius - diff in vector form.
        // direction is opposite of diff.
        sf::Vector2f normalized_diff( diff / length);
        normalized_diff *= (DOUBLE_RAD - length)/2.f;
        pos = pos -  normalized_diff;
        other_ball.pos = other_ball.pos + normalized_diff;

        ball.setPosition(pos);
    }
}



