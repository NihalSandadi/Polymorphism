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
//clears the entire map of movies deconstuctor
MovieFactory::~MovieFactory()
{
	MovieTypes.clear();
}

//creates a movie of a certain type and returns a movie pointer of that type
Movie* MovieFactory::makeMovie(char type)
{
	return MovieTypes[type];
}
//Beginning Of Comedy Class
Comedy::Comedy()
{
	int ReleaseYear;
}

Comedy::~Comedy() {};

//printing out the comedy movie
ostream& Comedy::operator<<(ostream& Os, const Comedy& M) override
{

}

//Beginning Of Drama Class
Drama::Drama()
{
	int ReleaseYear;
}

//Drama deconstructor
Drama::~Drama() {};

//Printing the Drama movie out
ostream& Drama::operator<<(ostream& Os, const Comedy& M) override
{

}

//Beginning Of Classic Class
Classic::Classic()
{
	int ReleaseYear, ReleaseMonth;
	string ActorFirstName, ActorLastName;

}

//classic deconstructor
Classic::~Classic() {};

//printing the classic Movie
ostream& Classic::operator<<(ostream& Os, const Movie& M) override
{

}
