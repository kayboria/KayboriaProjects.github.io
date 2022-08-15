#include "Admin.hpp"
#include <iostream>

using namespace std;

Admin::Admin()
{
    id = 0;
    type = 0;
    position = " ";
    name = " ";
}
// constructor with arguments
Admin::Admin(int i, string n, int t, string e)
{
    id = i;
    type = t;
    position = e;
    name = n;
}

//Accessors and mutators
void Admin::setID(int a)
{
    id = a;
}
int Admin::getID()
{
    return id;
}
void Admin::SetType(int a)
{
    type = a;
}
int Admin::getType()
{
    return type;
}
void Admin::SetPosition(string a)
{
    position = a;
}
string Admin::getPosition()
{
    return position;
}
void Admin::setName(string a)
{
    name = a;
}
string Admin::getName()
{
    return name;
}