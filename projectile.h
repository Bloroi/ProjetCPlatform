#ifndef PROJECTILE_H
#define PROJECTILE_H
#include<SFML/Graphics.hpp>

class Projectile
{
    private:
        sf::RectangleShape projectile;
    public:
        Projectile(sf::Texture* texture,sf::Vector2f size);

        void fire(int speed);

        void Draw(sf::RenderWindow& window);

        void setPosition(sf::Vector2f newPos);
};
#endif
