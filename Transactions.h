// Transaction and TransactionDatabase classes

#pragma once
#include <iostream>
#include <queue>
#include <string>
/*
#include "Customers.h"
#include "StoreDriver.h"
*/

using namespace std;

//forward declaration
class Customer;
class Movie;
// class StoreDriver;

class Transaction
{
  friend ostream& operator<<(ostream& Os, const Transaction& T);
private:
  Customer* TargetCustomer;
  char Command;
  Movie* TargetMovie;
public:
    Transaction();
    ~Transaction();
    Transaction(char); // inventory
    char getCommand();
    void setCommand(char Command);
    Customer* getTargetCustomer();
    void setTargetCustomer(Customer* TargetCustomer);
    Movie* getTargetMovie();
    void setTargetMovie(Movie* TargetMovie);
    // bool execute(); // moved to store driver

};

class TransactionDatabase
{
public:
    TransactionDatabase();
    ~TransactionDatabase();
    bool addTransaction(Transaction*);
    queue<Transaction*> Transactions;
    // bool executeTransactions(); // moved to store driver
private:

    bool clear();
};
