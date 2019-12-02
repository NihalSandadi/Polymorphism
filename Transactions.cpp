#include "Transactions.h"

Transaction::Transaction()
{
	TargetCustomer = nullptr;
	TargetMovie = nullptr;
	Command = '\0';
}

// showInventory
Transaction::Transaction(char Type)
{
	if (Type == 'I' || Type == 'H' || Type == 'R' || Type == 'B')
	{
		cout << "BAD COMMAND" << endl;
	}else
	{
		Command = Type;
		TargetCustomer = nullptr;
		TargetMovie = nullptr;
	}
}

char Transaction::getCommand()
{
	return this->Command;
}

void Transaction::setCommand(char Command)
{
	this->Command = Command;
}

Customer* Transaction::getTargetCustomer()
{
	return this->TargetCustomer;
}

void Transaction::setTargetCustomer(Customer* TargetCustomer)
{
	this->TargetCustomer = TargetCustomer;
}

Movie* Transaction::getTargetMovie()
{
	return this->TargetMovie;
}

void Transaction::setTargetMovie(Movie* TargetMovie)
{
	this->TargetMovie = TargetMovie;
}

TransactionDatabase::TransactionDatabase()
{
	Transactions;
}

TransactionDatabase::~TransactionDatabase()
{
	clear();
}

bool TransactionDatabase::addTransaction(Transaction* Trans)
{
	if (Trans == nullptr) return false;
	Transactions.push(Trans);
	return true;
}

/* // Moved to Store Driver
bool TransactionDatabase::executeTransactions()
{
	while (!Transactions.empty())
	{
		if (Transactions.front() == nullptr) return false;
		Transactions.front()->execute();
		Transactions.pop();
	}
	return true;
}
*/

bool TransactionDatabase::clear()
{
	while (!Transactions.empty())
	{
		Transaction* Temp = Transactions.front();
		Transactions.pop();
		delete Temp;
	}

	return true;
}
