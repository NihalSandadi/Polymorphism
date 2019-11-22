//Movie implementation
#include "Movie.h"

using namespace std;

//Movie Constructor
Movie::Movie()
{
	MovieType = '\0';
	Director = "";
}

//Deconstructor
virtual Movie::~Movie()
{
	MovieType = '\0';
	Director = "";
}

//Printing out the movie 
virtual ostream& Movie::operator<<(ostream &Os,const Media& M)
{
	Os << M;
}

//Beginning of Movie Factory 
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

Comedy::~Comedy() {};

ostream& Comedy::operator<<(ostream& Os, const Comedy& M) override
{

}

//Beginning Of Drama Class
Drama::Drama()
{
	int ReleaseYear;
}

Drama::~Drama() {};

ostream& Drama::operator<<(ostream& Os, const Comedy& M) override
{

}

//Beginning Of Classic Class
Classic::Classic()
{
	int ReleaseYear, ReleaseMonth;
	string ActorFirstName, ActorLastName;

}

Classic::~Classic() {};

ostream& Classic::operator<<(ostream& Os, const Movie& M) override
{

}
