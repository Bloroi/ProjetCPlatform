#include "projectile.h"

/*Constructeur comprenant la texture et la taille du projectile*/
Projectile::Projectile(sf::Texture* texture,sf::Vector2f size, int speed){
   projectile.setSize(size);
   projectile.setTexture(texture);
   this->speed=speed;
}

/*Projectile::Projectile(const Projectile& b){

   // projectile.setSize(size);
   // projectile.setTexture(texture);
    this->speed=b.speed;

}

Projectile& Projectile::operator=(const Projectile& b){
   projectile.setSize(size);
   projectile.setTexture(texture);
   this->speed=b.speed;
}*/

Projectile::~Projectile()
{}

/*Méthode pour faire bouger le projectile à une certaine vitesse*/
void Projectile::fire(){

     projectile.move(speed,0);

}

/*Méthode pour intégrer le missile dans la map*/
void Projectile::Draw(sf::RenderWindow& window){
    window.draw(projectile);
}

/*Méthode pour changer la position du projectile*/
void Projectile::setPosition(sf::Vector2f newPos){
   projectile.setPosition(newPos);
}
