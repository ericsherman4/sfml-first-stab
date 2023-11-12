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
    
    const sf::Time FRAME_TIME;
    sf::RenderWindow window; 
    Ball ball1;
    Ball ball2;
    Border border;
};

