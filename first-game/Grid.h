#pragma once
#include "Ball.h"
class Grid
{
public:
    Grid(float width, float height, float radius);

    void Add(Ball* grid);
    void HandleCollisions();

    // is it possible for multiple balls to be in the same grid position. 
    // yes totally possible. so this strategy wont work. 
    // can do something like the article. which we have another data structure for the cell unit.

    //could also store ball IDs instead of the object itself but honestly no i think storing the object is better
    // gonna have to learn dynamic memory alloc probably.

private:
    Ball** grid;

};

