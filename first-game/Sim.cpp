#include "Sim.h"


Sim::Sim()
    : window(sf::VideoMode(1920, 1080), "First Game!"),
    player(),
    pos(INIT_X, INIT_Y),
    vel(-10,3),
    FRAME_TIME(sf::seconds(1.f / 60.f))
{
    window.setVerticalSyncEnabled(true);

    player.setRadius(20.f);
    player.setPosition(pos);
    player.setFillColor(sf::Color::Magenta);

    isMovingUp = isMovingDown = isMovingRight = isMovingLeft = false;
}

void Sim::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    // TODO: there is an even better way than this but implementation dependent
    // https://gafferongames.com/post/fix_your_timestep/
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > FRAME_TIME)
        {
            timeSinceLastUpdate -= FRAME_TIME;
            ProcessEvents();
            Update(FRAME_TIME);
        }
        Display();
    }
}

void Sim::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

    switch (key)
    {
        case sf::Keyboard::Key::W:
            isMovingUp = isPressed;
            break;
        case sf::Keyboard::Key::A:
            isMovingLeft = isPressed;
            break;
        case sf::Keyboard::Key::S:
            isMovingDown = isPressed;
            break;
        case sf::Keyboard::Key::D:
            isMovingRight = isPressed;
            break;
    }

}

void Sim::ProcessEvents()
{
    if (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    HandlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    HandlePlayerInput(event.key.code, false);
                    break;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void Sim::Update(sf::Time dt)
{
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingDown)
    {
        movement.y += SPEED;
    }
    if (isMovingRight)
    {
        movement.x += SPEED;
    }
    if (isMovingLeft)
    {
        movement.x -= SPEED;
    }
    if (isMovingUp)
    {
        movement.y -= SPEED;
    }
    player.move(movement * dt.asSeconds());

}

void Sim::Display()
{
    window.clear();
    window.draw(player);
    window.display();
}
