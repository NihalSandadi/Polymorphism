#include "Movie.h"

using namespace std;

Movie::Movie()
{

}

virtual Movie::~Movie()
{

}

virtual ostream& Movie::operator<<(ostream &Os,const Media& M)
{
	//
	Os << M;
}

MovieFactory::MovieFactory()
{

}

MovieFactory::~MovieFactory()
{

}

Movie* MovieFactory::makeMovie(char)
{

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
