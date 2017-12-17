#ifndef PLEVEL_H
#define PLEVEL_H
#include "pgame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include <vector>
#include "functions.h"
#include "item.h"
#include "projectile.h"
#include <SFML/Audio.hpp>

using namespace std;

class PLevel : public PGame
{
private :
    /*TEXTURE*/
    sf::Texture enemyTexture1;
    sf::Texture enemyTexture2;
    sf::Texture projectileTexture;
    /*PROJECTILE*/
    std::vector<Projectile> projectileVector;
    std::vector<Enemy*> enemies;
    std::vector<Platform> platforms;
    std::vector<Item> items;
    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::Event event;


public:
    /*FORME CANONIQUE*/
    PLevel(){}
    PLevel(sf::RenderWindow* window);
    PLevel(const PLevel& c);
    ~PLevel();
    PLevel& operator=(const PLevel& e);


    void init();
    keyPressedOnce();
    void initDeltaTime();
    int getType()const{return PLEVEL1;}

};


#endif // PLEVEL_H
