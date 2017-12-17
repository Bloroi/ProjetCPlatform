#ifndef PMENUS_H
#define PMENUS_H
#include "panel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <button.h>
#include <vector>

using namespace std;



class PMenus : public Panel
{
protected:
    sf::View viewMenu;
    sf::Font arial;

public:
    /*FORME CANONIQUE*/
    PMenus(){}
    PMenus(sf::RenderWindow* window);
    PMenus(const PMenus& c);
    ~PMenus(){};
    PMenus& operator=(const PMenus& e);

    void ResizeView();
};

#endif // PMENUS_H
