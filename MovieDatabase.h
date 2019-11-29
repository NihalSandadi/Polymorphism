#pragma once
#include <string>
#include <vector>
#include "BST.cpp"
#include "Movie.h"
#include <ctype.h>
using namespace std;

//forward declaration
class Movie;

class MovieDatabase {
private:
	 map<char,vector<Movie*>> MoviesVector;
	 //vector<Movie*> MoviesVector;

public:
	MovieDatabase();
	~MovieDatabase();
	Movie* getMovie(string);
	bool add(Movie* movie);
	bool remove(Movie* movie);
	bool clear();
	void showInventory();
	int getHash(string);
};
