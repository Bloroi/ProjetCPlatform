#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <coin.h>

class Player{
public :
    Player(){
        if(!perso.loadFromFile("images/player.png")){
            QFileInfo file("images/player.png");
            qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
        }
        perso.setSmooth(true);

        sprite.setTexture(perso);

    }

    void drawTo(sf::RenderWindow & window){
        window.draw(sprite);
    }

    void move(sf::Vector2f distance){
        sprite.move(distance);
    }

    void setPos(sf::Vector2f newPos){
        sprite.setPosition(newPos);
    }

    int getY(){
        return sprite.getPosition().y;
    }

    bool isCollidingWithCoin(Coin *coin){
        if(sprite.getGlobalBounds().intersects((coin->getGlobalBounds()))){
            return true;
        }
        return false;
    }

private:
    //sf::RectangleShape player;
       sf::Texture perso;
       sf::Sprite sprite;

};

#endif // PLAYER_H
