#include "FoodList.hpp"
#include "Food.hpp"
#include <iostream>
using namespace std;

FoodList::FoodList()
{
    head = NULL;
    tail = NULL;
}

FoodList::~FoodList()
{
    Food *currNode = head;
    Food *nextNode = NULL;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    head = NULL;
}

void FoodList::insertNode(string name, int id, int price)
{

    Food *temp = new Food(name, id, price);
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void FoodList::displayList()
{
    Food *curr = head;
    while (curr != NULL)
    {
        curr->displayinfo();
        curr = curr->next;
    }
}

bool FoodList::printReciet(int i,int &total)
{
    Food *temp = head;

    while (temp != NULL)
    {
        if (temp->id == i)
        {
            cout << temp->id << "\t" << temp->name << "\t" << temp->price << endl;

            total += temp->price;
            
        }
        temp = temp->next;
    }

    return false;
}

bool FoodList::findFood(int i)
{
    Food *temp = head;

    while (temp != NULL)
    {
        if (temp->id == i)
        {
            cout << "\nID\t Name\t\t        Price" << endl;

            temp->displayinfo();
            return true;
        }
        temp = temp->next;
    }

    return false;
}