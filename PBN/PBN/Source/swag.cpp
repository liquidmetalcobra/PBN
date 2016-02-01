//
//  swag.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#include "swag.hpp"


void swag::collide(gameobject *go)
{
    if (go == opponent)
    {
        std::cout<< "swag hit";
        opponent->hp-=10;
        markForDeath = true;
        opponent->anim.stop();
    }
}

void swag::update()
{
    anim.update();
    if(anim.animationFrame == anim.numFrames[0])
    {
        anim.stop(0,anim.numFrames[0]);
        moving = 1;
    }
    if (moving == 1)
    {
        setX(getX()+(1*((orientation*2)-1)));
        if(getX() > SCREEN_W || getX() < 0)
        {
            std::cout<< "swag is going away now";
            markForDeath = true;
        }
    }
    
}
void swag::draw()
{
    anim.draw(x,y);
}

void swag::parse(char * filename)
{
    /*
    int doesEvolve,numswags;
  std::cout << "hi";
    std::ifstream myfile;
    
    myfile.open(filename);
    std::string file_line;
    getline(myfile,file_line);
    std::stringstream fl(file_line);
    fl >> name;
    fl >> id;
    fl >> numswags;
    fl >> doesEvolve;
  std::cout << "\n";
  std::cout << name << numswags << doesEvolve;
    for (int i = 0; i < numswags; i++)
    {
        
        getline(myfile, file_line);
        std::istringstream is( file_line );
        
        std::string j;
        is >> j;
        swags.push_back(j);
        int k;
        is >> k;
        swaglevel.push_back(k);
      std::cout << "\n" << j;
    }
    if (doesEvolve)
    {
        getline(myfile, file_line);
        std::istringstream is( file_line );
        is >> evolveto;
        is >> evolveat;
    }
    else
    {
        evolveto = "";
        evolveat = 101;
    }
    //current line of text is in file_line, not including the \n
    myfile.close();
     */
}
