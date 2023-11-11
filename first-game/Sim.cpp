#include "Sim.h"


Sim::Sim()
    : window(sf::VideoMode(1920, 1080), "First Game!"),
    test(),
    border({ 0,0 }, { 400,600 }, 20.f),
    FRAME_TIME(sf::seconds(1.f / 60.f))
{
    window.setVerticalSyncEnabled(true);
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
            }
    
        }
    }
}

void Sim::Update(sf::Time dt)
{
    test.Update(dt);

}

void Sim::Display()
{
    window.clear();

    border.Display(window);
    test.Display(window);
    
    window.display();
}
