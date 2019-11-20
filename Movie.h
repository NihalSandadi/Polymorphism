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
	virtual ~Movie();
	virtual ostream& operator<<(ostream& Os, const Media& M);
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
	~Comedy();
    ostream& operator<<(ostream& Os, const Comedy& M) override;
};

class Drama: public Movie{
public:
	int ReleaseYear;

	Drama();
	~Drama();
    ostream& operator<<(ostream& Os, const Comedy& M) override;
};

class Classic : public Movie {
public:
	int ReleaseYear, ReleaseMonth;
    string ActorFirstName, ActorLastName;

    Classic();
	~Classic();
    ostream& operator<<(ostream& Os, const Movie& M) override;
};

/*
class Movie
{
private:
	string Director;
	int ReleaseMonth;
	int ReleaseYear;
	char MovieType;
	string ActorFirstName;
	string ActorLastName;
public:

	Movie(string Director, int ReleaseYear, char MovieType)
	{
		this->Director = Director;
		this->ReleaseYear = ReleaseYear;
		this->MovieType = MovieType;
	}

	Movie(string Director, int ReleaseMonth, int ReleaseYear, char MovieType, string ActorFirstName, string ActorLastName)
	{
		this->Director = Director;
		this->ReleaseMonth = ReleaseMonth;
		this->ReleaseYear = ReleaseYear;
		this->MovieType = MovieType;
		this->ActorFirstName = ActorFirstName;
		this->ActorLastName = ActorLastName;
	}
		
}
*/