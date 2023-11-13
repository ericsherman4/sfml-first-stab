#include "ColorSM.h"

ColorSM::ColorSM()
{
    r = 0;
    b = 255;
    g = 255;
    curr_state = State::FALLING_G;
    next_state = State::FALLING_G;
}

void ColorSM::Run()
{
    // https://stackoverflow.com/questions/5162458/fade-through-more-more-natural-rainbow-spectrum-in-hsv-hsb
    switch (curr_state)
    {
        case State::RISING_G:
            g += speed;
            if (g >= 255)
            {
                g = 255;
                next_state = State::FALLING_R;
            }
            break;
        case State::FALLING_R:
            r -= speed;
            if (r <= 0)
            {
                r = 0;
                next_state = State::RISING_B;
            }
            break;
        case State::RISING_B:
            b += speed;
            if (b >= 255)
            {
                b = 255;
                next_state = State::FALLING_G;
            }
            break;
        case State::FALLING_G:
            g -= speed;
            if (g <= 0)
            {
                g = 0;
                next_state = State::RISING_R;
            }
            break;
        case State::RISING_R:
            r += speed;
            if (r >= 255)
            {
                r = 255;
                next_state = State::FALLING_B;
            }
            break;
        case State::FALLING_B:
            b -= speed;
            if (b <= 0)
            {
                b = 0;
                next_state = State::RISING_G;
            }
            break;
    }

    curr_state = next_state;
}
