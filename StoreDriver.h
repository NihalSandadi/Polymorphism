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
    // bool readTransactions(string File);
    // bool executeTransactions();
private:
	BST<Comedy*>* comedyBST; //comedy stores all comedy movies
	BST<Classic*>* classicBST; //classic stores all classic movies
	BST<Drama*>* dramaBST; //drama stores all drama movies

    HashMapDatabase* Customers;
    //MovieDatabase* Movies; // done
    // TransactionDatabase* Transactions;
	vector<string> split(const string& s, char delimiter);
    void parseMovies();
    void parseCustomers();
};

