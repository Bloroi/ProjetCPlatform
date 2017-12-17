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

PGame::PGame(const PGame& b){

    this->viewGame = b.viewGame;
    this->playerTexture = b.playerTexture;
    this->player = b.player;

}

PGame& PGame::operator=(const PGame& b){
    if(!(&b==this)){

        this->viewGame = b.viewGame;
        this->playerTexture = b.playerTexture;


        this->player = b.player;

    }
    return *this;
}

PGame::~PGame()
{}

void PGame::ResizeView()
{
    float aspectRatio = float(mainWindow->getSize().x)/ float(mainWindow->getSize().y);
    viewGame.setSize(VIEW_GAME * aspectRatio,VIEW_GAME);
}
