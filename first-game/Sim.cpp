#include "Sim.h"
#include "assert.h"


Sim::Sim()
    : window(sf::VideoMode(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT), "Balls on Balls on Balls"),
    FRAME_TIME(sf::seconds(CONFIG_60FPS)),
    spawn_clock(0.f),
    active_ball_count(0),
    color(),
    stat(),
    grid(CONFIG_VIDEO_WIDTH, CONFIG_VIDEO_HEIGHT, static_cast<int>(CONFIG_BALL_RADIUS)),
    fps_limit_reached(false)
{
    balls = new Ball[CONFIG_MAX_BALLS]();
    window.setPosition({ 100, 0 });
}

void Sim::Run()
{
    sf::Clock clock;
    sf::Clock clock2;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    spawn_clock = timeSinceLastUpdate.asSeconds();
    // TODO: there is an even better way than this but implementation dependent
    // https://gafferongames.com/post/fix_your_timestep/
    // TODO: substepping?? see the brick game part 3.  

    const float FPS_LIMIT = CONFIG_FPS_LIMIT;
    const float update_dt = FRAME_TIME.asSeconds() / static_cast<float>(CONFIG_NUM_SUBSTEPS);
    const float frame_time_as_seconds = FRAME_TIME.asSeconds();

    int num_over = 0;

    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate.asSeconds() > FPS_LIMIT)
        {   
            fps_limit_reached = (++num_over) > 30;
        }
        while (timeSinceLastUpdate > FRAME_TIME)
        {
            stat.Log_Clock();
            ProcessEvents();

            for (int i = 0; i < CONFIG_NUM_SUBSTEPS; ++i)
            {
                Update(update_dt);
            }
            stat.Log_Clock();
            stat.CalculateStats(clock2.restart().asSeconds(), active_ball_count);
            timeSinceLastUpdate -= FRAME_TIME;
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
    if(spawn_clock > 0.1f && !fps_limit_reached && active_ball_count < (CONFIG_MAX_BALLS - CONFIG_NUM_BALL_SOURCES))
    {
        SpawnBalls();
    }

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

    for (int i{ 0 }; i < active_ball_count; ++i)
    {
        balls[i].Display(window);
    }
    
    window.display();
}

void Sim::SpawnBalls()
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
