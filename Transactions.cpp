#include "Transactions.h";

Transaction::Transaction()
{
}

Transaction::Transaction(char)
{
}

Transaction::Transaction(char, Customer*)
{
}

Transaction::Transaction(char, Customer*, Media*)
{
}

Transaction::~Transaction()
{
}

bool Transaction::execute()
{
	return false;
}

//ostream& Transaction::operator<<(ostream& Os, const Transaction& T)
//{
//	// TODO: insert return statement here
//}

TransactionDatabase::TransactionDatabase()
{
}

TransactionDatabase::~TransactionDatabase()
{
}

bool TransactionDatabase::executeTransactions()
{
	return false;
}

bool TransactionDatabase::clear()
{
	return false;
}
