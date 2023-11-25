#include "Statistics.h"
#include  "Config.h"

Statistics::Statistics()
    : text()
    , update_time(0.f)
    , font()
    , clock()
    , sim_time(0.f)
{
    font.loadFromFile("Sansation.ttf");
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(CONFIG_FONT_SIZE_PIX);
    text.setFillColor(sf::Color::White);
}

void Statistics::Display(sf::RenderWindow& win)
{
    win.draw(text);
}

void Statistics::CalculateStats(float dt, int ball_count)
{
    //update time is how fast to update the display
    update_time += dt;
    if (update_time > CONFIG_STATISTICS_PRINT_INTERVAL)
    {
        text.setString(
            "Sim Time: " + std::to_string(sim_time) 
            + "\nBall Count: " + std::to_string(ball_count)
        );
        update_time -= CONFIG_STATISTICS_PRINT_INTERVAL;
    }
}

void Statistics::Log_Clock()
{
    sim_time = clock.restart().asSeconds();
}
