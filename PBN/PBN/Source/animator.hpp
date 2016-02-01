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
#include <string>
#include <fstream>
#include <sstream>

#include <vector>


class animator : public gameobject
{
public:
    animator(char * bitmapName,char * spritesheetName)
    {
        init(bitmapName,spritesheetName);
    
    };
    animator() {
    std::cout << "\nSHOULD NOT BE CALLED\n";
        
    };
    ~animator()
    {
        al_destroy_bitmap(b);
    };
    void init(char * bmpName, char * ssName);
    void parse(char * ssName);
    void switchAnimations(int animationNumber);
    void update();
    
    void draw(int lx, int ly);
    
    void stop(int aniNum, int aniFrame);
    void stop();
    void start();
    
    
    int animationFrame;
    int nextAnimation;
    int isPlaying;
    std::vector<int> speed;
    std::vector<int> numFrames;
    std::vector<int> x;
    std::vector<int> y;
    
    int currentAnimation;
    int numAnimations;
    int height;
    int width;
    int resetCount;
private:
    ALLEGRO_BITMAP *b;
    
};