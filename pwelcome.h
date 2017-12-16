#ifndef PWELCOME_H
#define PWELCOME_H
#include "panel.h"
#include "pmenus.h"
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include "button.h"
#include <vector>

using namespace std;

class PWelcome : public PMenus
{
private:
    sf::RectangleShape rect;
    vector<button*>buttons;
public:
    PWelcome(){}
    PWelcome(sf::RenderWindow* window);
    //   PMenu(const PMenu& c);
           ~PWelcome();
    //   PMenu& operator=(const PMenu& e);
    void init();

    //Listeners
    keyPressedOnce();


    //Getters
    int getType()const{return 0;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PWELCOME_H
