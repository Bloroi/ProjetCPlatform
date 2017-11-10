#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include "player.h"
#include "coin.h"
#include <sstream>
#include <SFML/Audio.hpp>


/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/

int main(int argc, char *argv[]){
    //sf::RenderWindow window(sf::VideoMode(800,600),"Hello Window");
    //COUCOU je m'apelle Logan
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width/2)-445,(sf::VideoMode::getDesktopMode().height/2)-200);

    window.create(sf::VideoMode(700,500),"ProjectVideoGame",sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    sf::Texture perso;
    sf::Sprite sprite;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.
    sf::SoundBuffer buffer;
    sf::SoundBuffer coinB;
    sf::Sound sound;
    sf::Sound coinS;
    sf::Music music;


    if(!music.openFromFile("music/music.wav")){
        QFileInfo file("music/music.wav");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas ou n'est pas compatible !";
    }
    music.play();
    music.setLoop(true);

    if(!buffer.loadFromFile("music/jump.wav")){
        QFileInfo file("music/jump.wav");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas ou n'est pas compatible !";
    }
    sound.setBuffer(buffer);

    if(!coinB.loadFromFile("music/coin.wav")){
        QFileInfo file("music/coin.wav");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas ou n'est pas compatible !";
    }
    coinS.setBuffer(coinB);


    if(!backgroundTexture.loadFromFile("images/background.png")){
        QFileInfo file("images/background.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas ou n'est pas compatible !";
    }else{
        TextureSize = backgroundTexture.getSize(); //Size de la texture
        WindowSize = window.getSize();

        float ScaleX = (float) WindowSize.x/TextureSize.x;
        float ScaleY = (float) WindowSize.y/TextureSize.y;

        background.setTexture(backgroundTexture);
        background.setScale(ScaleX,ScaleY);
    }


    window.setKeyRepeatEnabled(true);

    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(50,200));
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color(33,42,231,255));

    if(!perso.loadFromFile("images/player.png")){
        QFileInfo file("images/player.png");
        qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
    }
    perso.setSmooth(true);

    sprite.setTexture(perso);

    //Player OBJECT
    Player player;
    player.setPos({50,200});

    //Coin OBJECT
    std::vector<Coin*> coinVec; // pointeur et référencement car nous voulons pouvoir supprimer,modifier l'objet coin quand le joueur le touche
    Coin coin1({20,20});
    Coin coin2({20,20});
    coinVec.push_back(&coin1);
    coinVec.push_back(&coin2);

    coin1.setPos({375,350});
    coin2.setPos({250,375});

    //Score Objects :
    int score = 0;

    sf::Font arial;
    arial.loadFromFile("styles/arial.ttf");


    std::ostringstream ssScore;
    ssScore <<"Score : " <<score;

    sf::Text lblScore;
    lblScore.setCharacterSize(30);
    lblScore.setPosition({10,10});
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());



    //Gravity variables :
    const int groundHeight = 400;
    const float gravitySpeed = 0.3;
    bool isJumping = false;




    while (window.isOpen()){
        sf::Event Event;

        const float moveSpeed = 0.2;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            player.move({0,-moveSpeed});
            //sound.play();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        player.move({moveSpeed,0});

                    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        player.move({-moveSpeed,0});

                    }
            isJumping = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            player.move({moveSpeed,0});

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            player.move({-moveSpeed,0});

        }


        //Event Loop:
        while(window.pollEvent(Event)){
            switch(Event.type){
            case sf::Event::Closed:
                window.close();

            case sf::Event::KeyReleased:
                isJumping = false;
            }

            if(Event.key.code == sf::Keyboard::Space){
                isJumping=false;
            }

        }

        //Gravity Logic

        if(player.getY()<groundHeight && isJumping==false){
            player.move({0,gravitySpeed});
        }

        //Coin Logic
        for(int i = 0 ;i<coinVec.size();i++){
            if(player.isCollidingWithCoin(coinVec[i])){
                coinVec[i]->setPos({4000,4000});
                //coinVec.erase(coinVec.begin()+i-1);
                coinS.play();
                score++;
                ssScore.str("");
                ssScore << "Score : "<<score;
                lblScore.setString(ssScore.str());
            }
        }
        window.clear();
        window.draw(background);
        window.draw(lblScore);
        coin1.drawTo(window);
        coin2.drawTo(window);
        player.drawTo(window);
        window.draw(rect);
        window.display();

    }
    return 0;
}
