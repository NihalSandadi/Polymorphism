// StoreDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StoreDriver.h"
StoreDriver::StoreDriver()
{
  Movies = new MovieDatabase();
  Customers = new HashMapDatabase();
}

StoreDriver::~StoreDriver()
{
  delete Movies;
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
	return false;
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
  while(!InFile.eof())
  {
    // gets the next line
    getline(InFile, Line);

    // splits the line by comma and stores in a vector
    vector<string> SplitByComma = split(Line, ',');
    if (SplitByComma[0] == "F") // for comedy movies
    {
		auto newMovie1 = (Comedy*)MovFactory.makeMovie('F');
		// F, Stock, Director, Title, Year it released
		if (Movies->add(newMovie1)) { //if it can insert the movie
			newMovie1->MovieType = (const char)SplitByComma[0][0]; // (not exactly sure if/how) this works lol
			newMovie1->Quantity = stoi(SplitByComma[1]);
			newMovie1->Director = SplitByComma[2];
			newMovie1->Title = SplitByComma[3];
			newMovie1->ReleaseYear = stoi(SplitByComma[4]);
		}
		else
		{
			delete newMovie1;
		}

    }else if (SplitByComma[0] == "D") // for drama movies
    {
      // D, Stock, Director, Title, Year it released

		auto newMovie1 = (Drama*)MovFactory.makeMovie('D');
		// F, Stock, Director, Title, Year it released
		if (Movies->add(newMovie1)) { //if it can insert the movie
			newMovie1->MovieType = (const char)SplitByComma[0][0]; // (not exactly sure if/how) this works lol
			newMovie1->Quantity = stoi(SplitByComma[1]);
			newMovie1->Director = SplitByComma[2];
			newMovie1->Title = SplitByComma[3];
			newMovie1->ReleaseYear = stoi(SplitByComma[4]);
		}
		else
		{
			delete newMovie1;
		}
    }
else if (SplitByComma[0] == "C") // for classic movies
	{
	// splits the last part of the line by space to differinciate between
	// the actor and the release date
	vector<string> SplitBySpace = split(SplitByComma[4], ' ');

	// C, Stock, Director, Title, Major actor Release date
	Classic* newMovie = (Classic*)MovFactory.makeMovie('C');
	if (Movies->add(newMovie))
	{
		//newMovie->MovieType = (const char)SplitByComma[0][0]; // possible error, string to char
		newMovie->Quantity = stoi(SplitByComma[1]);
		newMovie->Director = SplitByComma[2];
		newMovie->Title = SplitByComma[3];
		//not working because unable to create a classic a properly
		newMovie->ActorFirstName = SplitBySpace[0];
		newMovie->ActorLastName = SplitBySpace[1];
		newMovie->ReleaseMonth = stoi(SplitBySpace[2]);
		newMovie->ReleaseYear = stoi(SplitBySpace[3]);
	}
    }else // bad case (incorrect movie type)
    {
      return false;
    }
  }
  InFile.close();
  return true;
}

bool readCustomers(string File)
{
  ifstream InFile;
  InFile.open(File);
  string Line;

  // while not end of file
  //while(!InFile.eof())
  //{
  //  // gets the next line
  //  getline(InFile, Line);

  //  // splits the line by comma and stores in a vector
  //  vector<string> SplitByComma = split(Line, ',');
  //  // 3333 Witch Wicked
  //  Customers* NewCustomer = makeCustomer(stoi(SplitByComma[0]));
  //  NewCustomer->FirstName = SplitByComma[1];
  //  NewCustomer->LastName = SplitByComma[2];
  //}
  return true;
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
	auto* store = new StoreDriver();
	//bool check = readMovies(data4movies);
	//cout << check << endl;
	Testing();
	store->readMovies("data4movies");
	cout << endl << "Finished Tests" << endl;
	return 1;
}
