#include <iostream>
#include "Customer.hpp"
#include "CustomerList.hpp"
#include <windows.h>

using namespace std;

CustomerList::CustomerList()
{
    head = NULL;
    tail = NULL;
}

CustomerList::~CustomerList()
{
    Customer *currNode = head;
    Customer *nextNode = NULL;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    head = NULL;
}

void CustomerList::insertNode(int id, string name, long phon)
{

    Customer *temp = new Customer(id, name, phon);
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

void CustomerList::displayList()
{
    Customer *curr = head;
    while (curr != NULL)
    {
        curr->displayinfo();
        curr = curr->next;
    }
}

bool CustomerList::findCustomer(int i)
{
    Customer *temp = head;

    while (temp != NULL)
    {
        if (temp->id == i)
        {
            cout << "ID\tName \tPhone" << endl;
            temp->displayinfo();
            return true;
        }
        temp = temp->next;
    }

    return false;
}

bool CustomerList::logMessage(int i)
{
    Customer *temp = head;

    while (temp != NULL)
    {
        if (temp->id == i)
        {
            system("CLS");
            cout << "Wecome Back Mr/Mrs " << temp->name;
            Sleep(1500);

            return true;
        }
        temp = temp->next;
    }

    return false;
}