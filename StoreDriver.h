// ------------------------------------------------ StoreDriver.h--------------------------------------------------------
// Jayden Stipek Nihal CSS 343 B
// Creation: 11/20/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - The Driver for the Store (Reads in files and executes commands)
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Has a BST for each genre
//		Genres include (Drama(D), Comedy(F), and Classic(C))
//		Reads in files and creates movie, customer, and transaction obbjects
//		Afterwards executes commands for each Transaction created
//
// Inputs:	data4commands.txt
//			data4customers.txt
//			data4movies.txt
// -----------------------------------------------------------------------------------------------------------------

#pragma once
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Media.h"
#include "HashMapDatabase.h"
#include "Transactions.h"
#include "BST.cpp"

using namespace std;

class StoreDriver
{
public:
  StoreDriver();
  ~StoreDriver();
  bool readMovies(string File); // done
  bool readCustomers(string File);
	void printMovies();
   void printCustomers();
  Movie* getMovie(char, char, string, string, int);
  bool executeTransaction(Transaction*);
  bool executeTransactions();
  bool readTransactions(string File);
  string toStringTransactions();
  void showCustomerHistory(Customer*);
private:
	BST<Comedy*>* comedyBST; //comedy stores all comedy movies
	BST<Classic*>* classicBST; //classic stores all classic movies
	BST<Drama*>* dramaBST; //drama stores all drama movies
	 HashMapDatabase* Customers;
  TransactionDatabase* Transactions;
	vector<string> split(const string& s, char delimiter);
  void parseMovies();
  void parseCustomers();
};
