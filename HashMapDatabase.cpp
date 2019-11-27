#include "HashMapDatabase.h"

//Add a customer to the hashtable of customers
bool HashMapDatabase::add(Customer* C)
{
	if (Customers[C->CustomerId] == nullptr)
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
	if (Customers[ID] != nullptr)
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
	Customer* temp = Customers[ID];
	return temp;
}

bool HashMapDatabase::clear()
{
	return false;
}

int HashMapDatabase::getHash(int ID)
{
	return ID;
}
