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
class tile : public gameobject
{
public:
    tile(float iX, float iY, int iSize)
    {
        resetCount = 0;
        setID(1);
        setX(iX);
        setY(iY);
        setSize(iSize);
        
        b = al_create_bitmap(size, size);
        if(!b) {
            fprintf(stderr, "failed to create tile bitmap!\n");
        }
        
        al_set_target_bitmap(b);
        
        al_clear_to_color(al_map_rgb(10, 120, 255));
        markForDeath = false;
    };
    tile()
    {
        tile(20,20,32);
    };
    ~tile()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
    
    
private:
  
    ALLEGRO_BITMAP *b;
    int resetCount;
};