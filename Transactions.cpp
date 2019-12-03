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
		Command = Type;
		TargetCustomer = nullptr;
		TargetMovie = nullptr;
	}else
	{
		cout << "BAD COMMAND" << Type << endl;
	}
}

char Transaction::getCommand() const
{
	return this->Command;
}

void Transaction::setCommand(char Command)
{
	this->Command = Command;
}

Customer* Transaction::getTargetCustomer() const
{
	return this->TargetCustomer;
}

void Transaction::setTargetCustomer(Customer* TargetCustomer)
{
	this->TargetCustomer = TargetCustomer;
}

Movie* Transaction::getTargetMovie() const
{
	return this->TargetMovie;
}

void Transaction::setTargetMovie(Movie* TargetMovie)
{
	this->TargetMovie = TargetMovie;
}

TransactionDatabase::TransactionDatabase()
{
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

ostream& operator<<(ostream& Os, const Transaction &T)
{
	Movie* tempM = T.getTargetMovie();
	Customer* tempC = T.getTargetCustomer();

	Os << T.getCommand() << " " << tempM << " " << tempC;
	return Os;
}
