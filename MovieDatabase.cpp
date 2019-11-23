//MovieDatabase.cpp the implementation of the .h 
#include "MovieDatabase.h"

//MovieDatabase constuctor
MovieDatabase::MovieDatabase()
{
}

//Deconstructor
MovieDatabase::~MovieDatabase()
{
}

//Getting a movie by the string given often 
Movie* MovieDatabase::getMovie(string)
{

	return nullptr;
}

//Adding a movie to the database
bool MovieDatabase::add(Movie* movie)
{
	////obtain the movie based on the type 
	//if(Movies[movie.Type] == null)
	//Movies[movie.Type];
	//else
	//	Movies
	//return false;
}

//Removing a movie from the database
bool MovieDatabase::remove(Movie*)
{
	return false;
}

//clear the entire database of movies
bool MovieDatabase::clear()
{
	return false;
}

//printout the entire database
void MovieDatabase::showInventory()
{
}

//not sure how to implement this or why it is needed
int MovieDatabase::getHash(string)
{
	return 0;
}
