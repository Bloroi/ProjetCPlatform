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
    sf::Texture enemyTexture1;
    sf::Texture enemyTexture2;


    if(!playerTexture.loadFromFile("images/persogrille2.png")){
        QFileInfo file("images/persogrille2.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    playerTexture.setSmooth(true);
    //player.setTexture(&playerTexture);

    if(!enemyTexture1.loadFromFile("images/Dragon.png")){
        QFileInfo file("images/skeletona.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    enemyTexture1.setSmooth(true);


    if(!enemyTexture2.loadFromFile("images/Serpent.png")){
        QFileInfo file("images/Serpent.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    enemyTexture2.setSmooth(true);


    //Animation animation(&playerTexture, sf::Vector2u(9,5),0.3f);
    Player player(&playerTexture, sf::Vector2u(9,5),0.1f,350.0f,500.0f);

    /*ENEMY*/
    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy(&enemyTexture2,sf::Vector2u(4,4), sf::Vector2f(100,150),sf::Vector2f(3100.0f,425.0f),0.2f,150.0f));
    enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(200,250),sf::Vector2f(3050.0f,425.0f),0.1f,250.0f));
    enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(100,100),sf::Vector2f(2900.0f,425.0f),0.1f,250.0f));
 /*   enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3075.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3055.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3080.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3085.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3089.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3088.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3054.0f,425.0f),0.2f,250.0f));
    enemies.push_back(new Enemy(&playerTexture, sf::Vector2u(9,5),sf::Vector2f(3060.0f,425.0f),0.2f,250.0f));*/
    /*PLATFORM*/
    std::vector<Platform> platforms;
    //Methode pour lire les platforms
    lirePlatform(platforms);

     /*ITEMS*/
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
        /*Personnage en mvt*/
        player.Update(deltaTime);
        for(int i=0;i<enemies.size();i++){

            enemies[i]->Update(deltaTime,platforms);
            if(enemies[i]->GetCollider().CheckCollect(player.GetCollider())){
                //player.setPosition(sf::Vector2f(0.00f,0.00f));
                //player.OnCollision(direction);
                player.setcolordamage(sf::Color::Red);
             }
            else{
                player.setcolordamage(sf::Color::White);
            }
        }


        sf::Vector2f direction;

        if(player.GetPosition().y > 1000){
           player.setPosition(sf::Vector2f(206.0f,206.0f));
        }



        for(Platform& platform : platforms) // for each
        {
            if(platform.GetCollider().CheckCollision(player.GetCollider(),direction,1.00f))
                player.OnCollision(direction);

            for(int i=0;i<enemies.size();i++)
            {
                if(platform.GetCollider().CheckCollision(enemies[i]->GetCollider(),direction,1.00f))
                   enemies[i]->OnCollision(direction);
            }
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

        for(int i=0;i<enemies.size();i++)
        {
            enemies[i]->Draw(window);
        }


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
