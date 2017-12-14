#include "player.h"

Player::Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,float jumpHeight) :
    animation(texture,imageCount,switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.0f,150.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(3100.0f,206.0f);
    body.setTexture(texture);
    //body.setFillColor(sf::Color::Blue);
}



Player::~Player(){

}

void Player::setcolordamage(sf::Color color)
{
    body.setFillColor(color);
}

/**Cette méthode agit si il y a collision avec une plateforme empêchant de bouger le personnage dans la direction de
 cette plateforme**/
void Player::OnCollision(sf::Vector2f direction)
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
        canJump = true;
    }
    else if(direction.y > 0.0f)
    {
        //Collision on the top.
        velocity.y = 0.0f;
    }


}

/**Est apellé à chaque frame du jeu pour mettre à jour les mouvements du personnage **/
void Player::Update(float deltaTime){

    velocity.x = 0.0f;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        velocity.x -=speed /** deltaTime*/;
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            velocity.x -=speed*1.2;
           }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity.x +=speed /** deltaTime*/;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
           velocity.x +=speed*1.2;
          }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;

        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
        //square root (2.0f * gravity * jumpHeight);
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

    if(!canJump){
        row = 1;
        animation.setSwitchTime(0.5f);
    }

    animation.Update(row,deltaTime,faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity*deltaTime);
}

/**Permet d'écrire le personnage dans la window passée en paramètre **/
void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
}

