#include "Grid.h"

Grid::Grid(float width, float height, float radius)
{
    grid = new Ball* [width * height];
}
