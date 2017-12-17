#include "psettings.h"

PSettings::PSettings(sf::RenderWindow* window) : Panel(window)
{

}

PSettings::PSettings(const PSettings& b){

}

PSettings& PSettings::operator=(const PSettings& b){

}


PSettings::~PSettings()
{}

void PSettings::init()
{

    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(50,200));
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color::Red);

    keyPressedOnce();
    mainWindow->draw(rect);
}

PSettings::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
