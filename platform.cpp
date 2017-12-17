#include "platform.h"

Platform::Platform(string name,string filename, sf::Vector2f size, sf::Vector2f position )
{
    this->name = name;

    sf::Texture *texture = new sf::Texture;
    if(!texture->loadFromFile(filename))
        qDebug()<<"Fichier n'existe pas";

    body.setSize(size);
    body.setOrigin(size/2.0f);
    body.setTexture(texture);
    body.setPosition(position);
    this->filename = filename;
}
Platform::Platform(const Platform& b){

    this->name = b.name;
    this->filename = b.filename;
    this->body=b.body;


}

Platform& Platform::operator=(const Platform& b){
    if(!(&b==this)){

        this->name = b.name;
        this->filename = b.filename;
        this->body=b.body;



    }
    return *this;
}

Platform::~Platform()
{

}

/** Cette méthode permet d'écrire dans la window la plateforme **/
void Platform::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
