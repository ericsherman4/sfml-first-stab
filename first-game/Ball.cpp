#include "Ball.h"
#include "math.h"
#include "assert.h"

// has to be a vector so cant use grav const directly
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
    static const float height = CONFIG_BORDER_BOTTOM;
    static const float width = CONFIG_BORDER_RIGHT;
    static const float top = CONFIG_BORDER_TOP;
    static const float left = CONFIG_BORDER_LEFT;
    // down the screen is positive. very annoying
    // but right is default positive.
    // invert y calculation and only y calculation. x is fine.
    assert(initialized == true);
    const sf::Vector2 vel = curr_pos - prev_pos;
    prev_pos = curr_pos;
    curr_pos = curr_pos + vel + GRAV * dt * dt;

    if ((curr_pos.y + RADIUS) > height)
    {
        curr_pos.y = height - RADIUS;
    }
    else if ((curr_pos.y - RADIUS) < top)
    {
        curr_pos.y = top + RADIUS;
    }

    if ((curr_pos.x + RADIUS) > width)
    {
        curr_pos.x = width - RADIUS;
    }
    else if ((curr_pos.x - RADIUS) < left)
    {
        curr_pos.x = left + RADIUS;
    }
}

void Ball::TestCollision(Ball * other_ball)
{
    assert(initialized == true);
    sf::Vector2f diff = other_ball->curr_pos - curr_pos;
    float length_sq = diff.x * diff.x + diff.y * diff.y;
    static const float DIAMETER_SQ = RADIUS * 4 * RADIUS;
    static const float DIAMETER = 2 * RADIUS;
    assert(length >= 0.f);
    //if (length_sq < (DIAMETER_SQ -4) ) // fizzy version
    if(length_sq < (DIAMETER_SQ +7)) // merging version
    {
        //ball.setFillColor(sf::Color::Green);
        // diff is from center to center.
        // want the ball to move 2*radius - diff backwards.
        // 2*radius - diff in vector form.
        // direction is opposite of diff.

        const float length = sqrt(length_sq);

        sf::Vector2f normalized_diff( diff / length);
        normalized_diff *= (DIAMETER - length)/2.f;
        curr_pos = curr_pos -  normalized_diff;
        other_ball->curr_pos = other_ball->curr_pos + normalized_diff;

    }
}

bool Ball::GetInitialized()
{
    return initialized;
}



