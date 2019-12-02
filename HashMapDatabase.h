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
private:
	const int HASHSIZE = 10000;
	vector<Customer*> Customers; // Hashtable of customer pointers
	int getHash(int ID); //hashing the int
};
