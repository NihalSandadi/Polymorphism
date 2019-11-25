// MovieProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include "StoreDriver.h"

StoreDriver::StoreDriver()
{
  MoviesDatabase = new MovieDatabase();
}

StoreDriver::~StoreDriver()
{
  delete MoviesDatabase;
}

// code modified from https://www.fluentcpp.com
// /2017/04/21/how-to-split-a-string-in-c/
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

bool StoreDriver::readMovies(string File)
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

    if (SplitByComma[0] == "F") // for comedy movies
    {
      // F, Stock, Director, Title, Year it released
      Movie* Temp = makeMovie('F');
      MovieDatabase.add(Temp);
      Temp->MovieType = SplitByComma[0]; // possible error, string to char
      // temp->Stock = SplitByComma[1]; // should add a stock variable to
                                        // the movie class
      Temp->Director = SplitByComma[2];
      Temp->Title = SplitByComma[3];
      Temp->ReleaseYear = stoi(SplitByComma[4]);

    }else if (SplitByComma[0] == "D") // for drama movies
    {
      // D, Stock, Director, Title, Year it released
      Movie* Temp = makeMovie('D');
      MovieDatabase.add(Temp);
      Temp->MovieType = SplitByComma[0]; // possible error, string to char
      // temp->Stock = SplitByComma[1]; // should add a stock variable to
                                        // the movie class
      Temp->Director = SplitByComma[2];
      Temp->Title = SplitByComma[3];
      Temp->ReleaseYear = stoi(SplitByComma[4]);

    }else if (SplitByComma[0] == "C") // for classic movies
    {
      // splits the last part of the line by space to differinciate between
      // the actor and the release date
      vector<string> SplitBySpace = split(SplitByComma[4], ' ');

      // C, Stock, Director, Title, Major actor Release date
      Movie* Temp = makeMovie('F');
      MovieDatabase.add(Temp);
      char CharArray[1];
      strcpy(CharArray, SplitByComma[0].c_str())
      Temp->MovieType = CharArray[0]; // possible error, string to char
      // temp->Stock = SplitByComma[1]; // should add a stock variable to
                                        // the movie class
      Temp->Director = SplitByComma[2];
      Temp->Title = SplitByComma[3];
      Temp->ActorFirstName = SplitBySpace[0];
      Temp->ActorLastName = SplitBySpace[1];
      Temp->ReleaseMonth = stoi(SplitBySpace[2]);
      Temp->ReleaseYear = stoi(SplitBySpace[3]);

    }else // bad case (incorrect movie type)
    {
      return false;
    }
  }
  InFile.close();
  return true;
}

int main()
{
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
