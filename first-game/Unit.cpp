#include "Unit.h"
#include "assert.h"

Unit::Unit()
    : size(0)
{
}

void Unit::Add(Ball* ball)
{
    assert(MAX_SIZE >= (size + 1));
    unit[size++] = ball;
}
