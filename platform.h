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
    Platform(string name,string filename, sf::Vector2f size, sf::Vector2f position );
    ~Platform();

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
