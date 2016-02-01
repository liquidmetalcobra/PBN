//
//  gameobject.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/13/16.
//
//

#ifndef gameobject_hpp
#define gameobject_hpp

#include <stdio.h>

#endif /* gameobject_hpp */
#pragma once
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
//#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "globals.h"

class gameobject
{
public:
    gameobject()
    {
        this->x = 200;
        this->y = 200;
        this->size = 100;
        this->id = 0;
        markForDeath = false;
    };

    ~gameobject(){};
    
    virtual void collide(gameobject *go);
    virtual void update();
    virtual void init();
    virtual void draw();
    
    float getX() { return x; }
    float getY() { return y; }
    int getID() { return id; }
    int getSize() { return this->size; }
    
    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    void setID(float newID) { id = newID; }
    void setSize(int newSize) { size = newSize; }

    bool markForDeath;
    
protected:
    float x;
    float y;
    int size;
    int id;
    int resetCount;
    
};