#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Border.h"

class Sim
{
private:
    void ProcessEvents();
    void Update(sf::Time dt);
    void Display();
public:
    Sim();
    void Run();
private:

    static constexpr int NUM_BALLS = 40;
    
    const sf::Time FRAME_TIME;
    sf::RenderWindow window; 
    Ball balls[NUM_BALLS];
    Border border;
};

