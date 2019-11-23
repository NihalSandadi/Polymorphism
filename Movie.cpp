//Movie implementation
#include "Movie.h"

using namespace std;

//Movie Constructor
Movie::Movie()
{
	MovieType = '\0';
	Director = "";
}

Movie::Movie(char Type, string Director)
{
	this->MovieType = Type;
	this->Director = Director;
}

//Deconstructor
Movie::~Movie() {}

//Printing out the movie
ostream& Movie::operator<<(ostream &Os,const Media& M) {}

//Beginning of Movie Factory
MovieFactory::MovieFactory()
{
	MovieTypes;
}
//clears the entire map of movies deconstuctor
MovieFactory::~MovieFactory()
{
	MovieTypes.clear();
}

//creates a movie of a certain type and returns a movie pointer of that type
Movie* MovieFactory::makeMovie(char type)
{
	if (MovieTypes.count(type) > 0)
		throw "BAD MOVIE TYPE";
	return new MovieTypes[type];
}
//Beginning Of Comedy Class
Comedy::Comedy() : Movie()
{
	int ReleaseYear;
}

Comedy::Comedy(string Director, int ReleaseYear) : Movie('F', Director)
{
	this->ReleaseYear = ReleaseYear;
}

Comedy::~Comedy() {}

//printing out the comedy movie
ostream& Comedy::operator<<(ostream& Os, const Comedy& M) override
{
	Os << M->MovieType << " F " << M->title << ", " << M->ReleaseYear;
	return Os;
}

//Beginning Of Drama Class
Drama::Drama() : Movie()
{
	ReleaseYear;
}

Drama::Drama(string Director, int ReleaseYear) : Movie('D', Director)
{
	this->ReleaseYear = ReleaseYear;
}

//Drama deconstructor
Drama::~Drama() {}

//Printing the Drama movie out
ostream& Drama::operator<<(ostream& Os, const Drama& M) override
{
	Os << M->MovieType << " F " << M->title << ", " << M->ReleaseYear;
	return Os;
}

//Beginning Of Classic Class
Classic::Classic() : Movie()
{
	ReleaseYear = 0;
	ReleaseMonth = 0;
	ActorFirstName = "";
	ActorLastName = "";

}

Classic::Classic(string Director, int ReleaseYear, int ReleaseMonth,
	string ActorFirstName, string ActorLastName) : Movie('C', Director)
{
	this->ReleaseYear = ReleaseYear;
	this->ReleaseMonth = ReleaseMonth;
	this->ActorFirstName = ActorFirstName;
	this->ActorLastName = ActorLastName
}

//classic deconstructor
Classic::~Classic() {}

//printing the classic Movie
ostream& Classic::operator<<(ostream& Os, const Movie& M) override
{
	Os << (media type) << " C " << (movie name) << " " <<
	 ActorFirstName << " " << ActorFirstName << " " << ReleaseMonth
	 << " " << ReleaseYear;
}
