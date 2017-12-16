#ifndef PACCUEIL_H
#define PACCUEIL_H
#include "panel.h"
#include "pmenus.h"
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include "button.h"
#include <vector>

using namespace std;

class PAccueil : public PMenus
{
private:
    sf::RectangleShape rect;
    vector<button*>buttons;
public:
    PAccueil(){}
    PAccueil(sf::RenderWindow* window);
    //   PMenu(const PMenu& c);
           ~PAccueil();
    //   PMenu& operator=(const PMenu& e);
    void init();

    //Listeners
    keyPressedOnce();


    //Getters
    int getType()const{return 0;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PACCUEIL_H
