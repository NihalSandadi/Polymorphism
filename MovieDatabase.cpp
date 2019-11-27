//MovieDatabase.cpp the implementation of the .h
#include "MovieDatabase.h"

//MovieDatabase constuctor
MovieDatabase::MovieDatabase()
{
	MoviesVector = {};
}

//Deconstructor
MovieDatabase::~MovieDatabase()
{
	for (auto X : MoviesVector)// needs to traverse the BST
		for(auto Movies : X.getRoot())
		delete Movies;
}

//Getting a movie by the string given often (implement later)
Movie* MovieDatabase::getMovie(string Title)
{
	/*for (auto X : Movies)
	{
		if (X->title == Title)
			return X;
	}
	return nullptr;*/
}

//Adding a movie to the database (not implemented)
bool MovieDatabase::add(Movie* Movie)
{
	MoviesVector.push_back(Movie);
	return true;
}

//Removing a movie from the database
bool MovieDatabase::remove(Movie* tempMovie)
{
	/*vector<BST<Movie*>>::iterator It;
	It = find(Movies.begin(), Movies.end(), tempMovie);
	for (auto X : Movies)
	{
		if (X == tempMovie)
			{
				delete X;
				Movies.erase(It);
				return true;
			}
	}
	return false;*/
}

//clear the entire database of movies
bool MovieDatabase::clear()
{
	for (auto X : MoviesVector)
		delete X;
	MoviesVector.clear();
	return true;
}

//printout the entire database
void MovieDatabase::showInventory()
{
	for (auto X : MoviesVector)
	{
		cout << X << endl;
	}
}

//not sure how to implement this or why it is needed
int MovieDatabase::getHash(string)
{
	return 0;
}
