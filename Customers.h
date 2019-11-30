//Customers.h

#pragma once
#include <string>
#include <vector>
#include "Transactions.h"

using namespace std;
// forward declaration
class Transaction;
class Movie;

class Customer
{
public:
	int CustomerId;
	string FirstName;
	string LastName;
	void showHistory();
	void updateHistory(Transaction);
private:
	vector<Transaction> History;
	//vector<Movie*> CurrentlyBorrowed; not implementing atm 
};


