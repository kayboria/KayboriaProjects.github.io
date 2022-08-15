#include "Customer.hpp"
#include <iostream>

using namespace std;
Customer::Customer(int _id, string _name, long _phno)
{
    name = _name;
    id = _id;
    phno = _phno;
    next = NULL;
}

void Customer::displayinfo()
{
    cout << id << "\t" << name << "\t" << phno << endl;
}