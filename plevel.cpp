#include "plevel.h"

PLevel::PLevel(sf::RenderWindow* window): PGame(window)
{

    //platforms
        readPlatform(platforms,"level/platforms.txt");




        //ENNEMY TEXTURE
        if(!enemyTexture1.loadFromFile("images/ogre.png")){

        }
        enemyTexture1.setSmooth(true);

        if(!enemyTexture2.loadFromFile("images/Serpent.png")){

        }
        enemyTexture2.setSmooth(true);

        //PROJECTILE TEXTURE

        if(!projectileTexture.loadFromFile("images/Boule_Feu.png")){

        }

        //enemies
        enemies.push_back(new Enemy(&enemyTexture2,sf::Vector2u(4,4), sf::Vector2f(150,200),sf::Vector2f(3100.0f,425.0f),0.2f,150.0f));
        enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(300,350),sf::Vector2f(3050.0f,425.0f),0.1f,250.0f));
        enemies.push_back(new Enemy(&enemyTexture1,sf::Vector2u(4,4), sf::Vector2f(100,100),sf::Vector2f(2900.0f,425.0f),0.1f,350.0f));

        //ITEMS
        items.push_back(Item(sf::Vector2f(80,80),sf::Vector2f(570,420)));



}

PLevel::~PLevel()
{}

void PLevel::init()
{

    initDeltaTime();

    sf::Event event;
            while(mainWindow->pollEvent(event))
            {
                switch(event.type){
                case sf::Event::Resized:
                    ResizeView(*mainWindow,viewGame,VIEW_GAME);
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

                    aspectRatio = float(mainWindow->getSize().x)/float(mainWindow->getSize().y);

                            viewGame.setCenter(player.GetPosition().x,player.GetPosition().y-200);


                            if(viewGame.getCenter().x<(VIEW_GAME*aspectRatio)/2){
                                viewGame.setCenter((VIEW_GAME*aspectRatio)/2,viewGame.getCenter().y);
                            }

                            if(viewGame.getCenter().y>0){
                                viewGame.setCenter(viewGame.getCenter().x,0);
                            }


                         mainWindow->setView(viewGame);
                         player.Draw(*mainWindow);


                            for(int i=0;i<enemies.size();i++)
                            {
                                enemies[i]->Draw(*mainWindow);
                            }


                            for(Platform& platform : platforms){
                                platform.Draw(*mainWindow);
                            }

                            for(Item item : items){
                                item.Draw(*mainWindow);
                            }

                            for(int i=0;i< projectileVector.size();i++)
                            {
                                if(projectileVector[i].GetPosition().x>( player.GetPosition().x*4)){
                                    projectileVector.erase(projectileVector.begin()+i);
                                }
                                else
                                {
                                    projectileVector[i].Draw(*mainWindow);
                                    projectileVector[i].fire();
                                }

                            }
                            keyPressedOnce();

}



PLevel::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PMENU);
    }
}

void PLevel::initDeltaTime(){
 deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f /20.0f){
            deltaTime = 1.0f /20.0f;
        }
}
