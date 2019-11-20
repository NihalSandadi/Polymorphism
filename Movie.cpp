#include "Movie.h"

using namespace std;

Movie::Movie()
{
	
}

virtual Movie::~Movie()

{
	
}

virtual ostream& Movie::operator<<(ostream& Os, const Media& M)
{
	
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

Comedy::Comedy()
{
	
}

Comedy::~Comedy()
{
	
}

ostream& Comedy::operator<<(ostream& Os, const Comedy& M) override
{
	
}

Drama::Drama()
{
	
}

Drama::~Drama()
{
	
}

ostream& Drama::operator<<(ostream& Os, const Comedy& M) override
{
	
}


Classic::Classic()
{

}

Classic::~Classic()
{
	
}

Classic::operator<<(ostream& Os, const Movie& M) override
{
	
}