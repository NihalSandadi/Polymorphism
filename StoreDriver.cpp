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

bool StoreDriver::readMovies(string File)
{
	return false;
	MovieFactory MovFactory; //MovieFactory 
	MediaFactory MediaFactory; //MediaFactory
	ifstream InFile;
	InFile.open(File);
	string Line;

  // while not end of file
  while(!InFile.eof())
  {
    // gets the next line
    getline(InFile, Line);

    // splits the line by comma and stores in a vector
    vector<string> SplitByComma = split(Line, ',');
	stringstream Variable(Line); // to convert to ints
	string garbage;

	//THIS IS ALL BROKEN
    if (SplitByComma[0] == "F") // for comedy movies
    {
      // F, Stock, Director, Title, Year it released
		//Movie* newMovie = MovFactory.makeMovie('F');
		//if (Movies.add(newMovie)) { //if it can instert the movie
		//	Media* newMedia = MediaFactory.makeMedia('d');
		//	newMovie->MovieType = (const char)SplitByComma[0].c_str(); // (not exactly sure if/how) this works lol
		//	newMedia->Quantity = SplitByComma[1]; //erro
		//	int i >> Variable(SplitByComma[1]);
		//	newMovie->Director = SplitByComma[2];
		//	newMovie->Title = SplitByComma[3];
		//	newMovie->ReleaseYear = stoi(SplitByComma[4]);
		//}
		//else
		//{
		//	delete  newMovie;
		//}

  //  }else if (SplitByComma[0] == "D") // for drama movies
  //  {
  //    // D, Stock, Director, Title, Year it released
  //    Movie* newMovie = MovFactory.makeMovie('D');
  //    MovieDatabase.add(newMovie);
  //    newMovie->MovieType = SplitByComma[0]; // possible error, string to char
  //    newMovie->Quantity = SplitByComma[1];
  //    newMovie->Director = SplitByComma[2];
  //    newMovie->Title = SplitByComma[3];
  //    newMovie->ReleaseYear = stoi(SplitByComma[4]);

  //  }else if (SplitByComma[0] == "C") // for classic movies
  //  {
  //    // splits the last part of the line by space to differinciate between
  //    // the actor and the release date
  //    vector<string> SplitBySpace = split(SplitByComma[4], ' ');

  //    // C, Stock, Director, Title, Major actor Release date
  //    Movie* newMovie = MovFactory.makeMovie('F');
  //    MovieDatabase.add(newMovie);
  //    char CharArray[1];
  //    strcpy(CharArray, SplitByComma[0].c_str())
  //    Temp->MovieType = CharArray[0]; // possible error, string to char
  //    MovFactory->Quantity = SplitByComma[1];
  //    newMovie->Director = SplitByComma[2];
  //    newMovie->Title = SplitByComma[3];
  //    newMovie->ActorFirstName = SplitBySpace[0];
  //    newMovie->ActorLastName = SplitBySpace[1];
  //    newMovie->ReleaseMonth = stoi(SplitBySpace[2]);
  //    newMovie->ReleaseYear = stoi(SplitBySpace[3]);

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


void testComedy()
{
	//(char Type, string Director, string Title, int Quantity)
	cout << "===TESTING COMEDY INITIALIZATION===" << endl;
	Movie* Movie1 = new Movie('F', "Nihal Sandadi","GodSave",10);
	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;

	cout << "Print the movie" << endl;
	cout << *Movie1 << endl;
	cout << "===!!!WORKS!!!===" << endl;
}

void testDrama()
{
	cout << "===TESTING DRAMA INITIALIZATION===" << endl;
	Movie* Movie1 = new Movie('D', "Nihal Sandadi","Bobs Crew", 20);
	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
	cout << "===!!!WORKS!!!===" << endl;
}

void testClassic()
{
	cout << "===TESTING CLASSIC INITIALIZATION===" << endl;
	Movie* Movie1 = new Movie('C', "Nihal Sandadi", "Skeet skeet", 30);
	cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
	cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
	cout << "===!!!WORKS!!!===" << endl;
}

void testMovieFactory()
{
	cout << "===TESTING MOVIE FACTORY===" << endl;
	MovieFactory* Factory1 = new MovieFactory();
	Factory1->MovieTypes['F'] = new Movie('F', "Nihal", "Skeet skeet", 1);
	Factory1->MovieTypes['D'] = new Movie('D', "Jayden", "BBBBB", 2);
	Factory1->MovieTypes['C'] = new Movie('C', "Pisan", "CCCCC", 3);

	cout << "Printing Director for movie F : " <<
		Factory1->MovieTypes['F']->Director << endl;
	cout << "Printing Director for movie D : " <<
		Factory1->MovieTypes['D']->Director << endl;
	cout << "Printing Director for movie C : " <<
		Factory1->MovieTypes['C']->Director << endl;

	cout << "Print the Movie's stuff" << endl;
	cout << *Factory1->MovieTypes['F'] << endl;
	
	cout << "===!!!WORKS!!!===" << endl;
}
// testing everything
void Testing()
{
	testComedy();
	testDrama();
	testClassic();
	testMovieFactory();
	cout << "===END OF TESTS===" << endl;
}
//main function for input and output
int main()
{
	//bool check = readMovies(data4movies);
	//cout << check << endl;
	Testing();
	cout << endl << "Finished Tests" << endl;
	return 1;
}