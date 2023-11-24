#pragma once

#include <SFML/Graphics.hpp>

class Statistics
{
public:
    Statistics();
    void Display(sf::RenderWindow& win);
    void CalculateStats(float dt, int ball_count);
    void Log_Clock();
private:
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    float sim_time;
    float update_time;
};

