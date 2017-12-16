#include "pmenus.h"

PMenus::PMenus(sf::RenderWindow* window) : Panel(window)
{
    this->viewMenu = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_MENU,VIEW_MENU));
     arial.loadFromFile("styles/arial.ttf");
}

void PMenus::ResizeView()
{
    float aspectRatio = float(mainWindow->getSize().x)/ float(mainWindow->getSize().y);
    viewMenu.setSize(VIEW_MENU * aspectRatio,VIEW_MENU);
}
