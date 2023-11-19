#pragma once
#include "Ball.h"

class Unit
{
public:
    Unit();
    void Add(Ball * ball);
    
    static constexpr int MAX_SIZE =  10;
    // array of ball pointers
    Ball* unit[MAX_SIZE];
    int size;
};

