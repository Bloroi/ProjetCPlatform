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
#include "projectile.h"


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

    /*TEXTURE*/
    sf::Texture playerTexture;
    sf::Texture enemyTexture1;
    sf::Texture enemyTexture2;

    //PLAYER TEXTURE
    if(!playerTexture.loadFromFile("images/playerRedmond.png")){
        QFileInfo file("images/persogrille2.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    playerTexture.setSmooth(true);
    //player.setTexture(&playerTexture);


    //ENNEMY TEXTURE
    if(!enemyTexture1.loadFromFile("images/ogre.png")){
        QFileInfo file("images/skeletona.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    enemyTexture1.setSmooth(true);

    if(!enemyTexture2.loadFromFile("images/Serpent.png")){
        QFileInfo file("images/Serpent2.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    enemyTexture2.setSmooth(true);

    //PROJECTILE TEXTURE
    sf::Texture projectileTexture;
    if(!projectileTexture.loadFromFile("images/Boule_Feu.png")){
        QFileInfo file("images/Boule_Feu.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }


    /*PLAYER*/
    //Animation animation(&playerTexture, sf::Vector2u(9,5),0.3f);
    Player player(&playerTexture, sf::Vector2u(4,3),0.1f,350.0f,500.0f);

    /*PROJECTILE*/
    std::vector<Projectile> projectileVector;

    /*ENEMY*/
    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy(&enemyTexture2,sf::Vector2u(4,4), sf::Vector2f(150,200),sf::Vector2f(3100.0f,425.0f),0.2f,150.0f));
    enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(300,350),sf::Vector2f(3050.0f,425.0f),0.1f,250.0f));
    enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(100,100),sf::Vector2f(2900.0f,425.0f),0.1f,350.0f));

    /*PLATFORM*/
    std::vector<Platform> platforms;
    //Methode pour lire les platforms
    readPlatform(platforms);

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
        /*Ennemi en mvt*/
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


        /*Gestion des collisions avec la platforme*/
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

        /*Gestion collision avec les items*/
        for(Item& item : items) // for each
        {
            if(item.GetCollider().CheckCollect(player.GetCollider())){
                item.setPos(sf::Vector2f(0.00f,0.00f));
             }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){


            if( player.GetFaceRight())
            {
                 Projectile newProjectile(&projectileTexture,sf::Vector2f(20,70),2);
                 newProjectile.setPosition(sf::Vector2f(player.GetPosition()));
                 projectileVector.push_back(newProjectile);
            }
            else
            {
                 Projectile newProjectile(&projectileTexture,sf::Vector2f(20,70),-2);
                 newProjectile.setPosition(sf::Vector2f(player.GetPosition()));
                 projectileVector.push_back(newProjectile);
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

        for(int i=0;i< projectileVector.size();i++)
        {
            if(projectileVector[i].GetPosition().x>( player.GetPosition().x*4)){
                projectileVector.erase(projectileVector.begin()+i);
            }
            else
            {
                projectileVector[i].Draw(window);
                projectileVector[i].fire();
            }

        }

      //  qDebug() << player.GetPosition().x << player.GetPosition().y;
       // qDebug() << view.getCenter().x << view.getCenter().y;
/*        platform1.Draw(window);
        platform2.Draw(window);*/
        window.display();
    }
    return 0;
}
