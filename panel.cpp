#include "panel.h"

int Panel::activeP =0;

Panel::Panel(sf::RenderWindow* window)
{
    mainWindow = window;
}

Panel::Panel(const Panel& b){

    this->mainWindow = b.mainWindow;

}

Panel& Panel::operator=(const Panel& b){
    if(!(&b==this)){

        this->mainWindow = b.mainWindow;
    }
    return *this;
}


Panel::~Panel()
{

}

/*Méthode qui gère les boutons lorsque ceux-ci sont activés*/
Panel::mouseClicked(button *btn){
    if(btn->isSelected(worldPos.x,worldPos.y))
    {

        btn->changeTexture(true);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            setActiveP(btn->getTodo());
        }
    }else{
        btn->changeTexture(false);
    }
}


