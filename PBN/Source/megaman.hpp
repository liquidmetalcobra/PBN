/* megaman_hpp */
//
//  megaman.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

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
#include "pokemon.hpp"
class megaman : public pokemon
{
public:
    megaman(std::string n, float iY, int iSize, float iDX, float iDY)
    {
        name = n;
    //    std::cout << "MEGAMAN";
    };
    ~megaman()
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