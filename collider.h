#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

class Collider
{
public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    void Move(float dx,float dy){ body.move(dx,dy);}

    bool CheckCollision(Collider other,sf::Vector2f& direction, float push);
    bool CheckCollect(Collider other);
    bool CheckOnPlatform(Collider other);
    bool CheckWalls(Collider other);
    sf::Vector2f GetPosition(){ return body.getPosition();}
    sf::Vector2f GetHalfSize(){ return body.getSize()/2.0f;}
private:
    sf::RectangleShape& body;

};

#endif // COLLIDER_H
