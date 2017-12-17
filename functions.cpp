#include "functions.h"
#include <iostream>

using namespace std;

sf::Music music;
/*
istream& operator>>(istream& is, Platform& p)
{
   //cout<<p.body.getSize().x;<<std::endl;

    is >> p.body.getSize().x;
    is >> p.body.getSize().y;
    is >> p.body.getOrigin().x;
    is >> p.body.getOrigin().y;
    is >> p.body.getTexture();
    is >> p.body.getPosition().x;
    is >> p.body.getPosition().y;
    return is;
}*/

/** Cette méthode permet de lire dans un fichier txt les informations sur les plateformes**/
void readPlatform(vector<Platform>& platforms,string filepath){
    string a,b,c,d,e,f,g;
    float c1,d1,e1,f1;

    std::ifstream infile(filepath);

    getline(infile,a,',');
    getline(infile,b,',');
    getline(infile,c,',');
    getline(infile,d,',');
    getline(infile,e,',');
    getline(infile,f,';');
    getline(infile,g,'\n');

     while (a!=""){

        std::cout<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<"|"<<f<<endl;

        c1 = std::stof(c);
        d1 = std::stof(d);
        e1 = std::stof(e);
        f1 = std::stof(f);
        platforms.push_back(Platform(a,b,sf::Vector2f(c1,d1),sf::Vector2f(e1,f1)));

        getline(infile,a,',');
        getline(infile,b,',');
        getline(infile,c,',');
        getline(infile,d,',');
        getline(infile,e,',');
        getline(infile,f,';');
        getline(infile,g,'\n');
     }
}



/** Cette méthode permet d'écrire des plateformes dans un fichier txt**/
ostream& operator<<(ostream& os, const Platform& p)
{
    os <<p.name<<","<<p.filename<<","<<p.body.getSize().x <<","<<  p.body.getSize().y <<","<<p.body.getPosition().x<<","<<p.body.getPosition().y<<";"<<endl;
    return os;
}


