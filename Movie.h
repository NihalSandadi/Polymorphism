//Movie, MovieFactory, Classic, Drama, Comedy

#pragma once
#include "Media.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Parent class for all movie types
class Movie {
	friend ostream& operator<<(ostream& Os, const Movie& M);
public:
	char MovieType; // can be Classic, Comedy, and Drama for now
	string Director;
	string Title;
	int Quantity; // number of instances of a movie in the library

	Movie();
	void increaseQuantity(); // +1
	void decreaseQuantity(); // -1
	virtual ~Movie();
};

// MovieFactory creates movies
class MovieFactory {
public:
	MovieFactory() {};
	~MovieFactory() {};
	Movie* makeMovie(char);
};

// Comedy movie
class Comedy : public Movie {
	friend ostream& operator<<(ostream& Os, const Comedy& M);
	friend bool operator<(const Comedy& lhs, const Comedy& rhs);
	friend bool operator==(const Comedy& lhs, const Comedy& rhs);
public:
	int ReleaseYear;

	Comedy();
	Comedy(string Director, int ReleaseYear);
	~Comedy() {};
};

// Drama movie
class Drama : public Movie {
	friend ostream& operator<<(ostream& Os, const Drama& M);
	friend bool operator<(const Drama& lhs, const Drama& rhs);
	friend bool operator==(const Drama& lhs, const Drama& rhs);
public:
	int ReleaseYear;

	Drama();
	Drama(string Director, int ReleaseYear);
	~Drama() {};
};

// Classic movie
class Classic : public Movie {
	friend ostream& operator<<(ostream& Os, const Classic& M);
	friend bool operator<(const Classic& lhs, const Classic& rhs);
	friend bool operator==(const Classic& lhs, const Classic& rhs);
public:
	//variables
	int ReleaseYear, ReleaseMonth;
	string ActorFirstName, ActorLastName;

	Classic();
	Classic(string Director, int ReleaseYear, int ReleaseMonth,
		string ActorFirstName, string ActorLastName);
	~Classic() {};
};
