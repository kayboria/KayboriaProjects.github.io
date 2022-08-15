#include "Food.hpp"
#include <iostream>

using namespace std;

Food::Food(string _name, int _id, int _price)
{
    name = _name;
    id = _id;
    price = _price;
    next = NULL;
}

//Display function to show the id, price and name of the food
void Food::displayinfo()
{
    cout << id << "\t" << name << "\t" << price << endl;
}