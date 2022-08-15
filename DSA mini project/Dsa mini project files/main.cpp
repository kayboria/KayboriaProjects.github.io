#include <iostream>
#include <fstream>
#include <windows.h>
#include "Customer.hpp"
#include "Food.hpp"
#include "Admin.hpp"
#include "FoodList.hpp"
#include "CustomerList.hpp"
using namespace std;

//function to read the food file, it reades id, price and name of the food and sets it.
//files operation is used

int ReadFood(FoodList &a)
{
    fstream file;
    file.open("Food.txt", ios::in);
    int size = 0;
    int id, price;
    string name;
    while (!file.eof())
    {
        file >> id;
        file >> price;
        getline(file, name);
        a.insertNode(name, id, price);

        size++;
    }

    return size;
}

//function for insertion sort to sort foods id
void InsertionSort(int a[], int n)

{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

//this function is to read customer from the file.
//does the same thing as read food function
int ReadCustomer(CustomerList &a)
{
    fstream file;

    file.open("Customers.txt", ios::in);
    int size = 0, id;
    long phno;
    string name;
    while (!file.eof())
    {
        file >> id;
        file >> phno;
        getline(file, name);
        a.insertNode(id, name, phno);
        size++;
    }
    return size;
}

// this menu is for admin to do the following operations
// the password for the admin is "password" itself
int dispAdminMenu()
{
    system("CLS");
    int a;
    cout << "Welcome! Please select your choice " << endl
         << "1. Show list of Customers" << endl
         << "2. Add Food" << endl
         << "3. Search food" << endl
         << "4. Search Customer" << endl
         << "5. Exit" << endl;
    cin >> a;
    return a;
}

// this menu is for customer to do the following operations
int DispCustMenu()
{
    system("CLS");
    int a;
    cout << "Welcome! Please select your choice " << endl
         << "1. Show Menu" << endl
         << "2. Show Receipt" << endl
         << "3. Exit" << endl;
    cin >> a;
    return a;
}

int main()
{
    //variables initialized

    FoodList fList;
    CustomerList cList;

    int c, a, sizea = 0, sizeb, y;
    int rec[100];
    fstream file;

    sizea = ReadFood(fList);
    sizeb = ReadCustomer(cList);
    //this is the first screen to run the app
    // we can select both admin and customer.
    //for admin, it will request for a password, and the password is "password" itself
    cout << " Are you a : " << endl
         << "1. Customer " << endl
         << "2. Admin" << endl;
    cin >> c;

    if (c == 1)
    {

    A:
        system("CLS");
        //variables initilized
        int p, id;
        string name;
        char any;
        long phno;
        //after pressing customer, this menu will be shown
        cout << "Welcome to our food ordering system !" << endl
             << "1. Existing Customer" << endl
             << "2. New Customer" << endl
             << "Please make a selection to continue :";
        cin >> p;
        if (p != 1 && p != 2)
        {
            cout << "Invalid Choice please try again!";
            goto A;
        }

        if (p == 2)
        {
            //for registering new customer
            cout << "Enter id  :";
            cin >> id;
            cin.ignore(100, '\n');
            cout << "Enter name : ";
            getline(cin, name);
            cout << "Enter Phone Number :";
            cin >> phno;
            file.open("Customers.txt", ios::out | ios::app);
            file << endl
                 << id << " " << phno << " " << name;
        }
        else if (p == 1)
        {
            //for existing customer which only requires cusotmer id
            int ec, flag = 0;
            cout << "Enter Customer id : ";
            cin >> ec;
            for (int k = 0; k < sizeb; k++)
            {
                if (cList.logMessage(k))
                {

                    goto here;
                }
            }
            if (flag == 0)
            {
                cout << "Sorry Invalid Customer ID !!";
                Sleep(1000);
                goto A;
            }
        }

    here:
        a = DispCustMenu();
        switch (a)
        {
        //for fod ordering
        //fd is food class object and by the object it gets the id, name and price of the food
        case 1:
        {
            int s = 1;
            cout << "\n****************MENU****************"
                 << "\nID\t Name\t\t        Price" << endl;

            fList.displayList();

            y = 0;
            while (s != 0)
            {
                //for ordering the food by food's id number
                // if the user enters 0, it terminates
                cout << "Choose your Orders (Press 0 once you are done)";
                cin >> s;
                rec[y] = s;
                y++;
            }
            InsertionSort(rec, y);

            cout << "Thank you for shopping with us!";
            cout << "\n Press any key and then press enter to continue";
            cin >> any;
            goto here;
            break;
        }
        case 2:
        {
            // for showing the order
            int total = 0;
            system("CLS");
            cout << "\n\n Thank you for using us as your preferred platform!!" << endl
                 << "Your order is : " << endl
                 << "\nID\t Name\t\t Price" << endl;
            for (int i = 0; i < y; i++)
            {
                fList.printReciet(rec[i],total);
            }
            cout << "Total Price :" << total << endl;
            break;
        }
        case 3:
        {
            cout << endl
                 << "Have a Nice Day!";
            break;
        }
        }
    }
    else if (c == 2)
    {
        //Admin
        //Admin password is "password" itself
        system("CLS");
        char any;
        char pas[20];
        int b;
        cout << "Enter Password : ";
        cin >> pas;
        if (strcmp(pas, "password") != 0)
        {
            cout << "ACCESS DENIED!!";
        }
        else
        {
        here2:
            b = dispAdminMenu();
            switch (b)
            {
            case 1:
            {
                cout << "\n\n************Customers************" << endl
                     << "ID\tName \tPhone" << endl;
                cList.displayList();

                cout << "\nPress anything and then press enter to continue";
                cin >> any;
                goto here2;
                break;
            }
            case 2:
            {
                // this case is for the admin to add new food to the food list
                int id, price;
                string name;
                cout << "Enter id  :";
                cin >> id;
                cin.ignore(100, '\n');
                cout << "Enter name : ";
                getline(cin, name);
                cout << "Enter price :";
                cin >> price;
                //files operation, to add new items to food.tx file
                file.open("Food.txt", ios::out | ios::app);
                file << id << " " << price << " " << name << endl;
                goto here2;
                break;
            }
            case 3:
            {
                //searching is used here
                //to search for the food identified by the food id
                int ec, flag = 0;
                cout << "\n\n Enter food id : ";
                cin >> ec;

                if (fList.findFood(ec))
                {

                    flag = 1;
                }

                if (flag == 0)
                {
                    cout << "Invalid ID";
                }
                cout << "\n Enter anything and then press enter to continue ! ";
                cin >> any;
                goto here2;
                break;
            }
            case 4:
            {
                //for searching the existing customer by using customer id
                int ec, flag = 0;
                cout << "\n\n Enter customer id : ";
                cin >> ec;

                if (cList.findCustomer(ec))
                {
                    // cout << "ID\tName \tPhone";
                    cout << endl;

                    flag = 1;
                }

                if (flag == 0)
                {
                    cout << "Invalid ID";
                }
                cout << "\n Enter anything to continue ! ";
                cin >> any;
                goto here2;
                break;
            }

            case 5:
            {
                cout << endl
                     << "Have a Nice Day!";
                break;
            }
            }
        }
    }
    system("pause");
    return 0;
}