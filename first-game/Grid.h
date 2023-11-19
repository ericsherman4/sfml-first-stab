#pragma once
#include "Ball.h"
#include "Unit.h"
#include "SFML/Graphics.hpp"
class Grid
{
public:
    Grid(int width, int height, int radius);
    int GetGridPos(const sf::Vector2f& pos);
    void Add(Ball * ball);
    void Clear();


    // is it possible for multiple balls to be in the same grid position. 
    // yes totally possible. so this strategy wont work. 
    // can do something like the article. which we have another data structure for the cell unit.

    //could also store ball IDs instead of the object itself but honestly no i think storing the object is better
    // gonna have to learn dynamic memory alloc probably.


    

private:
    const int WIDTH;
    const int HEIGHT;
    const int RADIUS;
    const int LENGTH;
    Unit * grid;

};

