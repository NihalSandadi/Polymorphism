// StoreDriver class

#ifndef ASSIGNMENT4_STOREDRIVER_H
#define ASSIGNMENT4_STOREDRIVER_H

#include <string>

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
    MovieDatabase* MoviesDatabase; // done
    // TransactionDatabase* Transactions;
    vector<string> split(const string& s, char delimiter)
    void parseMovies();
    void parseCustomers();
};

#endif //ASSIGNMENT4_STOREDRIVER_H
