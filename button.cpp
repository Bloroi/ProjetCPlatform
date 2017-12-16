#include "button.h"

button::button(string name,int todo,float size,sf::Vector2i pos,string path,string pathSelected)
{
    if(path!="0")
    {
        if(!textureNormal.loadFromFile(path)){

            qDebug()<<"Fichier n'existe pas";
        }
        textureNormal.setSmooth(true);
        sprite.setTexture(textureNormal);
    }

    if(pathSelected!="0")
    {
        if(!textureClicked.loadFromFile(pathSelected)){

            qDebug() <<"Fichier n'existe pas";
        }
        textureClicked.setSmooth(true);
    }

    this->name = name;
    this->todo = todo;
    sprite.setScale(sprite.getScale().x/size,sprite.getScale().y/size);
    cout<<sprite.getGlobalBounds().width<<"/"<<sprite.getGlobalBounds().height<<endl;
    sprite.setOrigin(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height);
    this->setPosition(pos.x,pos.y);

}

void button::changeTexture(bool selected){
    if(selected){
        sprite.setTexture(textureClicked);
    }else
    {
        sprite.setTexture(textureNormal);
    }
}

bool button::isSelected(int x,int y)
{
    if(sprite.getGlobalBounds().contains(x,y))
    {
        return true;
    }
    return false;
}

void button::setPosition(int x, int y)
{
    sprite.setPosition(sf::Vector2f(x,y));
}

button::setToDo(int todo)
{
    this->todo= todo;
}
