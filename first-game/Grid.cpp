#include "Grid.h"
#include "assert.h"

Grid::Grid(int width, int height, int radius)
    : WIDTH(width/radius)
    , HEIGHT(height/radius)
    , RADIUS(radius)
    , LENGTH ( WIDTH * HEIGHT)
{
    grid = new Unit[LENGTH];
}

int Grid::GetGridPos(const sf::Vector2f& pos)
{
    int arr_pos = static_cast<int>(pos.y) / RADIUS * WIDTH 
        + (static_cast<int>(pos.x) / RADIUS);



    assert(arr_pos < LENGTH);
    return arr_pos;
}

void Grid::Add(Ball * ball)
{
    
    grid[GetGridPos(ball->curr_pos)].Add(ball);

}

void Grid::Clear()
{
    for (int i{ 0 }; i < LENGTH; i++)
    {
        grid[i].size = 0;
    }
}
