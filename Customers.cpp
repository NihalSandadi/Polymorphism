#include "Customers.h"

Customer::Customer()
{
	CustomerId = 0;
	FirstName = "";
	LastName = "";
	History = {};
	// CurrentlyBorrowed = {}
}

//shows all the transactions the customer has made
void Customer::showHistory() // BROKEN
{
	
	cout << this->CustomerId << "-" << this->FirstName << " "
		<< this->LastName << endl;
	if (History.size() == 0)
	{
		cout << "NO HISTORY" << endl;
	}
	for (auto Item : History)
	{
		cout << Item << endl;
	}
	
}

//Add a transaction to the history Vector
void Customer::updateHistory(Transaction* newT)
{
	History.push_back(newT); //history is just a queue

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

ostream &operator<<(ostream &Os, Customer* o)
{
	Os << setw(8) << o->CustomerId << " " <<
	setw(30) << o->FirstName <<
	" " << o->LastName;
	return Os;
}

