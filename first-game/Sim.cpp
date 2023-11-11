#include "Sim.h"


Sim::Sim()
    : window(sf::VideoMode(1920, 1080), "First Game!"),
    player(),
    pos(INIT_X, INIT_Y),
    vel(-10,3)
{
    player.setRadius(20.f);
    player.setPosition(pos);
    player.setFillColor(sf::Color::Magenta);

    isMovingUp = isMovingDown = isMovingRight = isMovingLeft = false;
}

void Sim::Run()
{
    while (window.isOpen())
    {
        ProcessEvents();
        UpdateModel();
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

void Sim::UpdateModel()
{
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingDown)
    {
        movement.y += 0.5f;
    }
    if (isMovingRight)
    {
        movement.x += 0.5f;
    }
    if (isMovingLeft)
    {
        movement.x -= 0.5f;
    }
    if (isMovingUp)
    {
        movement.y -= 0.5f;
    }
    player.move(movement);

}

void Sim::Display()
{
    window.clear();
    window.draw(player);
    window.display();
}
