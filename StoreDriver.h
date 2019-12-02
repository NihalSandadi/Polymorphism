// StoreDriver class

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
#include "BST.cpp"

using namespace std;

class HashMapDatabase;
class TransactionDatabase;

class StoreDriver
{
public:
  StoreDriver();
  ~StoreDriver();
  bool readMovies(string File); // done
  bool readCustomers(string File);
	void printMovies();
  // void printCustomers();
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
  vector<Comedy*> unorderedComedy;
  vector<Classic*> unorderedClassic;
  vector<Drama*> unorderedDrama;

  HashMapDatabase* Customers;
  TransactionDatabase* Transactions;
	vector<string> split(const string& s, char delimiter);
  void parseMovies();
  void parseCustomers();
};
