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
#include "MovieDatabase.h"
#include "hashmapDatabase.h"
using namespace std;

class HashMapDatabase;
class MovieDatabase;
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
    HashMapDatabase* Customers;
    MovieDatabase* Movies; // done
    // TransactionDatabase* Transactions;
	vector<string> split(const string& s, char delimiter);
    void parseMovies();
    void parseCustomers();
};

