// ------------------------------------------------ Movie.h --------------------------------------------------------
// Jayden Stipek Nihal Sandadi CSS 343 B
// Creation: 10/25/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Enscapsulates Genres as a Movie type ('D','C','F')
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Able to have 3 different genres atm and able to add more
//		Genres include (Drama(D), Comedy(F), and Classic(C))
//		Using a Factory of the creation of Movie genres (MovieFactory)
//		Purpose of this is for abstraction and expandability
//		Now able to have different types of Media such as DVD'S,CD'S , etc
//		Able to have Quantity outside the movie itself in order for higher Inheritance/Abstraction
// -----------------------------------------------------------------------------------------------------------------

#pragma once
#include "Media.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Parent class for all movie types
class Movie {
	friend ostream& operator<<(ostream& Os, const Movie*& M);
public:
	char MovieType; // can be Classic, Comedy, and Drama so far
	string Director;
	string Title;
	int Quantity; // number of instances of a movie in the library
	virtual void display() const;
	Movie();
	void increaseQuantity(); // +1
	void decreaseQuantity(); // -1
	virtual ~Movie() {};
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
	virtual void display() const;
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
	virtual void display() const;
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
	virtual void display() const;
	Classic(string Director, int ReleaseYear, int ReleaseMonth,
		string ActorFirstName, string ActorLastName);
	~Classic() {};
};
