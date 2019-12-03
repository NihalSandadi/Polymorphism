// ------------------------------------------------ Transactions.h--------------------------------------------------------
// Jayden Stipek Nihal CSS 343 B
// Creation: 11/20/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - The Driver for the Store (Reads in files and executes commands)
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Has a vector for all types of Transaction
//		Genres include (Inventory(I), History(H),Return(R), and Borrow(B))
//		Reads in files and creates movie, customer, and transaction obbjects
//		Afterwards executes commands for each Transaction created
// 
// -----------------------------------------------------------------------------------------------------------------
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
	~Transaction() {};
	Transaction(char); // inventory
	char getCommand() const;
	void setCommand(char Command);
	Customer* getTargetCustomer() const;
	void setTargetCustomer(Customer* TargetCustomer);
	Movie* getTargetMovie() const;
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
private:
	bool clear();
};
