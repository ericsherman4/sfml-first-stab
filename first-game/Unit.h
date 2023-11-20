#pragma once
#include "Ball.h"

class Unit
{
public:
    Unit();
    void Add(Ball * ball);
    
    static constexpr int MAX_SIZE =  5;
    // array of ball pointers
    Ball* balls[MAX_SIZE];
    int size;
};

