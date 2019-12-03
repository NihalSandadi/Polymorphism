#include "HashMapDatabase.h"

// constructor
HashMapDatabase::HashMapDatabase()
{
	//used for hashing function
	Customers.resize(HASHSIZE);
}

// destructor
HashMapDatabase::~HashMapDatabase()
{
	for (auto &Customer : Customers)
	{
		delete Customer; //delete all customers inside the database
	}
}

// Add a customer to the hashtable of customers
bool HashMapDatabase::add(Customer* C)
{
	if (getCustomer(C->CustomerId) == nullptr)
	{
		Customers[C->CustomerId] = C;
		return true;
	}
	//already inside hashmap
	return false;
}

bool HashMapDatabase::remove(int ID)
{
	//might cause a memoryleak
	if (getCustomer(ID) != nullptr)
	{
		Customer* temp = Customers[ID];
		delete(temp);
		Customers[ID] = nullptr;
		return true;
	}
	//does not exist
	return false;
}

Customer* HashMapDatabase::getCustomer(int ID)
{
	//this works in case of nullptr too because this will return nullptr
	int index = getHash(ID);
	Customer* temp = Customers[index];
	return temp;
}

//clears the entire Map of customer pointers
bool HashMapDatabase::clear()
{
	for (auto& Customer : Customers)
	{
		delete Customer;
	}
	return true;
}

int HashMapDatabase::getHash(int ID)
{
	return ID;
}


void HashMapDatabase::printAllCustomers()
{
	cout << "CUSTOMERS:" << endl;
	for (auto X : Customers)
		cout << X << endl;
}

