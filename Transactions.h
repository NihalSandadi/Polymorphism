// Transaction and TransactionDatabase classes

#pragma once
#include <iostream>
#include <queue>
#include <string>

using namespace std;

//forward declaration
class Customer;
class Media;

class Transaction
{
public:
    Transaction();
    Transaction(char);
    Transaction(char, Customer*);
    Transaction(char, Customer*, Media*);
    ~Transaction();
    bool execute();
    //ostream& operator<<(ostream& Os, const Transaction& T);
};

class TransactionDatabase
{
public:
    TransactionDatabase();
    ~TransactionDatabase();
    bool executeTransactions();
private:
    queue<Transaction*> Transactions;
    bool clear();
};

