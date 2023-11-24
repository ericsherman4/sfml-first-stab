#include "Sim.h"
#include "assert.h"



Sim::Sim()
    : window(sf::VideoMode(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT), "Balls on Balls on Balls"),
    FRAME_TIME(sf::seconds(CONFIG_60FPS)),
    spawn_clock(0.f),
    active_ball_count(0),
    color(),
    stat(),
    grid(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT, static_cast<int>(CONFIG_BALL_RADIUS))
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

            stat.Log_Clock();
            for (int i = 0; i < CONFIG_NUM_SUBSTEPS; ++i)
            {
                Update(FRAME_TIME.asSeconds() / static_cast<float>(CONFIG_NUM_SUBSTEPS));
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

    for (int i{ 0 }; i < active_ball_count; ++i)
    {
        balls[i].Update(dt);
    }

    grid.Clear();

    for (int i{ 0 }; i < active_ball_count; ++i)
    {
        //sf::Vector2i test(grid.GetGridPosVect(balls[i].curr_pos));
        //if (!(test.x == 0
        //    || test.x == (CONFIG_VIDEO_WIDTH / CONFIG_BALL_RADIUS / 2)
        //    || test.y == 0
        //    || test.y == (CONFIG_VIDEO_HEIGHT / CONFIG_BALL_RADIUS / 2)))
        //{
            grid.Add(&balls[i]);
        //}
    }
    grid.FindCollisions();


    spawn_clock += dt;
}

void Sim::Display()
{
    window.clear();

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
    if (spawn_clock > 0.1f && active_ball_count < (CONFIG_MAX_BALLS - CONFIG_NUM_BALL_SOURCES))
    {
        for (int i = 0; i < CONFIG_NUM_BALL_SOURCES; i++)
        {
            color.Run();
            const float y_pos = CONFIG_SPAWN_START_Y + (i * Ball::RADIUS * CONFIG_SPAWN_Y_SPACING_FACTOR);
            balls[active_ball_count++].Init(
                { CONFIG_SPAWN_START_X - (i * 0.1f), CONFIG_SPAWN_START_Y + y_pos },
                { CONFIG_SPAWN_START_X - (i * 0.1f) - CONFIG_SPAWN_X_VEL,
                    CONFIG_SPAWN_START_Y + y_pos - CONFIG_SPAWN_Y_VEL },
                color.GetColor());
        }
        spawn_clock = 0;
    }
}
