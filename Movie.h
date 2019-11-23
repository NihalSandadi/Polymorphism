//Movie, MovieFactory, Classic, Drama, Comedy
#include <iostream>
#include <map>
#include <string>
#include "Media.h"

using namespace std;

class Movie: public Media {
public:
	char MovieType;
	string Director;
	Movie();
	Movie(char Type, string Director);
	virtual ~Movie();
	friend ostream& operator<<(ostream& Os, const Media& M);
};

class MovieFactory {
private:
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
	int ReleaseYear, ReleaseMonth;
  string ActorFirstName, ActorLastName;
  Classic();
	Classic(string Director, int ReleaseYear, int ReleaseMonth,
		string ActorFirstName, string ActorLastName);
	~Classic();
  friend ostream& operator<<(ostream& Os, const Classic& M);
};
