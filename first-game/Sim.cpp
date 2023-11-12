#include "Sim.h"


Sim::Sim()
    : window(sf::VideoMode(1920, 1080), "First Game!"),
    ball1(30, { 119, 15 }, sf::Color::Magenta),
    ball2(30, {120, 50}, sf::Color::White),
    border({ 100,100 }, { 400.f,600.f }, 5.0f),
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
    ball1.Update(dt);
    ball2.Update(dt);
    ball1.TestCollision(border);
    ball2.TestCollision(border);
    ball1.TestCollision(ball2);

}

void Sim::Display()
{
    window.clear();

    border.Display(window);
    ball1.Display(window);
    ball2.Display(window);
    
    window.display();
}
