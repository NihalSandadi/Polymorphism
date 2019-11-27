// StoreDriver class

#pragma once
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include "Media.h"
#include "MovieDatabase.h"

using namespace std;

class CustomerDatabase;
class MovieDatabase;
class TransactionDatabase;

class StoreDriver
{
public:
    StoreDriver();
    ~StoreDriver();
    bool readMovies(string File); // done
    bool readCustomers(string File);
    // bool readTransactions(string File);
    // bool executeTransactions();
private:
    CustomerDatabase* Customers;
    MovieDatabase* Movies; // done
    // TransactionDatabase* Transactions;
	vector<string> split(const string& s, char delimiter);
    void parseMovies();
    void parseCustomers();
};

