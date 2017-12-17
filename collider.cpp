#include "collider.h"

/*Collider::Collider()
{
}*/
Collider::Collider(sf::RectangleShape& body):body(body)
{
}

/*Collider::Collider(const Collider& b){

    this->body(b.body);

}

Collider& Collider::operator=(const Collider& b){
    if(!(&b==this)){

        this->body(b.body);

    }
    return *this;
}*/

Collider::~Collider(){

}

/**Cette méthode permet de vérifier la collision d'un joueur, ennemi ou autre par rapport à un autre objet
 pour lui empêcher de passer à travers (ici utilisé pour les plateformes)**/
bool Collider::CheckCollision(Collider other,sf::Vector2f& direction, float push){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);



    if(intersectX < 0.0f && intersectY < 0.00f){
        push = std::min(std::max(push,0.0f),1.0f);

        if(intersectX > intersectY){
            if(deltaX > 0.0f){
                Move(intersectX * (1.0f - push),0.0f);
                other.Move(-intersectX* push,0.0f);

                direction.x=1.0f;
                direction.y=0.0f;
            }
            else
            {
                Move(-intersectX * (1.0f - push),0.0f);
                other.Move(intersectX* push,0.0f);

                direction.x=-1.0f;
                direction.y=0.0f;
            }
        }
        else
        {
            if(deltaY > 0.0f){
                Move(0.0f,intersectY * (1.0f - push));
                other.Move(0.0f,-intersectY* push);

                direction.x=0.0f;
                direction.y=1.0f;
            }
            else
            {
                Move(0.0f,-intersectY * (1.0f - push));
                other.Move(0.0f,intersectY* push);


                direction.x=0.0f;
                direction.y=-1.0f;
            }
        }

        return true;
    }

    return false;
}

/**Cette méthode permet de vérifier la collision d'un joueur avec un item , pour lui permettre de le récupérer**/
bool Collider::CheckCollect(Collider other){
   // cout<<body.getPosition().x <<body.getPosition().y<<endl;

    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x)+30;
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    //cout<<intersectX<<"/"<<intersectY<<endl;

    if(intersectX < 0.0f && intersectY < 0.00f){
        return true;
    }

    return false;
}

/**Cette méthode permet de vérifier si un objet touche une platform.
 * Exemple :Un joueur qui marche sur la plateform**/
bool Collider::CheckOnPlatform(Collider other){
   // cout<<body.getPosition().x <<body.getPosition().y<<endl;

    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x)+50;
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    //if(intersectX < 50 && intersectY<1)
       // cout<<intersectX<<"/"<<intersectY<<endl;

    if(intersectX < 0.0f && intersectY <= 0.00f){
        return true;
    }

    return false;
}
/**Cette méthode permet de vérifier si un objet touche un mur.
 * Exemple :Au début du jeu, je joueur ne peut pas aller à gauche
 * car il y a un mur**/
bool Collider::CheckWalls(Collider other){
   // cout<<body.getPosition().x <<body.getPosition().y<<endl;

    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x)-20;
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

if(intersectX < 20 && intersectY<1)
    cout<<intersectX<<"/"<<intersectY<<endl;

    if(intersectX < 0.0f && intersectY < 0.00f){
        return true;
    }

    return false;
}




