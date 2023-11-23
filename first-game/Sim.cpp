#include "Sim.h"
#include "assert.h"



Sim::Sim()
    : window(sf::VideoMode(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT), "Balls on Balls on Balls"),
    border(CONFIG_BORDER_TOPLEFT, CONFIG_BORDER_DIM , CONFIG_BORDER_THICKNESS),
    FRAME_TIME(sf::seconds(CONFIG_60FPS)),
    spawn_clock(0.f),
    active_ball_count(0),
    color(),
    stat(),
    grid(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT, static_cast<int>(CONFIG_BALL_RADIUS), border)
{
    balls = new Ball[CONFIG_MAX_BALLS]();
    window.setPosition({ 100, 0 });
}

void Sim::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    spawn_clock = timeSinceLastUpdate.asSeconds();
    // TODO: there is an even better way than this but implementation dependent
    // https://gafferongames.com/post/fix_your_timestep/
    // TODO: substepping?? see the brick game part 3.  

    const float FPS_LIMIT = CONFIG_FPS_LIMIT;

    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() > FPS_LIMIT)
        {   
            //int count = 0;
            //while (true)
            //{
            //   count++;
            //}

        }
        while (timeSinceLastUpdate > FRAME_TIME)
        {
            timeSinceLastUpdate -= FRAME_TIME;
            ProcessEvents();

            stat.Log_Clock();
            const int substeps = 8;
            for (int i = 0; i < substeps; ++i)
            {
                Update(FRAME_TIME.asSeconds() / static_cast<float>(substeps));
            }
            stat.Log_Clock();
            stat.CalculateStats(FRAME_TIME.asSeconds(), active_ball_count);

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
    SpawnBalls();

#if 1
    // should just change this to num active balls you idiot
    for (int i{ 0 }; i < active_ball_count; ++i)
    {
        balls[i].Update(dt);
        balls[i].TestCollision(border);
    }

    grid.Clear();

    for (int i{ 0 }; i < active_ball_count; ++i)
    {
        sf::Vector2i test(grid.GetGridPosVect(balls[i].curr_pos));
        if (!(test.x == 0
            || test.x == (CONFIG_VIDEO_WIDTH / CONFIG_BALL_RADIUS / 2)
            || test.y == 0
            || test.y == (CONFIG_VIDEO_HEIGHT / CONFIG_BALL_RADIUS / 2)))
        {
            grid.Add(&balls[i]);
        }
    }
    grid.FindCollisions();


#else
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
                b.TestCollision(&bb);
            }
        }
        //TODO:
        //TODO:
        //TODO:
        b.TestCollision(border); //PLAY AROUND WITH THIS. SHOULD IT BE ON THE INSIDE?
        // It was on the inside after test collision originally I think. Or it may have been before.
    }

#endif 

    spawn_clock += dt;
}

void Sim::Display()
{
    window.clear();

    border.Display(window);
    stat.Display(window);

    for (int i{ 0 }; i < CONFIG_MAX_BALLS; ++i)
    {
        if (!balls[i].GetInitialized())
        {
            break;
        }
        balls[i].Display(window);
    }
    
    window.display();
}

void Sim::SpawnBalls()
{
    if (spawn_clock > 0.1 && active_ball_count < (CONFIG_MAX_BALLS - CONFIG_NUM_BALL_SOURCES))
    {
        for (int i = 0; i < CONFIG_NUM_BALL_SOURCES; i++)
        {
            color.Run();
            const float y_pos = CONFIG_SPAWN_START_Y + (i * Ball::RADIUS * CONFIG_SPAWN_Y_SPACING_FACTOR);
            balls[active_ball_count++].Init(
                { CONFIG_SPAWN_START_X, CONFIG_SPAWN_START_Y + y_pos },
                { CONFIG_SPAWN_START_X - CONFIG_SPAWN_X_VEL,
                    CONFIG_SPAWN_START_Y + y_pos - CONFIG_SPAWN_Y_VEL },
                color.GetColor());
        }
        spawn_clock = 0;
    }
}
