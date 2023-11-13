#pragma once
#include <SFML/Graphics.hpp>

class ColorSM
{
public:
    ColorSM();

    void Run();

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
    static constexpr float speed = 0.3f;

    float r;
    float g;
    float b;
};

