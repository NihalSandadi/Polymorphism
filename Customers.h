// ------------------------------------------------ Customers.h --------------------------------------------------------
// Jayden Stipek Nihal CSS 343 B
// Creation: 10/25/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Encapsulate customer functions
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Able to Show the history of a customer
//		Able to Update the history of the function
// -----------------------------------------------------------------------------------------------------------------

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
