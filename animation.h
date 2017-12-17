#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once
#include <SFML/Graphics.hpp>



class Animation
{

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

public:
    /*FORME CANONIQUE*/
    Animation();
    Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
    Animation(const Animation& an);
    ~Animation();
    Animation& operator=(const Animation& e);

    void Update(int row, float deltaTime,bool faceRight);
    void setSwitchTime(float switchTime){this->switchTime = switchTime;}
public:
    sf::IntRect uvRect;

};

#endif // ANIMATION_H
