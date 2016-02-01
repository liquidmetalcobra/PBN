//
//  ballGenerator.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/12/16.
//
//

#include "ballGenerator.hpp"


void ballGenerator::update()
{
    if (resetCount == 0)
    {
        resetCount = 60;
        bouncer * b = new bouncer(x,y,10,0,10);
        bouncerVector->push_back(b);
        colliderPointer->add(b);
    }
    else
    {
        resetCount--;
    }
    
}
void ballGenerator::draw()
{
    
}
void ballGenerator::init()
{
    
}
