#ifndef PSETTINGS_H
#define PSETTINGS_H
#include <SFML/Graphics.hpp>
#include <panel.h>
#include <iostream>

using namespace std;

class PSettings : public Panel
{
private:
    int activeP=0;
public:
    PSettings(){}
    PSettings(sf::RenderWindow* window);
    //   PSettings(const PSettings& c);
    ~PSettings();
    //   PSettings& operator=(const PSettings& e);
    void init();

    //Listeners
    keyPressedOnce();
    int mouseClicked();


    //Getters
    int getType()const{return PSETTINGS;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PSETTINGS_H
