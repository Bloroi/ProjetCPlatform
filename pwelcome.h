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
    /*FORME CANONIQUE*/
    PWelcome(){}
    PWelcome(sf::RenderWindow* window);
    PWelcome(const PWelcome& c);
    ~PWelcome();
    PWelcome& operator=(const PWelcome& e);


    void init();
    //Listeners
    keyPressedOnce();
    //Getters
    int getType()const{return PWELCOME;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PWELCOME_H
