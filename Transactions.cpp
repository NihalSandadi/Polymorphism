#include "Transactions.h"

// constructor
Transaction::Transaction()
{
	TargetCustomer = nullptr;
	TargetMovie = nullptr;
	Command = '\0';
}

Transaction::~Transaction()
{
		if (this->TargetCustomer != nullptr) {
			this->getTargetCustomer()->deleteHistory(this);
		}
}

// constructor taking a command type
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

// getter for the command
char Transaction::getCommand() const
{
	return this->Command;
}

// sets the command value
void Transaction::setCommand(char Command)
{
	this->Command = Command;
}

// getter returning the target customer
Customer* Transaction::getTargetCustomer() const
{
	return this->TargetCustomer;
}

// sets the customer value
void Transaction::setTargetCustomer(Customer* TargetCustomer)
{
	this->TargetCustomer = TargetCustomer;
}

// getter returning the target movie
Movie* Transaction::getTargetMovie() const
{
	return this->TargetMovie;
}

// sets the target movie
void Transaction::setTargetMovie(Movie* TargetMovie)
{
	this->TargetMovie = TargetMovie;
}

TransactionDatabase::TransactionDatabase() {}

TransactionDatabase::~TransactionDatabase()
{
	clear();
}

// adds to the transaction queue
bool TransactionDatabase::addTransaction(Transaction* Trans)
{
	if (Trans == nullptr) return false;
	Transactions.push(Trans);
	return true;
}

// deletes every transaction
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

// ostream overrider for cout
ostream& operator<<(ostream& Os, const Transaction &T)
{
	Movie* tempM = T.getTargetMovie();
	cout << T.getCommand()  << " ";
	tempM->display();
	//Os << T.getCommand() << " " << " " << tempC;
	return Os;
}
