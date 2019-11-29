//Movie, MovieFactory, Classic, Drama, Comedy

#pragma once
#include "Media.h"
#include <iostream>
#include <map>
#include <string>


using namespace std;
//got rid of : class Media (Was breaking the code)

class Movie {
	friend ostream& operator<<(ostream& Os, const Movie& M);
public:
	char MovieType;
	string Director;
	string Title;
	int Quantity;

	//virtual MediaFactory* makeMedia(ifstream&) = 0;
	Movie();
	void increaseQuanity();
	void decreaseQuanity();
	virtual ~Movie();
};

//MovieFactory creates movies and is a child of the Movie class
class MovieFactory {
public: // should be protected/private
public:
	MovieFactory();
	~MovieFactory();
	Movie* makeMovie(char);
};

class Comedy : public Movie {
	friend ostream& operator<<(ostream& Os, const Comedy& M);
	friend bool operator<(const Comedy& lhs, const Comedy& rhs);
	friend bool operator==(const Comedy& lhs, const Comedy& rhs);
public:
	int ReleaseYear;

	Comedy();
	Comedy(string Director, int ReleaseYear);
	~Comedy();
};

class Drama : public Movie {
	friend ostream& operator<<(ostream& Os, const Drama& M);
	friend bool operator<(const Drama& lhs, const Drama& rhs);
	friend bool operator==(const Drama& lhs, const Drama& rhs);
public:
	int ReleaseYear;

	Drama();
	Drama(string Director, int ReleaseYear);
	~Drama();
};

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
	~Classic();
};
