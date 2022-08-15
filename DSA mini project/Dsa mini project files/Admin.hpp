#ifndef Admin_H
#define Admin_H
#include <iostream>

using namespace std;

class Admin
{
private:
    int id, type;
    string position, name;

public:
    Admin();

    // constructor with arguments
    Admin(int i, string n, int t, string e);

    //Accessors and mutators

    void setID(int a);

    int getID();

    void SetType(int a);

    int getType();

    void SetPosition(string a);

    string getPosition();

    void setName(string a);

    string getName();
};
#endif