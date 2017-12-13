#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "collider.h"
#include <vector>
#include <platform.h>

using namespace std;


class Enemy
{
public:
    Enemy(sf::Texture* texture,sf::Vector2u imageCount,sf::Vector2f position,float switchTime,float speed);
    ~Enemy();

    void Update(float deltaTime,vector<Platform> plats);
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
    int pos;

    sf::Vector2f velocity;
    sf::Vector2f position;

};

#endif // ENEMY_H
