#include "Customers.h"

// default constructor
Customer::Customer()
{
	CustomerId = 0;
	FirstName = "";
	LastName = "";
	History = {};
}

// deconstructor for customer
Customer::~Customer()
{
	History.clear();
}

// shows all the transactions the customer has made
void Customer::showHistory()
{
	cout << endl << "History of: ";
	cout << this->CustomerId << "-" << this->FirstName << " "
		<< this->LastName << endl;

	if (History.size() == 0)
	{
		cout << "NO HISTORY" << endl;
	}

	for (auto Item : History)
	{
		cout << *Item << endl;
	}
}

// Add a transaction to the history Vector
void Customer::updateHistory(Transaction* newT)
{
	History.push_back(newT); //history is just a queue

	// for further implementation
	// takes into account of currently borrowed movies
	/*
	if (newT.getCommand() == 'B')
	{
		CurrentlyBorrowed.push_back(newT.getTargetMovie());
	}else if (newT.getCommand() == 'R')
	{
		vector<Movie*>::iterator It;
		int Index = 0;
		for (It = CurrentlyBorrowed.begin(), It != CurrentlyBorrowed.end(),
			It++, ++Index)
		{
			if (newT.getTargetMovie() == CurrentlyBorrowed[Index])
			{
				CurrentlyBorrowed.erase(It);
			}
		}
	}
	*/
}

void Customer::deleteHistory(Transaction* T)
{/*
	vector<Transaction*>::iterator It;
	It = find(History.begin(), History.end(), T);
	for (auto X : History) {
		if (X == T) {
			History.erase(It);
			break;
		}
	}
	T = nullptr;*/
}

// Displays the customer information formatted
void Customer::display()
{
	cout << setw(8) << this->CustomerId << " " <<
		setw(30) << this->FirstName <<
		" " << this->LastName;
}

// Displays the customer information formatted
// using an ostream object
ostream& operator<<(ostream& Os, Customer* o)
{
	Os << setw(8) << o->CustomerId << " " <<
		setw(30) << o->FirstName <<
		" " << o->LastName;
	return Os;
}
