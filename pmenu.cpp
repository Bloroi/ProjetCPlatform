#include "pmenu.h"

PMenu::PMenu(sf::RenderWindow* window) : Panel(window)
{


    rect.setPosition(sf::Vector2f(50,200));
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color(33,42,231,255));


    buttons.push_back(new button("buttonSettings",Panel::PLEVEL1,2,sf::Vector2i(0,0),"images/bouton1.png","images/bouton2.png"));
    //buttons.push_back(new button("buttonSettings",Panel::PMENU,2,sf::Vector2i(0,150),"images/bouton1.png","images/bouton2.png"));

}

PMenu::~PMenu()
{}

void PMenu::init()
{

    sf::Event event;
            while(mainWindow->pollEvent(event))
            {
                switch(event.type){
                case sf::Event::Resized:
                    ResizeView(*mainWindow,viewMenu,512.0f);
                    break;
                }
            }
        aspectRatio = float(mainWindow->getSize().x)/float(mainWindow->getSize().y);

        mainWindow->setView(viewMenu);


    // récupération de la position de la souris dans la fenêtre
   pixelPos = sf::Mouse::getPosition(*mainWindow);

    // conversion en coordonnées "monde"
   worldPos = mainWindow->mapPixelToCoords(pixelPos);

    for(int i =0;i<buttons.size();i++)
        mouseClicked(buttons[i]);

    keyPressedOnce();
    mainWindow->draw(rect);

    for(int i =0;i<buttons.size();i++)
        mainWindow->draw(buttons.at(i)->getSprite());
}

PMenu::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        setActiveP(Panel::PSETTINGS);
    }
}

