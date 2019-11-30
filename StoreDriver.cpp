// StoreDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StoreDriver.h"
StoreDriver::StoreDriver()
{
	comedyBST = new BST<Comedy*>();
	classicBST = new BST<Classic*>();
	dramaBST = new BST<Drama*>();
	//Movies = new MovieDatabase();
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
	while (std::getline(tokenStream, token, delimiter)) //using comma as our delimiter
	{
		tokens.push_back(token);
	}
	return tokens;
}

//reading in the Movies
bool StoreDriver::readMovies(string File)
{
	MovieFactory MovFactory; //MovieFactory
	MediaFactory MediaFactory; //MediaFactory
	ifstream InFile;
	InFile.open(File);
	string Line;
	if (!InFile) {
		cout << "File could not be opened." << endl;
		return false;
	}

	// while not end of file
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
			auto newMovie = (Comedy*)MovFactory.makeMovie('F');
			// F, Stock, Director, Title, Year it released
			if (comedyBST->Add(newMovie)) { //if it can insert the movie
				newMovie->MovieType = (const char)SplitByComma[0][0]; // (not exactly sure if/how) this works lol
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = SplitByComma[2];
				newMovie->Title = SplitByComma[3];
				newMovie->ReleaseYear = stoi(SplitByComma[4]);

				cout << "1 if Comedy Movie ADDED?: ";
				cout << comedyBST->contains(newMovie) << endl;
				comedyBST->display();
			}
			else
			{
				delete newMovie;
			}

		}
		else if (SplitByComma[0] == "D") // for drama movies
		{
			// D, Stock, Director, Title, Year it released

			auto newMovie = (Drama*)MovFactory.makeMovie('D');
			// F, Stock, Director, Title, Year it released
			if (dramaBST->Add(newMovie)) { //if it can insert the movie
				newMovie->MovieType = (const char)SplitByComma[0][0]; // (not exactly sure if/how) this works lol
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = SplitByComma[2];
				newMovie->Title = SplitByComma[3];
				newMovie->ReleaseYear = stoi(SplitByComma[4]);
				//cout << *newMovie << endl; for testing

			}
			else
			{
				delete newMovie;
			}
		}
		else if (SplitByComma[0] == "C") // for classic movies
		{
			// splits the last part of the line by space to differinciate between
			// the actor and the release date
			vector<string> SplitBySpace = split(SplitByComma[4], ' ');

			// C, Stock, Director, Title, Major actor Release date
			Classic* newMovie = (Classic*)MovFactory.makeMovie('C');
			if (classicBST->Add(newMovie))
			{
				//newMovie->MovieType = (const char)SplitByComma[0][0]; // possible error, string to char
				newMovie->Quantity = stoi(SplitByComma[1]);
				newMovie->Director = SplitByComma[2];
				newMovie->Title = SplitByComma[3];
				//not working because unable to create a classic a properly
				newMovie->ActorFirstName = SplitBySpace[1];
				newMovie->ActorLastName = SplitBySpace[2];
				newMovie->ReleaseMonth = stoi(SplitBySpace[3]); //broke here?
				newMovie->ReleaseYear = stoi(SplitBySpace[4]);
				//cout << *newMovie << endl; for testing
			}
		}
	}
	InFile.close();
	return true;
}

bool StoreDriver::readCustomers(string File)
{
	ifstream InFile;
	InFile.open(File);
	string Line;

	//while not end of file
	while (!InFile.eof())
	{
		// gets the next line
		getline(InFile, Line);

		// splits the line by comma and stores in a vector
		vector<string> SplitBySpace = split(Line, ' ');
		if (Line != "")
		{
			Customer* NewCustomer = new Customer();
			NewCustomer->CustomerId = stoi(SplitBySpace[0]);
			NewCustomer->FirstName = SplitBySpace[1];
			NewCustomer->LastName = SplitBySpace[2];
			Customers->add(NewCustomer); //adds the customer to the hashmap
			Customers->getCustomer(NewCustomer->CustomerId)->showHistory(); //for testing purposes
		}
		else
			break; //we reached the EOF
	}
	return true;
}

void StoreDriver::printMovies()
{
	comedyBST->display();
	classicBST->display();
	dramaBST->display();
}

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

// testing everything
void Testing()
{
	//testComedy();
	//testDrama();
	//testClassic();
	testMovieFactory();
	cout << "===END OF TESTS===" << endl;
}

//main function for input and output
int main()
{
	StoreDriver store;
	Testing();
	if (store.readMovies("data4movies.txt"))
	{
		cout << "FATE OF THE UNWEARY" << endl;
	}
	/*if (store.readCustomers("data4customers.txt"))
	{
		cout << "Customers Read & Stored Properly" << endl;
		return 1;
	}*/

	cout << "Failed" << endl;
	return 0;
}
