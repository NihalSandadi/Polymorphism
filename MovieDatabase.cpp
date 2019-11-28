//MovieDatabase.cpp the implementation of the .h
#include "MovieDatabase.h"

//MovieDatabase constuctor
MovieDatabase::MovieDatabase()
{
	MoviesVector['C'];
	MoviesVector['D'];
	MoviesVector['F']; 
}

//Deconstructor
MovieDatabase::~MovieDatabase()
{
	for (auto X : MoviesVector)// needs to traverse the BST
	{
		X.clear(); //delete all pointers inside tree
	}
	//MoviesVector = nullptr;
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

//Adding a movie to the database 
bool MovieDatabase::add(Movie* newMovie)
{
	char type = newMovie->MovieType;
	if (type == 'C') //Classic
	{
		if(!MoviesVector[type].contains(newMovie)) //if the movie is not already inside the vector
		MoviesVector[type].add(newMovie); //add it to the bst
	}
	if (type == 'D')//drama
	{
		if (!MoviesVector[type].contains(newMovie)) //if the movie is not already inside the vector
			MoviesVector[type].add(newMovie); //add it to the bs
	}
	if (type == 'F')//comedy
	{
		if (!MoviesVector[type].contains(newMovie)) //if the movie is not already inside the vector
			MoviesVector[type].add(newMovie); //add it to the bs
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
	//vector<BST<Movie*>>::iterator It; //also why do we need an iterator?
	//It = find(MoviesVector.begin(), MoviesVector.end(), tempMovie); //Iterate through the Vector (THIS THROWS ERROR)
	for (auto X : MoviesVector) //for every BST inside the vector
	{
		if (X.contains(tempMovie)) //if the tempmovie is inside 
			{
				X.remove(tempMovie);//remove it 
				//MoviesVector.erase(It); why is this needed?
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
		X.clear(); //clears entire tree (implemented inside the BST)
		//X is a BST I believe on the stack do we have to do anything else?
	}
	MoviesVector.clear(); //maybe?
	return true;
}

//printout the entire database
void MovieDatabase::showInventory()
{
	for (auto X : MoviesVector)
	{
		cout << X << endl; //The BST has a operator overload
	}
}

//hashing the nodes inside the BST or possibly hashing the bst's
int MovieDatabase::getHash(string Title)
{
	return (Title[0] - 'A') % 10; // Not sure if this is a proper hashing function
}
