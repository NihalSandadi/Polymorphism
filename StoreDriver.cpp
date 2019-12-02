// StoreDriver.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
#include "StoreDriver.h"
StoreDriver::StoreDriver()
{
	comedyBST = new BST<Comedy*>();
	classicBST = new BST<Classic*>();
	dramaBST = new BST<Drama*>();

	Customers = new HashMapDatabase();
}

StoreDriver::~StoreDriver()
{
	delete dramaBST;
	delete comedyBST;
	delete classicBST;
	//delete Movies;
	delete Customers;
}

// code modified from https://www.fluentcpp.com
// /2017/04/21/how-to-split-a-string-in-c/
vector<string> StoreDriver::split(const string& s, char delimiter)
{
	vector<std::string> tokens;
	string token;
	istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) //using comma as our
	// delimiter
	{
		tokens.push_back(token);
	}
	return tokens;
}

// removes extra spaces at the front and back
string removeSpace(string old)
{
	int length = old.length();
	if(old[0] == *" "){ //front
		old = old.substr(1, length + 5);
	}
	if(old[length-1] == *" "){ //back
		old = old.substr(0,length-2);
	}
	return old;
}

// reading in the Movies
bool StoreDriver::readMovies(string File)
{
	MovieFactory MovFactory; //MovieFactory
	MediaFactory MediaFactory; //MediaFactory
	ifstream InFile;
	string Line;

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

		// splits the line by comma and stores in a vector
		vector<string> SplitByComma = split(Line, ',');
		if (SplitByComma[0] == "F") // for comedy movies
		{
			// F, Stock, Director, Title, Year it released
			if (SplitByComma.size() != 5) {
				cout << "Invalid customer data. Exiting."; break;
			}

			auto newMovie = (Comedy*)MovFactory.makeMovie('F');
			// F, Stock, Director, Title, Year it released
			if (comedyBST->Add(newMovie)) { //  if it can insert the movie
				newMovie->MovieType = (const char)SplitByComma[0][0];
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = removeSpace(SplitByComma[2]);
				newMovie->Title = removeSpace(SplitByComma[3]);
				newMovie->ReleaseYear = stoi(SplitByComma[4]);
				//
				unorderedComedy.push_back(newMovie);
				//
			}
			else
			{
				delete newMovie;
			}
		}
		else if (SplitByComma[0] == "D") // for drama movies
		{
			// D, Stock, Director, Title, Year it released
			if (SplitByComma.size() != 5) {
				cout << "Invalid customer data. Exiting."; break;
			}

			auto newMovie = (Drama*)MovFactory.makeMovie('D');
			// D, Stock, Director, Title, Year it released
			if (dramaBST->Add(newMovie)) { // if it can insert the movie
				newMovie->MovieType = (const char)SplitByComma[0][0];
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = removeSpace(SplitByComma[2]);
				newMovie->Title = removeSpace(SplitByComma[3]);
				newMovie->ReleaseYear = stoi(SplitByComma[4]);
				//
				unorderedDrama.push_back(newMovie);
				//
			}
			else
			{
				delete newMovie;
			}
		}
		else if (SplitByComma[0] == "C") // for classic movies
		{
			// C, Stock, Director, Title, Major actor Release date
			if (SplitByComma.size() != 5) {
				cout << "Invalid customer data. Exiting."; break;
			}

			// splits the last part of the line by space to differinciate between
			// the actor and the release date
			vector<string> SplitBySpace = split(SplitByComma[4], ' ');
			if (SplitBySpace.size() != 5) {
				cout << "Invalid customer data. Exiting."; break;
			}

			// C, Stock, Director, Title, Major actor Release date
			Classic* newMovie = (Classic*)MovFactory.makeMovie('C');
			if (classicBST->Add(newMovie))
			{
				newMovie->MovieType = (const char)SplitByComma[0][0];
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = removeSpace(SplitByComma[2]);
				newMovie->Title = removeSpace(SplitByComma[3]);
				// not working because unable to create a classic a properly
				newMovie->ActorFirstName = removeSpace(SplitBySpace[1]);
				newMovie->ActorLastName = removeSpace(SplitBySpace[2]);
				newMovie->ReleaseMonth = stoi(SplitBySpace[3]); //broke here?
				newMovie->ReleaseYear = stoi(SplitBySpace[4]);
				//
				unorderedClassic.push_back(newMovie);
				//
			}
			else
			{
				delete newMovie;
			}
		}
	}

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
		if (SplitBySpace.size() != 3) {
			cout << "Invalid customer data. Exiting."; break;
		}

		Customer* NewCustomer = new Customer();
		NewCustomer->CustomerId = stoi(SplitBySpace[0]);
		NewCustomer->FirstName = removeSpace(SplitBySpace[1]);
		NewCustomer->LastName = removeSpace(SplitBySpace[2]);

		//adds the customer to the hashmap
		if (Customers->add(NewCustomer)) {
			//Customers->getCustomer(NewCustomer->CustomerId)->showHistory();
			//for testing purposes
		}
		else
		{
			delete NewCustomer;
		}
	}

	InFile.close();
	return true;
}


Movie* StoreDriver::getMovie(char MediaType, char MovieType, string DirAct, string Title, int ReleaseYear)
{
	if (MediaType == 'D')
	{
		if (MovieType == 'F')
		{
			auto* pointer = new Comedy();
			auto* CMovie = new Comedy();
			CMovie->Title = Title;
			CMovie->ReleaseYear = ReleaseYear;
			if (comedyBST->Retrieve(CMovie, pointer))
			{
				delete CMovie;
				return pointer; //null if nothing
			}
		}
		if (MovieType == 'D')
		{
			auto* pointer = new Drama();
			auto* DMovie = new Drama();
			DMovie->Director = DirAct; //organized by director and title
			DMovie->Title = Title;
			if (dramaBST->Retrieve(DMovie, pointer))
			{
				delete DMovie; //delete the temp
				return pointer; //null if nothing
			}
		}
		if (MovieType == 'C')
		{
			auto* pointer = new Classic();
			auto* CMovie = new Classic();
			vector<string> SplitBySpace = split(DirAct, ' ');
			CMovie->ReleaseMonth = ReleaseYear % 12; //organized by month,release year 201912 (only thing is 12 is gonna be 0)
			CMovie->ReleaseYear = ReleaseYear / 100; // to get rid of the month
			CMovie->ActorFirstName = SplitBySpace[0]; //firstname
			CMovie->ActorLastName = SplitBySpace[1];//lastname
			if (classicBST->Retrieve(CMovie, pointer))
			{
				delete CMovie; //delete the temp
				return pointer; //null if nothing
			}
		}
	}
	return nullptr;
}
// reading in the Movies
bool StoreDriver::readTransactions(string File)
{
	ifstream InFile;
	string Line;

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
		if ((const char)Line[0] == 'I')
		{
			auto NewTrans = new Transaction('I');
			cout << "COMMAND INSIDE STORE " << NewTrans->getCommand() << endl;
			Transactions->addTransaction(NewTrans);

		// history
		// H 1000
		}
		else if ((const char)Line[0] == 'H')
		{
			vector<string> SplitBySpace = split(Line, ' ');

			if (SplitBySpace.size() != 2)
				cout << "Invalid customer data. Exiting."; break;

			auto NewTrans = new Transaction('H');
			NewTrans->setTargetCustomer(Customers->getCustomer( stoi(SplitBySpace[1]) ));
			Transactions->addTransaction(NewTrans);

		// B 1000 D D Barry Levinson, Good Morning Vietnam,
		}else if ((const char)Line[0] == 'B')
		{
			vector<string> SplitByComma = split(Line, ',');
			vector<string> SplitBySpace = split(SplitByComma[0], ' ');

			auto NewTrans = new Transaction('B');
			NewTrans->setTargetCustomer(Customers->getCustomer( stoi(SplitBySpace[1]) ));
			// StoreDriver::getMovie(char MediaType, char MovieType, string Director,
			// string Title, int ReleaseYear) {}
			if (SplitByComma.size() == 3)
			{
				NewTrans->setTargetMovie(getMovie(SplitBySpace[2][0],
					SplitBySpace[3][0],	SplitBySpace[4] + " " + SplitBySpace[5],
					SplitByComma[1], 0));
			}else
			{
				NewTrans->setTargetMovie(getMovie(SplitBySpace[2][0],
					SplitBySpace[3][0],	SplitBySpace[4] + " " + SplitBySpace[5],
					SplitByComma[1], stoi(SplitByComma[2]) ));
			}
			Transactions->addTransaction(NewTrans);

		// 0   1  2 3 4  5    6     7
		// R 5000 D C 3 1971 Ruth Gordon
		// 0   1  2 3  4      5   6     1
		// R 8000 D F You've Got Mail, 1998

		// StoreDriver::getMovie(char MediaType, char MovieType,
		// string Director/Actor, string Title, int ReleaseDate) {}

		}else if ((const char)Line[0] == 'R')
		{
			auto NewTrans = new Transaction('R');
			vector<string> SplitBySpace = split(Line, ' ');
			if ('C' == (const char)SplitBySpace[3][0])
			{
				NewTrans->setTargetMovie(getMovie(SplitBySpace[2][0], 'C',
					SplitBySpace[6] + " " + SplitBySpace[7], "", stoi(SplitBySpace[4]) *
					stoi(SplitBySpace[5])));

					NewTrans->setTargetCustomer(Customers->getCustomer(
						stoi(SplitBySpace[1]) ));
			}else
			{
				vector<string> SplitByComma = split(Line, ',');
				vector<string> SplitBySpace = split(Line, ' ');
				string Title = "";

				for (int X = 4; X < SplitBySpace.size(); ++X)
				{
					Title = Title + " " + SplitBySpace[X];
				}

				if (SplitByComma.size() == 2)
				{
					NewTrans->setTargetMovie(getMovie(SplitBySpace[2][0],
						SplitBySpace[3][0], " ", Title, stoi(SplitByComma[1])));
				}else
				{
					NewTrans->setTargetMovie(getMovie(SplitBySpace[2][0],
						SplitBySpace[3][0], " ", Title, 0));
				}

				NewTrans->setTargetCustomer(Customers->getCustomer(
					stoi(SplitBySpace[1]) ));
			}
			Transactions->addTransaction(NewTrans);
		}else
		{
			cout << "IMPROPER COMMAND TYPE : " << Line << endl;
		}
	}


	InFile.close();
	return true;
}

//==============================================================================
//===============================PRINT FUNCTIONS================================
//==============================================================================

void StoreDriver::printMovies()
{
	comedyBST->display();
	classicBST->display();
	dramaBST->display();
}

//void StoreDriver::printCustomers()
//{
//	Customers->printAllCustomers();
//}


string StoreDriver::toStringTransactions()
{
	string Output = "";
	queue<Transaction*> temp;
	while(!Transactions->Transactions.empty())
	{
		Transaction* T = Transactions->Transactions.front();
		string s(1, T->getCommand()); // converts char to string
		Output = Output + "CHAR = " + s;
		if (T->getCommand() == 'I')
		{
			Output = Output + " SHOW INVENTORY";
		}else if (T->getCommand() == 'B')
		{
			Output = Output + " " + T->getTargetMovie()->Title + " IS BEING BORROWED BY ";
			Output = Output + T->getTargetCustomer()->FirstName + " " +
			T->getTargetCustomer()->LastName;
		}else if (T->getCommand() == 'R')
		{
			Output = Output + " " + T->getTargetMovie()->Title + " IS BEING RETURNED BY ";
			Output = Output + T->getTargetCustomer()->FirstName + " " +
			T->getTargetCustomer()->LastName;;
		}else if (T->getCommand() == 'H')
		{
			Output = Output + " SHOW HISTORY";
		}else
		{
			return Output;
		}
		temp.push(Transactions->Transactions.front());
		Transactions->Transactions.pop();
		delete T;
	}
	return Output;
}


bool StoreDriver::executeTransaction(Transaction* Tran)
{
	if (Tran->getCommand() == 'I')
	{
		printMovies();
		// borrow
	} else if (Tran->getCommand() == 'B')
	{
		Tran->getTargetMovie()->decreaseQuantity();
		Tran->getTargetCustomer()->updateHistory(Tran);
		// return
	} else if (Tran->getCommand() == 'R')
	{
		Tran->getTargetMovie()->increaseQuantity();
		Tran->getTargetCustomer()->updateHistory(Tran);
		// history
	} else if (Tran->getCommand() == 'H')
	{
		// showCustomerHistory(Tran->TargetCustomer);
	}	else
	{
		return false;
	}

	return true;
}



bool StoreDriver::executeTransactions()
{
	while (!Transactions->Transactions.empty())
	{
		if (Transactions->Transactions.front() == nullptr) return false;
		executeTransaction(Transactions->Transactions.front());
		Transactions->Transactions.pop();
	}
	return true;
}

//shows all the transactions the customer has made
void StoreDriver::showCustomerHistory(Customer* Cus)
{
	for (auto X : Customers->Customers)
	{
		if (X == Cus)
		{
			cout << Cus->CustomerId << " " << Cus->FirstName << " " << Cus->LastName;
			cout << endl;
			Cus->showHistory();
		}
	}
}


// ===========================Testing below this Line===========================

//TESTING PURPOSES
//
//
//void testComedy()
//{
//	//(char Type, string Director, string Title, int Quantity)
//	cout << "===TESTING COMEDY INITIALIZATION===" << endl;
//	Comedy* Movie1 = new Comedy('F', "Nihal Sandadi","GodSave",10);
//	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
//	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
//
//	cout << "Print the movie" << endl;
//	cout << *Movie1 << endl;
//	cout << "===!!!WORKS!!!===" << endl;
//}

////void testDrama()
//{
//	cout << "===TESTING DRAMA INITIALIZATION===" << endl;
//	Movie* Movie1 = new Movie('D', "Nihal Sandadi","Bobs Crew", 20);
//	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
//	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
//	cout << *Movie1  << endl;
//	cout << "===!!!WORKS!!!===" << endl;
//}
//
////void testClassic()
//{
//	cout << "===TESTING CLASSIC INITIALIZATION===" << endl;
//	Movie* Movie1 = new Movie('C', "Nihal Sandadi", "Skeet skeet", 30);
//	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
//	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
//	cout << *Movie1 << endl;
//	cout << "===!!!WORKS!!!===" << endl;
//}
/*
void testMovieFactory()
{

	//created a toy database
	//MovieDatabase Movies;
	cout << "===TESTING MOVIE FACTORY===" << endl;
	MovieFactory Factory1;
	auto newMovie1 = (Comedy*)Factory1.makeMovie('F');
	//Movies.add(newMovie1);
	newMovie1->ReleaseYear = 2019;
	newMovie1->Director = "Jayden";
	newMovie1->Title = "YEET";
	newMovie1->Quantity = 0;

	cout << "newMovie1 Release Year = " << newMovie1->ReleaseYear << endl;
	cout << *newMovie1 << endl;
	cout << "===!!!WORKS!!!===" << endl;
	delete newMovie1;
	//delete Movies;
}
*/
// testing everything
void Testing()
{
	// testComedy();
	// testDrama();
	// testClassic();
	// testMovieFactory();
	cout << "===END OF TESTS===" << endl;
}

//main function for input and output
int main()
{
	StoreDriver store;
	// Testing();
	if (store.readMovies("data4movies.txt"))
		cout << "Done reading movies" << endl;
	if (store.readCustomers("data4customers.txt"))
		cout << "Customers Read & Stored Properly" << endl;
	if (store.readTransactions("data4commands.txt"))
		cout << "Transactions Read & Stored Properly" << endl;
	
	cout << "PRINTING MOVIES" << endl;
	store.printMovies();
	cout << "DONE PRINTING MOVIES" << endl;
/*
	cout << "PRINTING CUSTOMERS" << endl;
	cout << "PRINTING CUSTOMERS" << endl;
	cout << "PRINTING CUSTOMERS" << endl;
	store.printCustomers();
	cout << "DONE PRINTING CUSTOMERS" << endl;
	cout << "DONE PRINTING CUSTOMERS" << endl;
	cout << "DONE PRINTING CUSTOMERS" << endl;
*/
/*
	cout << "PRINTING TRANSACTIONS" << endl;
	cout << "PRINTING TRANSACTIONS" << endl;
	cout << "PRINTING TRANSACTIONS" << endl;
	cout << store.toStringTransactions();
	cout << "DONE PRINTING TRANSACTIONS" << endl;
	cout << "DONE PRINTING TRANSACTIONS" << endl;
	cout << "DONE PRINTING TRANSACTIONS" << endl;
*/







	return 0;
}
