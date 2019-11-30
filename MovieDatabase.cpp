//MovieDatabase.cpp the implementation of the .h
#include "MovieDatabase.h"

//MovieDatabase constuctor
MovieDatabase::MovieDatabase()
{
	MoviesVector['C'] = {};
	MoviesVector['D'] = {};
	MoviesVector['F'] = {};
}

//Deconstructor
MovieDatabase::~MovieDatabase()
{
	for (auto X : MoviesVector)// needs to traverse the BST
	{
		for (auto Y : X.second)
		{
			delete Y;
		}
	}
	MoviesVector.clear();
}

//Getting a movie by the string given often (implement later)
Movie* MovieDatabase::getMovie(string Command)
{
	//if (MoviesVector[Command[0]] != nullptr)//check the genre exists
	//{
	//	//traverse the tree for each type properly
	//	return MoviesVector[Command[0]].contains(Command[1]); //returns null if non existant or the movie pointer
	//}
	return nullptr;
}

//Sorting is perfect 
bool sortVec(vector<Movie*>& MovieVec, Movie* NewMovie)
{
	vector<Movie*>::iterator It;
	int X = 0;
	for (It = MovieVec.begin(); It != MovieVec.end(); It++, ++X)
	{
		if (NewMovie < MovieVec[X])
		{
			MovieVec.insert(It, NewMovie);
			return true;
		}
	}
	return false;
}

//Adding a movie to the database
bool MovieDatabase::add(Movie* newMovie)
{
	char type = newMovie->MovieType;
	if (type == 'C' || type == 'D' || type == 'F')
	{
		// if the movie is not already inside the vector
		if (find(MoviesVector[type].begin(), MoviesVector[type].end(),
			newMovie) == MoviesVector[type].end())
		{
			// adds to vector in the right place
			sortVec(MoviesVector[type], newMovie);
		}
	}
	else
	{
		return false; //this is not a correct movie genre
	}
	return true;
}

//Removing a movie from the database (possibly working needs testing)
bool MovieDatabase::remove(Movie* tempMovie)
{
	vector<Movie*>::iterator It = find(MoviesVector[tempMovie->MovieType].begin(),
		MoviesVector[tempMovie->MovieType].end(), tempMovie);
	if (It == MoviesVector[tempMovie->MovieType].end())
		return false;

	for (auto X : MoviesVector[tempMovie->MovieType])
	{
		if (X == tempMovie)
		{
			delete X;
			MoviesVector[tempMovie->MovieType].erase(It);
			return true;
		}
	}

	return false;
}

//clear the entire database of movies
bool MovieDatabase::clear()
{
	for (auto X : MoviesVector) // go into each BST
	{
		for (auto Y : X.second)
		{
			delete Y;
		}
	}
	MoviesVector.clear();
	return true;
}

//printout the entire database
void MovieDatabase::showInventory()
{
	for (auto X : MoviesVector)
	{
		cout << X.first << endl; //Maps the 
		for (auto Y : X.second)
		{
			cout << *Y << ", ";
		}
		cout << endl;
	}
}
//hashing the nodes inside the BST or possibly hashing the bst's
int MovieDatabase::getHash(string Title)
{
	return (Title[0] - 'A') % 10; // Not sure if this is a proper hashing function
}
