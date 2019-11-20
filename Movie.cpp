#include "Movie.h"

using namespace std;

Movie::Movie()
{
	MovieType = '';
	Director =  "";
}

virtual Movie::~Movie()
{
	MovieType = '';
	Director =  "";
}

virtual ostream& Movie::operator<<(ostream& Os, const Media& M)
{
	Os << M;
}

MovieFactory::MovieFactory()
{
	map<char, Movie*> MovieTypes;
}

MovieFactory::~MovieFactory()
{
	MovieTypes.clear();
}

Movie* MovieFactory::makeMovie(char)
{
	return new MovieTypes[MovieType];
}

//Beginning Of Comedy Class
Comedy::Comedy()
{
	int ReleaseYear;
}

Comedy::~Comedy()
{
	
}

ostream& Comedy::operator<<(ostream& Os, const Comedy& M) override
{
	
}

//Beginning Of Drama Class
Drama::Drama()
{
	int ReleaseYear;
}

Drama::~Drama()
{
	
}

ostream& Drama::operator<<(ostream& Os, const Comedy& M) override
{
	
}


Classic::Classic()
{
	int ReleaseYear, ReleaseMonth;
	string ActorFirstName, ActorLastName;

}

Classic::~Classic()
{
	
}

Classic::operator<<(ostream& Os, const Movie& M) override
{
	
}