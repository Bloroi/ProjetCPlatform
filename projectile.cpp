#include "projectile.h"

Projectile::Projectile(sf::Texture* texture,sf::Vector2f size){
   projectile.setSize(size);
   projectile.setTexture(texture);
}

void Projectile::fire(int speed){
    projectile.move(speed,0);
}

void Projectile::Draw(sf::RenderWindow& window){
    window.draw(projectile);
}

void Projectile::setPosition(sf::Vector2f newPos){
   projectile.setPosition(newPos);
}
