#pragma once
#include <SFML/Graphics.hpp>

class Sim
{
private:
    
    void ProcessEvents();
    void UpdateModel();
    void Display();
public:
    Sim();
    void Run();
private:
    sf::RenderWindow window; 
    sf::CircleShape player;
};

