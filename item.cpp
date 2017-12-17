#include "item.h"

Item::Item(sf::Vector2f size,sf::Vector2f pos){
    item.setSize(size);
    //coin.setFillColor(sf::Color::Yellow);
    item.setPosition(pos);
    sf::Texture *texture = new sf::Texture;
    this->texture="images/sword1.png";
    if(!texture->loadFromFile("images/sword1.png"))
        qDebug()<<"Fichier n'existe pas";

    item.setTexture(texture);
}
/*Item::Item(const Item& c)
{
  item.setSize(sf::Vector2f(c.getGlobalBounds().width,c.getGlobalBounds().height));

   item.setPosition(c.GetPosition());
    sf::Texture *texture = new sf::Texture;
    if(!texture->loadFromFile("images/sword1.png"))
        qDebug()<<"Fichier n'existe pas";

    item.setTexture(c.texture);
}*/

Item::~Item(){}

/*Méthode qui permet d'afficher l'item*/
void Item::Draw(sf::RenderWindow &window){
    window.draw(item);
}

sf::FloatRect Item::getGlobalBounds(){
    return item.getGlobalBounds();
}

void Item::setPos(sf::Vector2f newPos){
    item.setPosition(newPos);
}
