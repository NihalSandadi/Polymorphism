//Customers.h

#pragma once
#include <string>
#include <vector>
#include  <iomanip>
#include "Transactions.h"

using namespace std;

// forward declaration
class Transaction;
class Movie;

class Customer
{
	// friend ostream& operator<<(ostream& Os, Customer* o);
public:
	Customer();
	int CustomerId;
	string FirstName;
	string LastName;
	void showHistory();
	void updateHistory(Transaction*);
private:
	vector<Transaction*> History;
	//vector<Movie*> CurrentlyBorrowed; not implementing atm
};
