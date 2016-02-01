#pragma once
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
//#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "bouncer.hpp"
#include "globals.h"
#include <vector>
class collider
{
public:
    collider()
    {
    };
    ~collider(){};
    
    void update();
    void add(gameobject* a);
    void remove(gameobject * r);
    bool checkCollision(gameobject* a, gameobject* b);
    
private:
    std::vector<gameobject*> balls;
    
};