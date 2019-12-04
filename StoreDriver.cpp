// StoreDriver.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include "StoreDriver.h"

// default constructor
StoreDriver::StoreDriver()
{
	comedyBST = new BST<Comedy*>();
	classicBST = new BST<Classic*>();
	dramaBST = new BST<Drama*>();
	Transactions = new TransactionDatabase();
	Customers = new HashMapDatabase();
}

// deconstructor
StoreDriver::~StoreDriver()
{
	delete dramaBST;
	delete comedyBST;
	delete classicBST;
	delete Transactions;
	delete Customers;
}

// code modified from https://www.fluentcpp.com
// /2017/04/21/how-to-split-a-string-in-c/
// splits a string into a vector of strings depending on the delimiter
vector<string> StoreDriver::split(const string& s, char delimiter)
{
	vector<std::string> tokens;
	string token;
	istringstream tokenStream(s);

	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}

// removes extra spaces at the front and back
string removeSpace(string old)
{
	int length = old.length();
	if (old[0] == *" ") { //front
		old = old.substr(1, length + 5);
	}
	if (old[length - 1] == *" ") { //back
		old = old.substr(0, length - 2);
	}
	return old;
}

// reading in the Movies
bool StoreDriver::readMovies(string File)
{
	MovieFactory MovFactory;
	ifstream InFile;
	string Line;

	// check for empty file
	InFile.open(File);
	if (!InFile) {
		cout << "File could not be opened." << endl;
		return false;
	}

	// loop through the file by line
	while (!InFile.eof())
	{
		// gets the next line
		getline(InFile, Line);

		if (Line == "") //end of file
		{
			break;
		}

		// splits the line by comma and stores in a vector
		vector<string> SplitByComma = split(Line, ',');
		if (SplitByComma[0] == "F") // for comedy movies
		{
			// checks to see if the line is properly sized
			if (SplitByComma.size() != 5) {
				cout << "Invalid Movie data. Exiting.";
				continue;
			}
			// F, Stock, Director, Title, Year it released
			Comedy* CMovie = (Comedy*)MovFactory.makeMovie('F'); //NEW
			CMovie->MovieType = (const char)SplitByComma[0][0];
			CMovie->Quantity = stoi(SplitByComma[1]);
			CMovie->Director = removeSpace(SplitByComma[2]);
			CMovie->Title = removeSpace(SplitByComma[3]);
			CMovie->ReleaseYear = stoi(SplitByComma[4]);
			if (!comedyBST->Add(CMovie))
			{
				delete CMovie;
			}
		}
		else if (SplitByComma[0] == "D") // for drama movies
		{
			// checks to see if the line is properly sized
			if (SplitByComma.size() != 5) {
				cout << "Invalid Movie data. Exiting.";
				continue;
			}
			// D, Stock, Director, Title, Year it released
			Drama* Dmovie = (Drama*)MovFactory.makeMovie('D');
			Dmovie->MovieType = (const char)SplitByComma[0][0];
			Dmovie->Quantity = stoi(SplitByComma[1]);
			Dmovie->Director = removeSpace(SplitByComma[2]);
			Dmovie->Title = removeSpace(SplitByComma[3]);
			Dmovie->ReleaseYear = stoi(SplitByComma[4]);
			if (!dramaBST->Add(Dmovie))
			{
				delete Dmovie;
			}
		}
		else if (SplitByComma[0] == "C") // for classic movies
		{
			// checks to see if the line is properly sized
			if (SplitByComma.size() != 5) {
				cout << "Invalid Movie data. Exiting.";
				continue;
			}
			// C, Stock, Director, Title, Major actor Release date
			// splits the last part of the line by space to differ between
			// the actor and the release date
			vector<string> SplitBySpace = split(SplitByComma[4], ' ');

			// checks to see if the line is properly sized
			if (SplitBySpace.size() != 5) {
				cout << "Invalid Movie data. Exiting.";
				continue;
			}

			// C, Stock, Director, Title, Major actor Release date
			Classic* Cmovie = (Classic*)MovFactory.makeMovie('C');
			Cmovie->MovieType = (const char)SplitByComma[0][0];
			Cmovie->Quantity = stoi(SplitByComma[1]);
			Cmovie->Director = removeSpace(SplitByComma[2]);
			Cmovie->Title = removeSpace(SplitByComma[3]);
			Cmovie->ActorFirstName = removeSpace(SplitBySpace[1]);
			Cmovie->ActorLastName = removeSpace(SplitBySpace[2]);
			Cmovie->ReleaseMonth = stoi(SplitBySpace[3]); //broke here?
			Cmovie->ReleaseYear = stoi(SplitBySpace[4]);
			if (!classicBST->Add(Cmovie))
			{
				delete Cmovie;
			}
		}
		else
		{
			cout << "Bad movie Genre: " << SplitByComma[0] << endl;
		}
	}
	// closes the file
	InFile.close();
	return true;
}

// reading in customers
bool StoreDriver::readCustomers(string File)
{
	ifstream InFile;
	string Line;

	// read in the file
	InFile.open(File);
	while (!InFile.eof())
	{
		// gets the next line
		getline(InFile, Line);

		if (Line == "") //end of file
		{
			break;
		}

		// splits the line by comma and stores in a vector
		vector<string> SplitBySpace = split(Line, ' ');

		// checks to see if the line is properly sized
		if (SplitBySpace.size() != 3) {
			cout << "Invalid customer data. Exiting.";
			continue;
		}

		Customer* NewCustomer = new Customer();
		NewCustomer->CustomerId = stoi(SplitBySpace[0]);
		NewCustomer->FirstName = removeSpace(SplitBySpace[1]);
		NewCustomer->LastName = removeSpace(SplitBySpace[2]);

		// adds the customer to the hashmap
		if (Customers->add(NewCustomer))
		{
		}else
		{
			delete NewCustomer;
		}
	}

	InFile.close();
	return true;
}

// returns a movie based on it's comparative types
Movie* StoreDriver::getMovie(char MediaType, char MovieType, string DirAct,
	string Title, int ReleaseYear)
{
	/* cout << "Finding movie ..." << "Title:" << Title << " DirAct:"
					<< DirAct << " MovieType:" << MovieType << " ReleaseYear:"
					<< ReleaseYear << endl;
					*/

	// checks the media type
	if (MediaType == 'D')
	{
		// checks the genre
		if (MovieType == 'F')
		{
			Comedy* pointer = nullptr;
			auto* CMovie = new Comedy();
			CMovie->Title = Title;
			CMovie->ReleaseYear = ReleaseYear;

			// retrieve returns a pointer to the movie object
			if (comedyBST->Retrieve(CMovie, pointer))
			{
				delete CMovie;
				//cout << "Returning after Retrieve " << pointer << endl;
				return pointer; //null if nothing
			}
			delete CMovie;
		}
		if (MovieType == 'D')
		{
			Drama* pointer = nullptr;
			auto* DMovie = new Drama();
			DMovie->Director = DirAct; //organized by director and title
			DMovie->Title = Title;
			if (dramaBST->Retrieve(DMovie, pointer))
			{
				delete DMovie; //delete the temp
				return pointer; //null if nothing
			}
			delete DMovie;
		}
		if (MovieType == 'C')
		{
			Classic* pointer = nullptr;
			auto* CMovie = new Classic();
			vector<string> SplitBySpace = split(DirAct, ' ');
			//organized by month,release year 122019
			CMovie->ReleaseMonth = ReleaseYear / 10000;
			CMovie->ReleaseYear = ReleaseYear - (CMovie->ReleaseMonth * 10000);
			CMovie->ActorFirstName = SplitBySpace[0];
			CMovie->ActorLastName = SplitBySpace[1];
			if (classicBST->Retrieve(CMovie, pointer))
			{
				delete CMovie; //delete the temp
				return pointer; //null if nothing
			}
			delete CMovie;
		}
	}
	return nullptr;
}

// reading in the Movies
bool StoreDriver::readTransactions(string File)
{
	ifstream InFile;
	string Line;

	// opens the file
	InFile.open(File);

	if (!InFile) {
		cout << "File could not be opened." << endl;
		return false;
	}

	// loop through the file
	while (!InFile.eof())
	{
		// gets the next line
		getline(InFile, Line);

		if (Line == "") //end of file
		{
			break;
		}

		// inventory
		// I
		//cout << Line << endl;
		if ((const char)Line[0] == 'I')
			//if (Line.rfind("I", 0) == 0)
		{
			auto NewTrans = new Transaction('I');
			Transactions->addTransaction(NewTrans); // adds a inventory command

		// history
		// H 1000
		} else if ((const char)Line[0] == 'H')
			//else if (Line.rfind("H", 0) == 0)
		{
			vector<string> SplitBySpace = split(Line, ' ');

			// checks to see if the line is properly sized
			if (SplitBySpace.size() != 2)
			{
				cout << "Invalid customer data. Exiting.";
				continue;
			}

			auto NewTrans = new Transaction('H');
			NewTrans->setTargetCustomer(Customers->getCustomer(
				stoi(SplitBySpace[1])));
			Transactions->addTransaction(NewTrans); // adds a history command

			// B 1000 D D Barry Levinson, Good Morning Vietnam,
		} else if ((const char)Line[0] == 'B')
		{
			string Title = "";
			int ReleaseYear = 0;
			string DirActor = "";

			// read common data
			vector<string> SplitBySpace = split(Line, ' ');
			int CustomerId = stoi(SplitBySpace[1]);
			char MediaType = (const char)SplitBySpace[2][0];
			char MovieType = (const char)SplitBySpace[3][0];

			// read specific movie data
			if (MovieType == 'F') {
				string Temp = Line.substr(Line.find(" F ") + 3);
				vector<string> SplitByComma = split(Temp, ',');
				Title = removeSpace(SplitByComma[0]);
				ReleaseYear = stoi(SplitByComma[1]);

			}
			else if (MovieType == 'D') {
				string Temp = Line.substr(Line.find(" D ") + 5);
				vector<string> SplitByComma = split(Temp, ',');
				DirActor = removeSpace(SplitByComma[0]);
				Title = removeSpace(SplitByComma[1]);

			}
			else if (MovieType == 'C') {
				ReleaseYear = stoi(SplitBySpace[4] + SplitBySpace[5]);
				DirActor = removeSpace(SplitBySpace[6]) + " " +
					removeSpace(SplitBySpace[7]);

			}
			else {
				cout << "INVALID MOVIE TYPE.. IGNORING... " << Line << endl;
				continue;
			}

			// StoreDriver::getMovie(char MediaType, char MovieType, string Director,
			// string Title, int ReleaseYear) {}
			Customer* C = Customers->getCustomer(CustomerId);
			if (C == nullptr) {
				cout << "INVALID CUSTOMER TYPE.. IGNORING... " << Line << endl;
				continue;
			}
			Movie* M = getMovie(MediaType, MovieType, DirActor, Title, ReleaseYear);
			if (M == nullptr) {
				cout << "INVALID MOVIE NAME.. IGNORING... " << Line << endl;
				continue;
			}

			auto NewTrans = new Transaction('B');
			NewTrans->setTargetCustomer(C);
			NewTrans->setTargetMovie(M);
			Transactions->addTransaction(NewTrans); // adds a borrow command

		} else if ((const char)Line[0] == 'R')
		{
			string Title = "";
			int ReleaseYear = 0;
			string DirActor = "";

			// read common data
			vector<string> SplitBySpace = split(Line, ' ');
			int CustomerId = stoi(SplitBySpace[1]);
			char MediaType = (const char)SplitBySpace[2][0];
			char MovieType = (const char)SplitBySpace[3][0];

			// read specific movie data
			if (MovieType == 'F') {
				string Temp = Line.substr(Line.find(" F ") + 3);
				vector<string> SplitByComma = split(Temp, ',');
				Title = removeSpace(SplitByComma[0]);
				ReleaseYear = stoi(SplitByComma[1]);

			}
			else if (MovieType == 'D') {
				string Temp = Line.substr(Line.find(" D ") + 5);
				vector<string> SplitByComma = split(Temp, ',');
				DirActor = removeSpace(SplitByComma[0]);
				Title = removeSpace(SplitByComma[1]);

			}
			else if (MovieType == 'C') {
				ReleaseYear = stoi(SplitBySpace[4] + SplitBySpace[5]);
				DirActor = removeSpace(SplitBySpace[6]) + " " + removeSpace(
					SplitBySpace[7]);

			}
			else {
				cout << "INVALID MOVIE TYPE.. IGNORING... " << Line << endl;
				continue;
			}

			// StoreDriver::getMovie(char MediaType, char MovieType, string Director,
			// string Title, int ReleaseYear) {}
			Customer* C = Customers->getCustomer(CustomerId);
			if (C == nullptr) {
				cout << "INVALID CUSTOMER TYPE.. IGNORING... " << Line << endl;
				continue;
			}
			Movie* M = getMovie(MediaType, MovieType, DirActor, Title, ReleaseYear);
			if (M == nullptr) {
				cout << "INVALID MOVIE NAME.. IGNORING... " << Line << endl;
				continue;
			}

			auto NewTrans = new Transaction('R');
			NewTrans->setTargetCustomer(C);
			NewTrans->setTargetMovie(M);
			Transactions->addTransaction(NewTrans); // adds a remove transaction

		} else
		{
			cout << "INVALID COMMAND TYPE.. IGNORING... " << Line << endl;
		}
	}


	InFile.close();
	return true;
}

//==============================================================================
//===============================PRINT FUNCTIONS================================
//==============================================================================

// prints all movies with their print functions
void StoreDriver::printMovies()
{
	comedyBST->display(); // prints comedy
	classicBST->display(); // prints classic
	dramaBST->display(); // prints drama
}

// prints all customers
void StoreDriver::printCustomers()
{
	Customers->printAllCustomers();
}

// used for testing
//string StoreDriver::toStringTransactions()
//{
//	string Output = "";
//	queue<Transaction*> temp;
//	while (!Transactions->Transactions.empty())
//	{
//		Transaction* T = Transactions->Transactions.front();
//		string s(1, T->getCommand()); // converts char to string
//		Output = Output + "CHAR = " + s;
//		if (s == "I")
//		{
//			Output = Output + " SHOW INVENTORY";
//		}
//		else if (s == "B")
//		{
//			Output = Output + " " + T->getTargetMovie()->Title + " IS BEING BORROWED BY ";
//			Output = Output + T->getTargetCustomer()->FirstName + " " +
//				T->getTargetCustomer()->LastName;
//		}
//		else if (s == "R")
//		{
//			Output = Output + " " + T->getTargetMovie()->Title + " IS BEING RETURNED BY ";
//			Output = Output + T->getTargetCustomer()->FirstName + " " +
//				T->getTargetCustomer()->LastName;;
//		}
//		else if (s == "H")
//		{
//			Output = Output + " SHOW HISTORY";
//		}
//		else
//		{
//			break;
//		}
//		temp.push(Transactions->Transactions.front());
//		Transactions->Transactions.pop();
//		Output = Output + '\n';
//	}
//
//	// pushes values back into transaction in order
//	while (!temp.empty())
//	{
//		Transactions->Transactions.push(temp.front());
//		temp.pop();
//	}
//	return Output;
//}

// executes a transaction object
bool StoreDriver::executeTransaction(Transaction* Tran)
{
	// hanndles a invectory transaction
	if (Tran->getCommand() == 'I')
	{
		cout << endl << "INVENTORY" << endl;
		printMovies();
		return true;
		// borrow
	}

	// handles a borrow transaction
	else if (Tran->getCommand() == 'B')
	{
		//cout << "Borrow" << endl;
		Tran->getTargetMovie()->decreaseQuantity();
		Tran->getTargetCustomer()->updateHistory(Tran);
		return true;
	}

	// handles a return transaction
	else if (Tran->getCommand() == 'R')
	{
		//cout << "Return" << endl;
		Tran->getTargetMovie()->increaseQuantity();
		Tran->getTargetCustomer()->updateHistory(Tran);
		return true;

		// history
	}

	// handles a history transaction
	else if (Tran->getCommand() == 'H')
	{
		//cout << "History" << endl;
		showCustomerHistory(Tran->getTargetCustomer());
		return true;
	}
	else
	{
		return false;
	}
	return true;
}

// executes all transactions
bool StoreDriver::executeTransactions()
{
	queue<Transaction*> Temp;

	while (!Transactions->Transactions.empty())
	{
		Transaction* T = Transactions->Transactions.front();
		executeTransaction(T);
		Transactions->Transactions.pop();
		delete T;
	}
/*
	while (!Temp.empty()) {
		Transaction* T = Temp.front();
		Temp.pop();
		delete T;
	}
*/
	return true;
}

// shows all the transactions the customer has made
void StoreDriver::showCustomerHistory(Customer* Cus)
{
	for (auto X : Customers->Customers)
	{
		if (X == Cus)
		{
			Cus->showHistory(); // shows their history
		}
	}
}

//main function for input and output
int main()
{
	StoreDriver store;
	// Testing();
	if (store.readMovies("data4movies.txt"))
		cout << "Movies Read & Stored Properly" << endl << endl;
	if (store.readCustomers("data4customers.txt"))
		cout << "Customers Read & Stored Properly" << endl << endl;
	if (store.readTransactions("data4commands.txt"))
		cout << "Transactions Read & Stored Properly" << endl << endl;

	cout << "Executing Transactions" << endl;
	store.executeTransactions();
	return 0;
}
