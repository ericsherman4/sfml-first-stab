#include "Grid.h"
#include "assert.h"

Grid::Grid(int width, int height, int radius)
    : DIAMETER(radius*2)
    , WIDTH(width/ DIAMETER)
    , HEIGHT(height/ DIAMETER)
    , LENGTH ( WIDTH * HEIGHT)
{
    grid = new Unit[LENGTH];
}

int Grid::GetGridPos(const sf::Vector2f& pos)
{
    int arr_pos = static_cast<int>(pos.y / DIAMETER) * WIDTH
        + (static_cast<int>(pos.x / DIAMETER));


    assert(arr_pos < LENGTH);
    return arr_pos;
}

// NOTE THIS IS ALREADY IN GRID POSITIONS, NOT PIXEL POSITIONS
// FIXs
int Grid::GetGridPos(int x, int y)
{
    int arr_pos = y * WIDTH + x;
    assert(arr_pos < LENGTH);
    return arr_pos;
}

sf::Vector2i Grid::GetGridPosVect(const sf::Vector2f& pos)
{
    return sf::Vector2i(static_cast<int>(pos.x / DIAMETER), static_cast<int>(pos.y / DIAMETER));
}

void Grid::Add(Ball * ball)
{

    grid[GetGridPos(ball->curr_pos)].Add(ball);

}

void Grid::Clear()
{
    for (int i{ 0 }; i < LENGTH; ++i)
    {
        grid[i].size = 0;
    }
}

void Grid::FindCollisions()
{

    for (int y{ HEIGHT - 1 }; y > 0; --y)
    {
        for (int x{ 1 }; x < WIDTH - 1; ++x)
        {
            Unit &current_cell = grid[GetGridPos(x, y)];
            if (current_cell.size == 0)
            {
                continue;
            }

            // doing middle, then bottom, then top seemed to have fixed the problem inrerestingly enough
            // why...
            CheckCellsCollisions(current_cell, grid[GetGridPos(x, y - 1)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x, y)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x, y+1)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x -1 , y - 1)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x -1 , y)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x -1, y + 1)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x +1, y - 1)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x +1 , y)]);
            CheckCellsCollisions(current_cell, grid[GetGridPos(x + 1, y + 1)]);
        }
    }

}

void Grid::CheckCellsCollisions(Unit& unit_1, Unit& unit_2)
{
    if (unit_2.size == 0)
    {
        return;
    }

    for (int i{ 0 }; i < unit_1.size; ++i)
    {
        for (int j{ 0 }; j < unit_2.size; ++j)
        {
            if (unit_1.balls[i] != unit_2.balls[j])
            {
                unit_1.balls[i]->TestCollision(unit_2.balls[j]);
            }
        }
    }
}

