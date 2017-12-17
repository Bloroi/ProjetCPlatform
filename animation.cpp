#include "animation.h"

Animation::Animation(){}

Animation::Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime=0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}
Animation::Animation(const Animation& an){
    this->imageCount = an.imageCount;
    this->currentImage=an.currentImage;

    this->totalTime=an.totalTime;
    this->switchTime= an.switchTime;
    this->uvRect=an.uvRect;

}

Animation::~Animation()
{

}

Animation& Animation::operator=(const Animation& e){
    if(!(&e==this)){
        this->imageCount = e.imageCount;
        this->currentImage=e.currentImage;

        this->totalTime =e.totalTime;
        this->switchTime= e.switchTime;
        this->uvRect= e.uvRect;
    }
    return *this;
}

/** Met à jour l'animation de l'objet qui l'appelle **/
void Animation::Update(int row, float deltaTime,bool faceRight){
    currentImage.y = row;
    totalTime+=deltaTime;

    if(totalTime >= switchTime){
        totalTime -=switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x)
        {
            currentImage.x=0;
        }

    }

    //uvRect.left = currentImage.x* uvRect.width;
    uvRect.top = currentImage.y* uvRect.height;
    if(faceRight){
        uvRect.left = currentImage.x*uvRect.width;
        uvRect.width = abs(uvRect.width);
    }else{
        uvRect.left = (currentImage.x +1)* abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}
