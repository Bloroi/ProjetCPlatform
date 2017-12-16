#include "panel.h"

int Panel::activeP =0;

Panel::Panel(sf::RenderWindow* window)
{
    mainWindow = window;
    this->viewMenu = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_MENU,VIEW_MENU));
}

Panel::~Panel()
{

}

void Panel::ResizeView(const sf::RenderWindow& window,sf::View& view,float heightView)
{
    float aspectRatio = float(window.getSize().x)/ float(window.getSize().y);
    view.setSize(heightView * aspectRatio,heightView);
}

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


