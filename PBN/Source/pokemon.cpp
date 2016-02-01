//
//  pokemon.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#include "pokemon.hpp"


void pokemon::collide(gameobject *go)
{
    std::cout << "\n" << hp;
}

void pokemon::update()
{
    if( hp <=0)
        markForDeath = true;
    anim.update();
}
void pokemon::draw()
{
    anim.draw(x,y);
}
void pokemon::init()
{
    
}
void pokemon::parse(char * filename)
{
    int doesEvolve,numMoves;
 // std::cout << "hi";
    std::ifstream myfile;
    
    myfile.open(filename);
    std::string file_line;
    getline(myfile,file_line);
    std::stringstream fl(file_line);
    fl >> name;
    fl >> id;
    fl >> numMoves;
    fl >> doesEvolve;
//  std::cout << "\n";
//  std::cout << name << numMoves << doesEvolve;
    for (int i = 0; i < numMoves; i++)
    {
    
        getline(myfile, file_line);
        std::istringstream is( file_line );
        
        std::string j;
        is >> j;
        moves.push_back(j);
        int k;
        is >> k;
        movelevel.push_back(k);
  //    std::cout << "\n" << j;
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
}
