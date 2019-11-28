//Movie, MovieFactory, Classic, Drama, Comedy

#pragma once 
#include "Media.h"
#include <iostream>
#include <map>
#include <string>


using namespace std;
//got rid of : class Media (Was breaking the code)

class Movie{
public:
	char MovieType;
	string Director;
	string Title;
	int Quantity;

	//virtual MediaFactory* makeMedia(ifstream&) = 0;
	Movie();
	Movie(char Type, string Director, string Title,	int Quantity);
	void increaseQuanity();
	void decreaseQuanity();
	virtual ~Movie();
	friend ostream& operator<<(ostream& Os, const Movie& M);
};

//MovieFactory creates movies and is a child of the Movie class 
class MovieFactory {
public: // should be protected/private
	map<char, Movie*> MovieTypes;
public:
	MovieFactory();
	~MovieFactory();
	Movie* makeMovie(char);
};

class Comedy: public Movie{
public:
	int ReleaseYear;
	Comedy();
	Comedy(string Director, int ReleaseYear);
	~Comedy();
  friend ostream& operator<<(ostream& Os, const Comedy& M);
};

class Drama: public Movie{
public:
	int ReleaseYear;

	Drama();
	Drama(string Director, int ReleaseYear);
	~Drama();
  friend ostream& operator<<(ostream& Os, const Drama& M);
};

class Classic : public Movie {
public:
	//variables
	int ReleaseYear, ReleaseMonth;
	string ActorFirstName, ActorLastName;

	Classic();
	Classic(string Director, int ReleaseYear, int ReleaseMonth,
		string ActorFirstName, string ActorLastName);
	~Classic();
  friend ostream& operator<<(ostream& Os, const Classic& M);
};
