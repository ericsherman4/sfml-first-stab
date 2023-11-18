#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Border.h"
#include "ColorSM.h"
#include "Config.h"
#include "Statistics.h"

class Sim
{
private:
    void ProcessEvents();
    void Update(float dt);
    void Display();
public:
    Sim();
    void Run();
private:

    static constexpr int NUM_BALLS = CONFIG_MAX_BALLS;

    const sf::Time FRAME_TIME;
    float spawn_clock;
    int active_ball_count;
    ColorSM color;
    sf::RenderWindow window; 
    Ball balls[NUM_BALLS];
    Border border;
    Statistics stat;
};

