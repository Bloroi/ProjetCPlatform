#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "collider.h"


class Enemy
{
public:
    Enemy(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed);
    ~Enemy();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f GetPosition(){return body.getPosition();}
    Collider GetCollider(){ return Collider(body);}
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;

};

#endif // ENEMY_H
