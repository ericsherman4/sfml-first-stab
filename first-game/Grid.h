#pragma once
#include "Ball.h"
#include "Unit.h"
#include "SFML/Graphics.hpp"
#include "Border.h"
class Grid
{
public:
    Grid(int width, int height, int radius, Border &border_in);
    int GetGridPos(const sf::Vector2f& pos);
    int GetGridPos(int x, int y);
    sf::Vector2i GetGridPosVect(const sf::Vector2f& pos);
    void Add(Ball * ball);
    void Clear();
    void FindCollisions();


    // is it possible for multiple balls to be in the same grid position. 
    // yes totally possible. so this strategy wont work. 
    // can do something like the article. which we have another data structure for the cell unit.

    //could also store ball IDs instead of the object itself but honestly no i think storing the object is better
    // gonna have to learn dynamic memory alloc probably.


    

private:

    void CheckSurroundingCells(int x_in, int y_in);
    void CheckCellsCollisions(Unit& unit_1, Unit& unit_2);

    const int DIAMETER;
    const int WIDTH;
    const int HEIGHT;
    const int LENGTH;
    Unit * grid;
    Border& border;

};

