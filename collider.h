#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

class Collider
{
private:
    sf::RectangleShape& body;
public:
    /*FORME CANONIQUE*/
    Collider();
    Collider(sf::RectangleShape& body);
   // Collider(const Collider& c);
    ~Collider();
    //Collider& operator=(const Collider& e);

    void Move(float dx,float dy){ body.move(dx,dy);}

    bool CheckCollision(Collider other,sf::Vector2f& direction, float push);
    bool CheckCollect(Collider other);
    bool CheckOnPlatform(Collider other);
    bool CheckWalls(Collider other);
    sf::Vector2f GetPosition(){ return body.getPosition();}
    sf::Vector2f GetHalfSize(){ return body.getSize()/2.0f;}

};

#endif // COLLIDER_H
