//
//  move.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef move_hpp
#define move_hpp

#include <stdio.h>

#endif /* move_hpp */
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

class move : public gameobject
{
public:
    move(std::string n, float iY, int iSize, float iDX, float iDY)
    {
    };
    move()
    {
        isDead = false;
    };
    ~move()
    {
    };
    
    void collide(gameobject *go);
//virtual void update();
    void start(std::string n,pokemon * own, pokemon *op, int orient,float newX, float newY);
  //  virtual void draw();
    
    void parse(char * filename);
     bool isDead;
protected:
   
    int orientation;
    pokemon *owner;
    pokemon *opponent;
    animator anim;
    std::string name;
    int id;
    int damage;
    int debuffs;
    int debuffDuration;
private:
    
    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};