#include "Sim.h"



Sim::Sim()
    : window(sf::VideoMode(700, 900), "First Game!"),
    border({ 0,300 }, { 700.f,600.f }, 5.0f),
    FRAME_TIME(sf::seconds(1.f / 60.f)),
    spawn_clock(0.f),
    active_ball_count(0),
    color()
{

}

void Sim::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    spawn_clock = timeSinceLastUpdate.asSeconds();
    // TODO: there is an even better way than this but implementation dependent
    // https://gafferongames.com/post/fix_your_timestep/
    // TODO: substepping?? see the brick game part 3.  
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() > FRAME_TIME.asSeconds() * 4)
        {   
            int count = 0;
            while (true)
            {
                count++;
            }

        }
        while (timeSinceLastUpdate > FRAME_TIME)
        {
            timeSinceLastUpdate -= FRAME_TIME;
            ProcessEvents();
            Update(FRAME_TIME.asSeconds());
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

void Sim::Update(float dt)
{
    if (NUM_BALLS == 1)
    {
        balls[0].Update(dt);
        balls[0].TestCollision(border);
        return;
    }

    const int NUM_ROWS = 8;
    if (spawn_clock > 0.1 && active_ball_count < (NUM_BALLS - NUM_ROWS))
    {
        for (int i = 0; i < NUM_ROWS; i++)
        {
            color.Run();
            balls[active_ball_count++].Init(
                { 20.f    , 10.f + (i * Ball::RADIUS * 3.f) },
                { 20.f - 4.f, 10.f + (i * Ball::RADIUS * 3.f) - 3.f },
                color.GetColor());
        }
        spawn_clock = 0;
    }

    for (Ball& b : balls)
    {
        // Doing in order. So if its not initialized, just ignore the rest.
        if (!b.GetInitialized())
        {
            break;
        }

        b.Update(dt);
        for (Ball& bb : balls)
        {
            // Doing in order. So if its not initialized, just ignore the rest.
            if (!bb.GetInitialized())
            {
                break;
            }
            if (&b != &bb)
            {
                b.TestCollision(bb);
            }
        }
        //TODO:
        //TODO:
        //TODO:
        b.TestCollision(border); //PLAY AROUND WITH THIS. SHOULD IT BE ON THE INSIDE?
        // It was on the inside after test collision originally I think. Or it may have been before.
    }

    spawn_clock += dt;
}

void Sim::Display()
{
    window.clear();

    border.Display(window);

    for (Ball& b : balls)
    {
        if (!b.GetInitialized())
        {
            break;
        }
        b.Display(window);
    }
    
    window.display();
}
