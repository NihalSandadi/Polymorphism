//HashMapDatabase (aka Customers database)

#pragma once
#include "Customers.h"

class HashMapDatabase
{
public:
	HashMapDatabase();
	~HashMapDatabase();
	bool add(Customer* C);
	bool remove(int ID);
	Customer* getCustomer(int ID);
	bool clear();
	// void printAllCustomers();
	vector<Customer*> Customers; // Hashtable of customer pointers
private:
	const int HASHSIZE = 10000;

	int getHash(int ID); //hashing the int
};
