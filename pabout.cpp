#include "pabout.h"

PAbout::PAbout(sf::RenderWindow* window) : PMenus(window)
{
    rect.setPosition(sf::Vector2f(50,200));
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color(250,250,231,255));

    buttons.push_back(new button("buttonBack",Panel::PWELCOME,2,sf::Vector2i(-240,-210),"images/buttonBack.jpg","images/buttonBackA.jpg"));

    //about
    ssAbout<<"Jeu realise par ADRIAENS Alexandre,\n"
          <<"CARLIER Logan, SCIOT Celine.\n"
          <<"Etudiants de la HELHa Campus Mons,\n"
         <<"dans le cadre du cours de Mr. V. Altares.";
    lblAbout.setCharacterSize(30);
    lblAbout.setFont(arial);
    lblAbout.setString(ssAbout.str());
   // lblAbout.setOrigin(lblAbout.getGlobalBounds().width-(mainWindow->getSize().x/4),lblAbout.getGlobalBounds().height);
    lblAbout.setPosition(sf::Vector2f(-250,-50));
}

void PAbout::init()
{
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


   mainWindow->draw(lblAbout);
}


PAbout::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
