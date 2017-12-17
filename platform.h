#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Graphics.hpp>
#include <collider.h>
#include <istream>
#include <ostream>
#include <string>
#include <QFileInfo>
#include <QDebug>

using std::istream;
using std::ostream;
using std::string;

class Platform
{
public:
    /*FORME CANONIQUE*/
    Platform(){}
    Platform(string name,string filename, sf::Vector2f size, sf::Vector2f position );
    Platform(const Platform& c);
    ~Platform();
    Platform& operator=(const Platform& e);


    string getName()const{return name;}


    void Draw(sf::RenderWindow& window);
    Collider GetCollider(){return Collider(body);}

    //friend istream& operator>>(istream& is, Platform& p);
    friend ostream& operator<<(ostream& os, const Platform& p);

private:
    sf::RectangleShape body;
    string name;
    string filename;
};

#endif // PLATFORM_H
