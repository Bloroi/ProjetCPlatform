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
    Item(sf::Vector2f size,sf::Vector2f pos);

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
