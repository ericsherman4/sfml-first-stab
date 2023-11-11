#include "Sim.h"


Sim::Sim()
    : window(sf::VideoMode(1920, 1080), "First Game!"),
    player()
{
    player.setRadius(100.f);
    player.setPosition(500.f, 500.f);
    player.setFillColor(sf::Color::Magenta);
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

void Sim::ProcessEvents()
{
    if (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void Sim::UpdateModel()
{

}

void Sim::Display()
{
    window.clear();
    window.draw(player);
    window.display();
}
