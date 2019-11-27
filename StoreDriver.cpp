// StoreDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StoreDriver.h"
#include "MovieDatabase.cpp"
#include "Movie.h"
#include "Customers.h"
#include "Transactions.h"
#include <cstring>

StoreDriver::StoreDriver()
{
  MoviesDatabase = new MovieDatabase();
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
	MovieFactory MFactory;
	MediaFactory MediaFactory;
	ifstream InFile;
	InFile.open(File);
	string Line;

  // while not end of file
  while(!InFile.eof())
  {
    // gets the next line
    getline(InFile, Line);

    // splits the line by comma and stores in a vector
 //   vector<string> SplitByComma = split(Line, ',');
	//stringstream Variable(Line); // to convert to ints
	//string garbage;


 //   if (SplitByComma[0] == "F") // for comedy movies
 //   {
 //     // F, Stock, Director, Title, Year it released
	//	Movie* newMovie = MFactory.makeMovie('F');
	//	if (Movies.add(newMovie)) { //if it can instert the movie
	//		Media* newMedia = MediaFactory.makeMedia('d');
	//		newMovie->MovieType = (const char)SplitByComma[0].c_str(); // (not exactly sure if/how) this works lol
	//		newMedia->Quantity >> SplitByComma[1]; //erro
	//		newMovie->Director = SplitByComma[2];
	//		newMovie->Title = SplitByComma[3];
	//		newMovie->ReleaseYear = stoi(SplitByComma[4]);
	//	}
	//	else
	//	{
	//		delete  newMovie;
	//	}

 //   }else if (SplitByComma[0] == "D") // for drama movies
 //   {
 //     // D, Stock, Director, Title, Year it released
 //     Movie* newMovie = MFactory.makeMovie('D');
 //     MovieDatabase.add(newMovie);
 //     newMovie->MovieType = SplitByComma[0]; // possible error, string to char
 //     newMovie->Quantity = SplitByComma[1];
 //     newMovie->Director = SplitByComma[2];
 //     newMovie->Title = SplitByComma[3];
 //     newMovie->ReleaseYear = stoi(SplitByComma[4]);

 //   }else if (SplitByComma[0] == "C") // for classic movies
 //   {
 //     // splits the last part of the line by space to differinciate between
 //     // the actor and the release date
 //     vector<string> SplitBySpace = split(SplitByComma[4], ' ');

 //     // C, Stock, Director, Title, Major actor Release date
 //     Movie* newMovie = MFactory.makeMovie('F');
 //     MovieDatabase.add(newMovie);
 //     char CharArray[1];
 //     strcpy(CharArray, SplitByComma[0].c_str())
 //     Temp->MovieType = CharArray[0]; // possible error, string to char
 //     MFactory->Quantity = SplitByComma[1];
 //     newMovie->Director = SplitByComma[2];
 //     newMovie->Title = SplitByComma[3];
 //     newMovie->ActorFirstName = SplitBySpace[0];
 //     newMovie->ActorLastName = SplitBySpace[1];
 //     newMovie->ReleaseMonth = stoi(SplitBySpace[2]);
 //     newMovie->ReleaseYear = stoi(SplitBySpace[3]);

 //   }else // bad case (incorrect movie type)
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
  while(!InFile.eof())
  {
    // gets the next line
    getline(InFile, Line);

    // splits the line by comma and stores in a vector
    vector<string> SplitByComma = split(Line, ',');
    // 3333 Witch Wicked
    Customers* NewCustomer = makeCustomer(stoi(SplitByComma[0]));
    NewCustomer->FirstName = SplitByComma[1];
    NewCustomer->LastName = SplitByComma[2];
  }
  return true;
}

int main()
{
  bool check = readMovies(data4movies);
  cout << check << endl;
  std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
