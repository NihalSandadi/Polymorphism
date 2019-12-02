#include "Customers.h"

Customer::Customer()
{
	CustomerId = 0;
	FirstName = "";
	LastName = "";
}

//shows all the transactions the customer has made
void Customer::showHistory()
{
	cout << this->CustomerId << "-" << this->FirstName << " " << this->LastName << endl;
	for (Transaction history : History)
	{
		cout << history << endl;
	}
}

//Add a transaction to the history Vector 
void Customer::updateHistory(Transaction newT)
{
	History.push_back(newT); //history is just a queue
}
