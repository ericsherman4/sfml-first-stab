#include "Ball.h"
#include "math.h"
#include "assert.h"

const sf::Vector2f Ball::GRAV(0.0f, CONFIG_GRAV_CONST);

Ball::Ball()
    : initialized(false),
    ball() // circleshape object
{

}

void Ball::Init(sf::Vector2f center_pos, sf::Vector2f prev_pos_in, sf::Color color)
{
    if (!initialized)
    {
        ball.setRadius(RADIUS);
        ball.setFillColor(color);
        //ball.setOutlineThickness(2);
        //ball.setOutlineColor(sf::Color::Red);

        // set the origin to be the center
        // passed in value is offset from top left corner.
        ball.setOrigin({ RADIUS, RADIUS });


        // Update position
        curr_pos = center_pos;
        prev_pos = prev_pos_in;

        initialized = true;
    }
}

void Ball::Display(sf::RenderWindow& window)
{
    assert(initialized == true);
    ball.setPosition(curr_pos);
    window.draw(ball);
}

void Ball::Update(float dt)
{
    // down the screen is positive. very annoying
    // but right is default positive.
    // invert y calculation and only y calculation. x is fine.
    assert(initialized == true);
    const sf::Vector2 vel = curr_pos - prev_pos;
    prev_pos = curr_pos;
    curr_pos = curr_pos + vel + GRAV * dt * dt;

}

void Ball::TestCollision(const Border& border)
{
    assert(initialized == true);
    auto box = border.GetRect();
    if ((box.height - curr_pos.y) < RADIUS)
    {
        curr_pos.y = box.height - RADIUS;
        //ball.setFillColor(sf::Color::Red); 
    }
    else
    {
        //ball.setFillColor(sf::Color::White); //this function added so much damn lag.
        // could make thing to just check if its already white and if so then dont assign.
    }
    if (box.width - curr_pos.x < RADIUS)
    {
        curr_pos.x = box.width - RADIUS;
        //ball.setFillColor(sf::Color::Yellow);
    }
    else if (curr_pos.x - box.left < RADIUS)
    {
        curr_pos.x = box.left + RADIUS;
        //ball.setFillColor(sf::Color::Yellow);
    }
    else
    {
        //ball.setFillColor(sf::Color::White); //this one too
    }
}

void Ball::TestCollision(Ball& other_ball)
{
    assert(initialized == true);
    sf::Vector2f diff = other_ball.curr_pos - curr_pos;
    float length = sqrt(diff.x * diff.x + diff.y * diff.y);
    const float DOUBLE_RAD = RADIUS * 2;
    if (length < DOUBLE_RAD)
    {
        //ball.setFillColor(sf::Color::Green);
        // diff is from center to center.
        // want the ball to move 2*radius - diff backwards.
        // 2*radius - diff in vector form.
        // direction is opposite of diff.
        sf::Vector2f normalized_diff( diff / length);
        normalized_diff *= (DOUBLE_RAD - length)/2.f;
        curr_pos = curr_pos -  normalized_diff;
        other_ball.curr_pos = other_ball.curr_pos + normalized_diff;

    }
}

bool Ball::GetInitialized()
{
    return initialized;
}



