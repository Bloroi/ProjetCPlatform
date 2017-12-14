#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "platform.h"
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

ostream& operator<<(ostream& os, const Platform& p);
//istream& operator>>(istream& is, Platform& p);
void readPlatform(vector<Platform>& platforms);


#endif // FUNCTIONS_H
