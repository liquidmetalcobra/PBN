//
//  tile.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/12/16.
//
//

#include "tile.hpp"

void tile::collide(gameobject *go)
{
   // cout << "TILE";
    resetCount = 20;
    al_set_target_bitmap(b);
    al_clear_to_color(al_map_rgb(255, 10, 125));
    
}

void tile::update()
{
    if (resetCount == 1)
    {
        resetCount--;
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(0, 0, 255));
        
    }
    else if (resetCount > 0)
    {
        resetCount--;
    }

}
void tile::draw()
{
    al_draw_bitmap(b, x, y, 0);
}
void tile::init()
{
    
}
