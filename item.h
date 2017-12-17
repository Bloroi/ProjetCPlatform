#ifndef ITEM_H
#define ITEM_H
#include <collider.h>
#include <istream>
#include <ostream>
#include <string>

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Item{
public:
    Item(){}
    Item(sf::Vector2f size,sf::Vector2f pos){
        item.setSize(size);
        //coin.setFillColor(sf::Color::Yellow);
        item.setPosition(pos);
        sf::Texture *texture = new sf::Texture;
        if(!texture->loadFromFile("images/key.png"))
            qDebug()<<"Fichier n'existe pas";

        item.setTexture(texture);
    }

    // Item(const Item& c);
      ~Item(){}
  //    Item& operator=(const Item& e);

    void Draw(sf::RenderWindow &window){
        window.draw(item);
    }


    sf::Vector2f GetPosition(){return item.getPosition();}
    Collider GetCollider(){ return Collider(item);}

    sf::FloatRect getGlobalBounds(){
        return item.getGlobalBounds();
    }

    void setPos(sf::Vector2f newPos){
        item.setPosition(newPos);
    }

private:
    sf::RectangleShape item;
};

#endif // ITEM_H
