#include "Customers.h"

//shows all the transactions the customer has made
void Customer::showHistory()
{
}

//Add a transaction to the history Vector 
void Customer::updateHistory()
{
	//implement once we have transactions done
	//History.push_back(this);
}

//Add a customer to the hashtable of customers
bool CustomerDatabase::add(Customer* C)
{
	if (Customers[C->CustomerId] == nullptr)
	{
		Customers[C->CustomerId] = C;
		return true;
	}
	else
	{
		//already inside hashmap
		return false;
	}
}

//Removes  the customer from the database
bool CustomerDatabase::remove(int ID)
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

//Get the customer pointer out of the hasttable
Customer* CustomerDatabase::getCustomer(int ID)
{
	//this works in case of nullptr too because this will return nullptr
	Customer *temp = Customers[ID];
	return temp;
}

//clear the entire database
bool CustomerDatabase::clear()
{
	//for every customer inside the database remove it
	for(auto& customer : Customers)
	{
		remove(customer->CustomerId);
	}
	return true;
	
}

//get the hash from the id (not implemented)
int CustomerDatabase::getHash(int ID)
{
	return ID;
}
