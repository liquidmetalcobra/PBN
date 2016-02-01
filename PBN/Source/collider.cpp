//
//  bouncer.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/12/16.
//
//

#include "collider.hpp"

void collider::update()
{

    unsigned long s = balls.size();
    if (s>=1)
        for(int i = 0; i < s; i++)
            for (int j = 1; j < s; j++)
            {
                //   std::cout<< i << j << "\n";
                if (i != j && checkCollision(balls[i], balls[j]))
                {
          
                    balls[i]->collide(balls[j]);
                    balls[j]->collide(balls[i]);
                }
            }
    
}
void collider::add(gameobject* a)
{
    balls.push_back(a);
}
void collider::remove(gameobject * r)
{
    //balls.erase(std::remove(balls.begin(), balls.end(), r), balls.end());
}
bool collider::checkCollision(gameobject* a, gameobject* b)
{
    float ax,ay,bx,by;
    ax = a->getX();
    ay = a->getY();
    bx = b->getX();
    by = b->getY();
    int size = a->getSize();
 
    if ((ax > bx + size - 1) || // is b1 on the right side of b2?
            (ay > by + size - 1) || // is b1 under b2?
            (bx > ax + size - 1) || // is b2 on the right side of b1?
            (by > ay + size - 1))   // is b2 under b1?
        {
            // no collision
            return 0;
        }
        
        // collision
        return 1;
    

}
