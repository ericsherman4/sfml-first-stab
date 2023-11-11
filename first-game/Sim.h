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

    static constexpr float INIT_X = 500.f;
    static constexpr float INIT_Y = 500.f;
    static constexpr float SPEED = 50.f;
    
    const sf::Time FRAME_TIME;
    sf::RenderWindow window; 
    Ball ball1;
    Border border;
};

