#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "ColorSM.h"
#include "Config.h"
#include "Statistics.h"
#include "Grid.h"

class Sim
{
private:
    void ProcessEvents();
    void Update(float dt);
    void Display();
    void SpawnBalls();
public:
    Sim();
    void Run();
private:

    const sf::Time FRAME_TIME;
    float spawn_clock;
    int active_ball_count;
    ColorSM color;
    sf::RenderWindow window; 
    Ball * balls;
    Statistics stat;
    Grid grid;
    bool fps_limit_reached;
};

