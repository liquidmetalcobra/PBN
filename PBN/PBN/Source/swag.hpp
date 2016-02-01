//
//  swag.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef swag_hpp
#define swag_hpp

#include <stdio.h>

#endif /* swag_hpp */
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
#include "animator.hpp"
#include "pokemon.hpp"
#include "move.hpp"

class swag : public move
{
public:
    swag(std::string n, pokemon * own, pokemon *op, int orient,float newX, float newY)
    {
        
        start(n,own,op,orient,newX,newY);
        damage = 10;
        moving = 0;
    };
    swag()
    {

        isDead = false;
    };
    ~swag()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject *go);
    void update();
    void draw();
    
    void parse(char * filename);
protected:
    bool moving;
   
   
private:
    
    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};