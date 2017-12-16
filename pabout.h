#ifndef PABOUT_H
#define PABOUT_H
#include "pmenus.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include <vector>
#include <sstream>

using namespace std;

class PAbout: public PMenus
{
private:
    sf::RectangleShape rect;
     vector<button*>buttons;
     ostringstream ssAbout;
     sf::Text lblAbout;
public:
    PAbout(){}
    PAbout(sf::RenderWindow* window);
    ~PAbout(){}

    void init();

    keyPressedOnce();

    int getType()const{return PABOUT;}
};

#endif // PABOUT_H
