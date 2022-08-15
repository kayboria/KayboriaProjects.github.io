#ifndef Customer_H
#define Customer_H
#include <iostream>

using namespace std;

class Customer
{

public:
    int id;
    string name;
    long phno;
    Customer *next = NULL;
    Customer(int, string, long);
    void displayinfo();
};
#endif