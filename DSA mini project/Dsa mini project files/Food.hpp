#ifndef Food_H
#define Food_H

#include <iostream>

using namespace std;

class Food
{
public:
    string name;
    int id;
    int price;
    Food *next;

    Food(string, int, int);

    //Display function to show the id, price and name of the food
    void displayinfo();
};
#endif