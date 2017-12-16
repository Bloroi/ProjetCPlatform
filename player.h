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
    Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,float jumpHeight, int score = 0,int health = 5, bool key = false);
    //   Player(const Player& c);
           ~Player();
    //   Player& operator=(const Player& e);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f GetPosition(){return body.getPosition();}
    bool GetFaceRight(){return faceRight;}
    void setPosition(sf::Vector2f position){ body.setPosition(position);}
    Collider GetCollider(){ return Collider(body);}
    void setcolordamage(sf::Color);
    int getScore()const{return score;}
    int getHealth()const{return health;}
    void setScore(int newScore){score = newScore;}
    void setHealth(int newHealth){health = newHealth;}
    int getKey()const{return key;}
    void setKey(int newKey){key = newKey;}
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
    bool key;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    int health;
    int score;




};

#endif // PLAYER_H
