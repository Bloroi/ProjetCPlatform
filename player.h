#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "collider.h"
#include "enemy.h"

class Player
{
public:
    Player();
    Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f GetPosition(){return body.getPosition();}
    bool GetFaceRight(){return faceRight;}
    void setPosition(sf::Vector2f position){ body.setPosition(position);}
    Collider GetCollider(){ return Collider(body);}
    void setcolordamage(sf::Color);
    /*bool collisions(Enemy e)
    {
        this->getGlo
    }*/
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;




};

#endif // PLAYER_H
