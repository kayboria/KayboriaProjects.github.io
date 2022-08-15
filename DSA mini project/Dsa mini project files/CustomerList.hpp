#ifndef CustomerList_H
#define CustomerList_H
#include <iostream>
#include "Customer.hpp"

using namespace std;

class CustomerList
{
private:
    Customer *head;
    Customer *tail;

public:
    CustomerList();
    ~CustomerList();

    void insertNode(int, string, long);
    bool findCustomer(int);
    bool logMessage(int);
    void displayList();
};
#endif