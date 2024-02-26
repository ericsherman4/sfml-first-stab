#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"

class ColorSM
{
public:
    ColorSM();

    void Run();
    sf::Color GetColor();

private: 
    enum class State
    {
        RISING_G,
        FALLING_R,
        RISING_B,
        FALLING_G,
        RISING_R,
        FALLING_B
    };

    State curr_state;
    State next_state;

public:

    float r;
    float g;
    float b;
};

