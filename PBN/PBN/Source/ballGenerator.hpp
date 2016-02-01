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
#include "gameobject.hpp"
#include "bouncer.hpp"
#include "collider.hpp"
#include <vector>

class ballGenerator
{
public:
    ballGenerator(float iX, float iY,collider* c, std::vector<bouncer *>* v)
    {
        
        resetCount = 0;
        colliderPointer = c;
        bouncerVector = v;
        x = iX;
        y = iY;
        
        
    };
    ~ballGenerator()
    {
  
    };
    
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
    
    
private:
    float x;
    float y;
    std::vector<bouncer *>* bouncerVector;
    collider* colliderPointer;
    int resetCount;
};