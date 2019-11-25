//MovieDatabase.cpp the implementation of the .h
#include "MovieDatabase.h"

//MovieDatabase constuctor
MovieDatabase::MovieDatabase()
{
	Movies = {};
}

//Deconstructor
MovieDatabase::~MovieDatabase()
{
	for (auto X : Movies)
		delete X;
}

//Getting a movie by the string given often
Movie* MovieDatabase::getMovie(string Title)
{
	for (auto X : Movies)
	{
		if (X->Title == Title)
			return X;
	}
	return nullptr;
}

//Adding a movie to the database
bool MovieDatabase::add(Movie* Movie)
{
	Movies.push_back(Movie);
	return true;
}

//Removing a movie from the database
bool MovieDatabase::remove(Movie* Movie)
{
	vector<Movies*>::iterator It;
	It = find(Movies.begin(), Movies.end(), Movie);
	for (auto X : Movies)
	{
		if (X == Movie)
			{
				delete X;
				Movies.erase(It);
				return true;
			}
	}
	return false;
}

//clear the entire database of movies
bool MovieDatabase::clear()
{
	for (auto X : Movies)
		delete X;
	Movies.clear();
	return true;
}

//printout the entire database
void MovieDatabase::showInventory()
{
	for (auto X : Movies)
	{
		cout << X << endl;
	}
}

//not sure how to implement this or why it is needed
int MovieDatabase::getHash(string)
{
	return 0;
}
