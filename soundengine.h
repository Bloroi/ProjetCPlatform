#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H
#include <string>
#include <iostream>
#include <QDebug>
#include <QFileInfo>
#include <SFML/Audio.hpp>

using namespace std;


class SoundEngine
{
private:
    SoundEngine();
    static SoundEngine* instance;
    sf::Music music;
    string currentMusic;
    sf::SoundBuffer SBpickItem;
    sf::SoundBuffer SBclick;
    sf::SoundBuffer SBjump;
    sf::Sound SpickItem;
    sf::Sound Sclick;
    sf::Sound Sjump;

public:
    SoundEngine(const SoundEngine &s);
    ~SoundEngine();
    static SoundEngine* getInstance();
    goMusic(string filepath);
    pauseMusic();
    stopMusic();
    playClick();
    playPickItem();
    playJump();


};

#endif // SOUNDENGINE_H
