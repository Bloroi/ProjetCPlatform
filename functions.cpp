#include "functions.h"
#include <iostream>

using namespace std;
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

void lirePlatform(vector<Platform>& platforms){
    string a,b,c,d,e,f;
    float b1,c1,d1,e1;

    std::ifstream infile("level/platforms.txt");

    getline(infile,a,',');
    getline(infile,b,',');
    getline(infile,c,',');
    getline(infile,d,',');
    getline(infile,e,';');
    getline(infile,f,'\n');

   std::cout<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<endl;

       b1 = std::stof(b);
       c1 = std::stof(c);
       d1 = std::stof(d);
       e1 = std::stof(e);
       platforms.push_back(Platform(a,sf::Vector2f(b1,c1),sf::Vector2f(d1,e1)));

     while (a!=""){

         std::cout<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<endl;

             b1 = std::stof(b);
             c1 = std::stof(c);
             d1 = std::stof(d);
             e1 = std::stof(e);
              platforms.push_back(Platform(a,sf::Vector2f(b1,c1),sf::Vector2f(d1,e1)));

         getline(infile,a,',');
         getline(infile,b,',');
         getline(infile,c,',');
         getline(infile,d,',');
         getline(infile,e,';');
         getline(infile,f,'\n');
     }
}




ostream& operator<<(ostream& os, const Platform& p)
{
    os <<p.filename<<","<<p.body.getSize().x <<","<<  p.body.getSize().y <<","<<p.body.getPosition().x<<","<<p.body.getPosition().y<<";"<<endl;
    return os;
}
