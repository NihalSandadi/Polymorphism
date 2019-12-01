#include "Transactions.h"

Transaction::Transaction()
{
	TargetCustomer = nullptr;
	TargetMovie = nullptr;
	Command = '\0';
}

Transaction::~Transaction()
{
	delete TargetMovie;
	delete TargetCustomer;
}

// showInventory
Transaction::Transaction(char Type)
{
	if (Type != 'I' || Type != 'H' || Type != 'R' || Type != 'B')
		throw "BAD COMMAND";

	Command = Type;
	TargetCustomer = nullptr;
	TargetMovie = nullptr;
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

bool Transaction::execute()
{
	if (Command == 'I')
	{
		// printMovies(); // possible redundent inheritance
	// borrow
	}else if (Command == 'B')
	{
		this->TargetMovie->decreaseQuantity();
		this->TargetCustomer->updateHistory(*this);
	// return
	}else if (Command == 'R')
	{
		this->TargetMovie->increaseQuanity();
		this->TargetCustomer->updateHistory(*this);
	// history
	}else if (Command == 'H')
	{
		this->TargetCustomer->.showHistory();
	}else
	{
		return false;
	}
	return true;
}

/*
ostream& Transaction::operator<<(ostream& Os, const Transaction& T)
{
	return Os;
}
*/


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

bool TransactionDatabase::clear()
{
	while (!Transactions.empty())
	{
		Transactions.pop();
	}
	return true;
}
