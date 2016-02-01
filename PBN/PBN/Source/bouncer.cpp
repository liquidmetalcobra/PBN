//
//  bouncer.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/12/16.
//
//

#include "bouncer.hpp"

void bouncer::collide(gameobject *go)
{

//std::cout << typeid(go).name();
    resetCount = 120;


    al_set_target_bitmap(b);
    al_clear_to_color(al_map_rgb(25, 100, 255));
    if (go->getID() == 1)
        markForDeath = true;
}

void bouncer::update()
{
    if (resetCount == 1)
    {
        resetCount--;
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 100, 255));

    }
    else if (resetCount > 0)
    {
        resetCount--;
    }
    if(x < 0 || x > SCREEN_W - size) {
        dx *=-1;
    }
    
    if(y < 0 || y > SCREEN_H - size) {
        dy *=-1;
    }
    x+=dx;
    y+=dy;
  // std::swag << this->y;
    
   
}
void bouncer::draw()
{
    al_draw_bitmap(b, x, y, 0);
}
void bouncer::init()
{
    
}
