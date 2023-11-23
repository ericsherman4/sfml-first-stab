#include "Unit.h"
#include "assert.h"

Unit::Unit()
    : size(0)
    , balls() // what exactly is happening here?
{
}

void Unit::Add(Ball* ball)
{
    assert(MAX_SIZE > size);
    balls[size++] = ball;
}
