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
#include <typeinfo>

class bouncer : public gameobject
{
    public:
    bouncer(float iX, float iY, int iSize, float iDX, float iDY)
    {
        resetCount = 0;
        setSize(iSize);
        setX(iX);
        setY(iY);
        dx  = iDX;
        dy = iDY;
        setID(1);
        
        b = al_create_bitmap(size, size);
        if(!b) {
            fprintf(stderr, "failed to create bouncer bitmap!\n");
        }
        
        al_set_target_bitmap(b);
        
        al_clear_to_color(al_map_rgb(255, 0, 255));
        markForDeath = false;
    };
    bouncer()
    {
        bouncer(20,20,32,4,4);
    }
    ~bouncer()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
   

private:
    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};