#pragma once
#include "Ball.h"
#include "Unit.h"
#include "SFML/Graphics.hpp"
class Grid
{
public:
    Grid(int width, int height, int radius);
    int GetGridPos(const sf::Vector2f& pos);
    int GetGridPos(int x, int y);
    sf::Vector2i GetGridPosVect(const sf::Vector2f& pos);
    void Add(Ball * ball);
    void Clear();
    void FindCollisions();    

private:

    void CheckCellsCollisions(Unit& unit_1, Unit& unit_2);

    const int DIAMETER;
    const int WIDTH;
    const int HEIGHT;
    const int LENGTH;
    Unit * grid;
};

