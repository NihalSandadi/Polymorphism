//Customers.h

#pragma once
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Transaction;
class Movie;

class Customer
{
public:
    int CustomerId;
    string FirstName;
    string LastName;
    void showHistory();
    void updateHistory();
private:
    vector<Transaction*> History;
    vector<Movie*> CurrentlyBorrowed;
};

//class CustomerDatabase
//{
//public:
//    bool add(Customer* C);
//    bool remove(int ID);
//    Customer* getCustomer(int ID);
//    bool clear();
//private:
//    vector<Customer*> Customers; // Vector of customer pointers
//    int getHash(int ID);
//};


