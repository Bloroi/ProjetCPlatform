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
    PMenus(){}
    PMenus(sf::RenderWindow* window);
    ~PMenus(){}
    void ResizeView();
};

#endif // PMENUS_H
