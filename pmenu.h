#ifndef PMENU_H
#define PMENU_H
#include "panel.h"
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include "button.h"
#include <vector>

using namespace std;

class PMenu : public Panel
{
private:
    sf::RectangleShape rect;
    vector<button*>buttons;
public:
    PMenu(sf::RenderWindow* window);
    ~PMenu();
    void init();

    //Listeners
    keyPressedOnce();


    //Getters
    int getType()const{return 0;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PMENU_H
