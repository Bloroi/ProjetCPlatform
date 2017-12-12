#include "enemy.h"

Enemy::Enemy(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed) :
    animation(texture,imageCount,switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.0f,150.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(206.0f,206.0f);
    body.setTexture(texture);
    //body.setFillColor(sf::Color::Blue);
}

Enemy::~Enemy(){

}

void Enemy::OnCollision(sf::Vector2f direction)
{
    if(direction.x < 0.0f)
    {
        //Collision on the left.
        velocity.x=0.0f;
    }
    else if(direction.x > 0.0f)
    {
        //Collision on the right.
        velocity.x = 0.0f;
    }

    if(direction.y < 0.0f)
    {
        //Collision on the bottom.
        velocity.y=0.0f;
    }
    else if(direction.y > 0.0f)
    {
        //Collision on the top.
        velocity.y = 0.0f;
    }


}


void Enemy::Update(float deltaTime){

    //sf::Vector2f movement(0.0f,0.0f);
    velocity.x = 0.0f;

    for(int i=0; i<1000;i++){
        if(i<500)
        {

            velocity.x -=speed /** deltaTime*/;
        }
        else
        {
            velocity.x +=speed /** deltaTime*/;
        }
    }


    velocity.y += 981.0f * deltaTime;

    if(velocity.x ==0.0f)
    {
        animation.setSwitchTime(0.3f);
        row=0;
    }
    else
    {
        row = 2;
        animation.setSwitchTime(0.1f);

        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }


    animation.Update(row,deltaTime,faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity*deltaTime);
}

void Enemy::Draw(sf::RenderWindow& window){
    window.draw(body);
}

