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
#include "functions.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>
#include "enemy.h"

using namespace std;

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

    Enemy ennemi(&playerTexture, sf::Vector2u(9,5),0.2f,450.0f);



    std::vector<Platform> platforms;


    //Lire plateforms

    lirePlatform(platforms);

    std::vector<Item> items;
    items.push_back(Item(sf::Vector2f(80,80),sf::Vector2f(570,420)));
    //Ecrire
/*
    string const filename("platforms.txt");
    std::ofstream out (filename.c_str());
    for(Platform platform : platforms){
      out << platform;
    }
    out.close();
*/


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
        ennemi.Update(deltaTime);
        sf::Vector2f direction;


     /*   sf::Thread thread(ennemi.Update(deltaTime));

        thread.launch();*/


        for(Platform& platform : platforms) // for each
        {
            if(platform.GetCollider().CheckCollision(player.GetCollider(),direction,1.00f))
                player.OnCollision(direction);
            if(platform.GetCollider().CheckCollision(ennemi.GetCollider(),direction,1.00f))
                ennemi.OnCollision(direction);
        }

        for(Item& item : items) // for each
        {
            if(item.GetCollider().CheckCollect(player.GetCollider())){
                item.setPos(sf::Vector2f(0.00f,0.00f));
             }
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
        ennemi.Draw(window);

        for(Platform& platform : platforms){
            platform.Draw(window);
        }

        for(Item item : items){
            item.Draw(window);
        }



      //  qDebug() << player.GetPosition().x << player.GetPosition().y;
       // qDebug() << view.getCenter().x << view.getCenter().y;
/*        platform1.Draw(window);
        platform2.Draw(window);*/
        window.display();
    }
    return 0;
}
