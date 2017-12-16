#include "pgame.h"

PGame::PGame(sf::RenderWindow* window) : Panel(window)
{



   this->viewGame = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(Panel::VIEW_GAME,VIEW_GAME));
  /*PLAYER*/
    if(!playerTexture.loadFromFile("images/playerRedmond.png")){
            QFileInfo file("images/persogrille2.png");
            qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
        }
    playerTexture.setSmooth(true);

  this->player = Player(&playerTexture, sf::Vector2u(4,3),0.1f,350.0f,500.0f);
}

PGame::~PGame()
{}
