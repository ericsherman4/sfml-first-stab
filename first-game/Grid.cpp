#include "Grid.h"
#include "assert.h"

Grid::Grid(int width, int height, int radius, Border & border_in)
    : DIAMETER(radius*2)
    , WIDTH(width/ DIAMETER)
    , HEIGHT(height/ DIAMETER)
    , LENGTH ( WIDTH * HEIGHT)
    , border(border_in)
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
            CheckSurroundingCells(x, y);
        }
    }
}

void Grid::CheckSurroundingCells(int x_in, int y_in)
{
    Unit &current_cell = grid[GetGridPos(x_in, y_in)];

    if (current_cell.size >= 1)
    {
        int p = 0;
    }
    for (int y{ y_in +1 }; y >= y_in - 1; --y)
    {
        for (int x{ x_in -1 }; x <= x_in + 1; ++x)
        {
            Unit & other_cell = grid[GetGridPos(x, y)];
            CheckCellsCollisions(current_cell, other_cell);
        }
    }
}

void Grid::CheckCellsCollisions(Unit& unit_1, Unit& unit_2)
{
    for (int i{ 0 }; i < unit_1.size; ++i)
    {
        for (int j{ 0 }; j < unit_2.size; ++j)
        {
            if (unit_1.balls[i] != unit_2.balls[j])
            {
                unit_1.balls[i]->TestCollision(unit_2.balls[j]);
                // unit_1.balls[i]->TestCollision(border);
            }
        }
    }
}

