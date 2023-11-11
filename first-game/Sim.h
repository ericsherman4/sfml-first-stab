#pragma once
#include <SFML/Graphics.hpp>

class Sim
{
private:
    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void ProcessEvents();
    void UpdateModel();
    void Display();
public:
    Sim();
    void Run();
private:

    static constexpr float INIT_X = 500.f;
    static constexpr float INIT_Y = 500.f;

    sf::RenderWindow window; 
    sf::CircleShape player;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
    sf::Vector2f pos;
    sf::Vector2f vel;
};

