#ifndef PANEL_H
#define PANEL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <button.h>
#include <soundengine.h>


class Panel
{
private:
    static int activeP;

protected:
    sf::RenderWindow* mainWindow;
    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

    float aspectRatio;


    float VIEW_GAME = 1600.0f;
    float VIEW_MENU = 512.0f;
    SoundEngine *se = SoundEngine::getInstance();


public:
    /*FORME CANONIQUE*/
    Panel(){}
    Panel(sf::RenderWindow* window);
    Panel(const Panel& c);
    ~Panel();
    Panel& operator=(const Panel& e);
    enum{
        PWELCOME,
        PSETTINGS,
        PABOUT,
        PLEVEL1
    };
    virtual void init()=0;

    //Listeners

    mouseClicked(button *btn);
    virtual void ResizeView(){}



    //Getters
    virtual int getType()const=0;
    //sf::RenderWindow* getWindow() const{return mainWindow;}
    //sf::RenderWindow& getWindow2() const{return *mainWindow;}
    int getActiveP(){return activeP; }
    void setActiveP(int a){activeP = a;}
};

#endif // PANEL_H
