#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once
#include <SFML/Graphics.hpp>



class Animation
{
public:
    Animation();
    Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
    ~Animation();

    void Update(int row, float deltaTime,bool faceRight);
    void setSwitchTime(float switchTime){this->switchTime = switchTime;}
public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};

#endif // ANIMATION_H
