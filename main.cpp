#include <QApplication>
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <sstream>
#include <SFML/Audio.hpp>
#include <vector>
#include "animation.h"
#include "player.h"
#include "platform.h"
#include "functions.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>
#include "enemy.h"
#include "projectile.h"
#include "panel.h"
#include "pmenu.h"
#include "psettings.h"
#include "plevel.h"


using namespace std;




int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"The Legend of HELHa",sf::Style::Close | sf::Style::Resize);

    int activePanel=0;
    vector<Panel*> panels;
    panels.push_back(new PMenu(&window));
    panels.push_back(new PSettings(&window));
    panels.push_back(new PLevel(&window));



    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        activePanel=panels[activePanel]->getActiveP();
        window.clear();
        panels[activePanel]->init();
       // window.clear(sf::Color(150,150,150));
        window.display();
    }
    return 0;
}
