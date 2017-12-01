#include <QApplication>
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <sstream>
#include <SFML/Audio.hpp>
#include <vector>
#include "animation.h"
#include "player.h"
#include "platform.h"

static const float VIEW_HEIGHT = 1600.0f;

void ResizeView(const sf::RenderWindow& window,sf::View& view)
{
    float aspectRatio = float(window.getSize().x)/ float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio,VIEW_HEIGHT);
}

int main(){
    sf::RenderWindow window(sf::VideoMode(512,512),"SFML Tutorial Youtube 2",sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));
    float aspectRatio;
   // sf::RectangleShape player(sf::Vector2f(100.0f,150.0f));
 //   player.setPosition(206.0f,206.0f);
    //sf::Sprite background;
    sf::Texture playerTexture;


    if(!playerTexture.loadFromFile("images/persogrille2.png")){
        QFileInfo file("images/persogrille2.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    playerTexture.setSmooth(true);
    //player.setTexture(&playerTexture);

    //Animation animation(&playerTexture, sf::Vector2u(9,5),0.3f);
    Player player(&playerTexture, sf::Vector2u(9,5),0.1f,350.0f,500.0f);

    //Background
    /*
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("images/background.png")){
        QFileInfo file("images/background.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas ou n'est pas compatible !";
    }else{
        sf::Vector2u TextureSize = backgroundTexture.getSize(); //Size de la texture
        sf::Vector2u WindowSize = window.getSize();

        float ScaleX = (float) WindowSize.x/TextureSize.x;
        float ScaleY = (float) WindowSize.y/TextureSize.y;

        background.setTexture(backgroundTexture);
        background.setScale(ScaleX,ScaleY);
    }*/


    //Don't need this anymore
    /*
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /=9;
    textureSize.y/=5;

    player.setTextureRect(sf::IntRect(textureSize.x*2,textureSize.y*2,textureSize.x,textureSize.y));*/

    sf::Texture groundTexture;
    if(!groundTexture.loadFromFile("images/ground.png")){
        QFileInfo file("images/ground.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }

    std::vector<Platform> platforms;

    platforms.push_back(Platform(&groundTexture,sf::Vector2f(400.0f,100.0f),sf::Vector2f(2700.0f,150.0f)));
    //platforms.push_back(Platform(nullptr,sf::Vector2f(400.0f,200.0f),sf::Vector2f(500.0f,0.0f)));
    platforms.push_back(Platform(&groundTexture,sf::Vector2f(1000.0f,300.0f),sf::Vector2f(500.0f,650.0f)));
    platforms.push_back(Platform(&groundTexture,sf::Vector2f(1000.0f,300.0f),sf::Vector2f(2000.0f,650.0f)));
    platforms.push_back(Platform(nullptr,sf::Vector2f(1,1000),sf::Vector2f(-1,0)));
/*    Platform platform1(&groundTexture,sf::Vector2f(400.0f,200.0f),sf::Vector2f(500.0f,200.0f));
    Platform platform2(nullptr,sf::Vector2f(400.0f,200.0f),sf::Vector2f(500.0f,0.0f));
    Platform platform3(&groundTexture,sf::Vector2f(1000.0f,200.0f),sf::Vector2f(500.0f,500.0f));*/

    float deltaTime = 0.0f;
    sf::Clock clock;


    while(window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f /20.0f){
            deltaTime = 1.0f /20.0f;
        }

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window,view);
                break;
            }
        }
        player.Update(deltaTime);

        sf::Vector2f direction;


        for(Platform& platform : platforms) // for each
        {
            if(platform.GetCollider().CheckCollision(player.GetCollider(),direction,1.0f))
                player.OnCollision(direction);
        }
/*        platform1.GetCollider().CheckCollision(player.GetCollider(),1.0f);
        platform2.GetCollider().CheckCollision(player.GetCollider(),0.1f);*/

        //Permet de déterminer où la caméra peut aller au minimum en fonction de la taille de fenêtre
        aspectRatio = float(window.getSize().x)/float(window.getSize().y);

        view.setCenter(player.GetPosition().x,player.GetPosition().y-200);


        if(view.getCenter().x<(VIEW_HEIGHT*aspectRatio)/2){
            view.setCenter((VIEW_HEIGHT*aspectRatio)/2,view.getCenter().y);
        }

        if(view.getCenter().y>0){
            view.setCenter(view.getCenter().x,0);
        }
       /* animation.Update(0,deltaTime,true);
        player.setTextureRect(animation.uvRect);*/

        window.clear(sf::Color(150,150,150));
        window.setView(view);
        player.Draw(window);

        for(Platform& platform : platforms){
            platform.Draw(window);
        }

      //  qDebug() << player.GetPosition().x << player.GetPosition().y;
        qDebug() << view.getCenter().x << view.getCenter().y;
/*        platform1.Draw(window);
        platform2.Draw(window);*/
        window.display();
    }
    return 0;
}
