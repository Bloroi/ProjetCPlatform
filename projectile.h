#ifndef PROJECTILE_H
#define PROJECTILE_H
#include<SFML/Graphics.hpp>
#include <collider.h>
class Projectile
{
    private:
        sf::RectangleShape projectile;
        int speed;

    public:
        /*FORME CANONIQUE*/
        Projectile(){}
        Projectile(sf::Texture* texture,sf::Vector2f size, int speed);
       // Projectile(const Projectile& c);
        ~Projectile();
       // Projectile& operator=(const Projectile& e);


        void fire();
        void Draw(sf::RenderWindow& window);
        Collider GetCollider(){ return Collider(projectile);}
        void setPosition(sf::Vector2f newPos);
         sf::Vector2f GetPosition(){return projectile.getPosition();}
};
#endif
