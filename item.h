#ifndef ITEM_H
#define ITEM_H
#include <collider.h>
#include <istream>
#include <ostream>
#include <string>
#include <QFileInfo>
#include <QDebug>

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Item{

private:
    sf::RectangleShape item;
    string texture;

public:
    /*FORME CANONIQUE*/
    Item(){}
<<<<<<< HEAD
    Item(sf::Vector2f size,sf::Vector2f pos){
        item.setSize(size);
        //coin.setFillColor(sf::Color::Yellow);
        item.setPosition(pos);
        sf::Texture *texture = new sf::Texture;
        if(!texture->loadFromFile("images/key.png"))
            qDebug()<<"Fichier n'existe pas";
=======
    Item(sf::Vector2f size,sf::Vector2f pos);
>>>>>>> b364c1339a3e2c26e89f24373b0100ad62a5b650

   // Item(const Item& c);
    ~Item();
   // Item& operator=(const Item& e);

    void Draw(sf::RenderWindow &window);


    sf::Vector2f GetPosition(){return item.getPosition();}
    Collider GetCollider(){ return Collider(item);}

    sf::FloatRect getGlobalBounds();

    void setPos(sf::Vector2f newPos);

};

#endif // ITEM_H
