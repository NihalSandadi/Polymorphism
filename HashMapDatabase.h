// ------------------------------------------------ HashMapDatabase.h --------------------------------------------------------
// Jayden Stipek Nihal CSS 343 B
// Creation: 10/25/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Encapsulate customer data
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Uses a hashmap implemented as a vector
//		Hash perfect hashing due to their being unique ID's
//		Able to add customers, remove, and other information as needed
// -----------------------------------------------------------------------------------------------------------------
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
