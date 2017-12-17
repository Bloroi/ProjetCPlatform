#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>

using namespace std;

class button
{
private:
    sf::Texture textureNormal;
    sf::Texture textureClicked;
    sf::Sprite sprite;
    int todo;
    string name;
public:
    /*FORME CANONIQUE*/
    button(){}
    button(string name,int todo,float size,sf::Vector2i pos,string path="0",string pathSelected="0");
    ~button(){}
    button( const button& b);
    button& operator=(const button& e);


    void changeTexture(bool selected);
    bool isSelected(int x,int y);

    //Setters
    void setPosition(int x, int y);
    setToDo(int todo);
    //Getters
    sf::Sprite getSprite()const{return sprite;}
    sf::Vector2f getPosition()const{return sprite.getPosition();}
    int getTodo()const{return todo;}
    //void drawTo(sf::RenderWindow & window){window.draw(sprite);}
};

#endif // BUTTON_H
