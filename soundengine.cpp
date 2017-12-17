#include "soundengine.h"

SoundEngine* SoundEngine::instance = 0;

SoundEngine::SoundEngine()
{

    if(!SBclick.loadFromFile("music/click.wav")){

       }
       Sclick.setBuffer(SBclick);

    if(!SBpickItem.loadFromFile("music/coin.wav")){
       }
       SpickItem.setBuffer(SBpickItem);


     if(!SBjump.loadFromFile("music/jump.wav")){
       }
      Sjump.setBuffer(SBjump);



}

SoundEngine::SoundEngine(const SoundEngine &s)
{

}

SoundEngine* SoundEngine::getInstance()
{
    if(instance==0)
    {
        instance = new SoundEngine;
    }
    return instance;
}

SoundEngine::goMusic(string filepath)
{
    if(filepath!=currentMusic){

    if(music.getStatus()==sf::Music::Playing)
    {
        music.stop();

    }


    if(!music.openFromFile(filepath)){

        }
        music.play();
        music.setLoop(true);
        currentMusic = filepath;

    }
}

SoundEngine::pauseMusic()
{
    music.pause();
}


SoundEngine::stopMusic()
{
    music.stop();
}

SoundEngine::playClick()
{
    Sclick.play();
}
SoundEngine::playPickItem()
{
    SpickItem.play();
}
SoundEngine::playJump()
{
    Sjump.play();
}


