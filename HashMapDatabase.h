//HashMapDatabase (aka Customers database)

#pragma once
#include <string>
#include <vector>
#include "Customers.h"

class HashMapDatabase
{
public:
	bool add(Customer* C);
	bool remove(int ID);
	Customer* getCustomer(int ID);
	bool clear();
private:
	vector<Customer*> Customers; // Vector of customer pointers
	int getHash(int ID);
};
