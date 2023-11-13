#include "Sim.h"
#include "ColorSM.h"


Sim::Sim()
    : window(sf::VideoMode(500, 900), "First Game!"),
    border({ 0,300 }, { 500.f,600.f }, 5.0f),
    FRAME_TIME(sf::seconds(1.f / 60.f))
{
    int height = 0;
    const int LEVEL_SIZE = NUM_BALLS / 2;
    const int LEFT_X_START = 10;
    ColorSM color;

    //window.setVerticalSyncEnabled(true);
    for (int i =0; i < NUM_BALLS; i++)
    {
        color.Run();
        if (i % LEVEL_SIZE == 0)
        {
            height = 0;
        }
        else
        {
            height++;
        }
        balls[i].Init(
            { LEFT_X_START + ((i / LEVEL_SIZE) * 20.f), 70.0f - (20.f * height) },
            { LEFT_X_START - 0.001f + ((i / LEVEL_SIZE) * 20.f), 68.0f - (20.f * height) },
            { static_cast<uint8_t>(color.r), static_cast<uint8_t>(color.g), static_cast<uint8_t>(color.b) });

    }
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
            Update(FRAME_TIME.asSeconds());
        }
        Display();

        //ProcessEvents();
        //Update(FRAME_TIME.asSeconds());
        //Display();
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

void Sim::Update(float dt)
{
    if (NUM_BALLS == 1)
    {
        balls[0].Update(dt);
        balls[0].TestCollision(border);
        return;
    }

    for (Ball& b : balls)
    {
        //TODO: the way this is handled right now means a position update
        // will put a bunch of balls into each other
        // and then by test collision with wall and border, all of them will be through the floor.
        b.Update(dt);
        for (Ball& bb : balls)
        {
            if (&b != &bb)
            {
                b.TestCollision(border);
                b.TestCollision(bb);
            }
        }
    }
}

void Sim::Display()
{
    window.clear();

    border.Display(window);

    for (Ball& b : balls)
    {
        b.Display(window);
    }
    
    window.display();
}
