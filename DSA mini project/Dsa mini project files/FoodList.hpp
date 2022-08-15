#ifndef foodlist_H
#define foodlist_H
#include "Food.hpp"
#include <iostream>
using namespace std;

class FoodList
{
    Food *head;
    Food *tail;

public:
    FoodList();
    ~FoodList();

    void insertNode(string, int, int);
    bool findFood(int);
    bool printReciet(int,int&);
    void displayList();
};
#endif
