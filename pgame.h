#ifndef PGAME_H
#define PGAME_H
#include "panel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <button.h>
#include <vector>
#include "player.h"

using namespace std;

class PGame : public Panel
{
    protected:
     sf::Texture playerTexture;
     sf::View viewGame;
     Player player;
    public:
     PGame(){}
     PGame(sf::RenderWindow* window);
//   PGame(const Panel& c);
       ~PGame();
//   PGame& operator=(const PGame& e);
     void ResizeView();
};

#endif // PGAME_H
