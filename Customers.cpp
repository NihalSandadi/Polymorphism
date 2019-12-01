#include "Customers.h"

Customer::Customer()
{
	CustomerId = 0;
	FirstName = "";
	LastName = "";
	History = {};
}

//shows all the transactions the customer has made
void Customer::showHistory()
{
	cout << this->CustomerId << "-" << this->FirstName << " " << this->LastName << endl;
	for (auto history : History)
	{
		// cout << history << endl;
		// error here error: invalid operands to binary
		//expression ('ostream' (aka 'basic_ostream<char>') and 'Transaction')
	}
}

//Add a transaction to the history Vector
void Customer::updateHistory(Transaction newT)
{
	History.push_back(newT); //history is just a queue
}
