//Movie implementation
#include "Movie.h"

using namespace std;

//Movie Default Constructor
Movie::Movie()
{
	Quantity = 0;
}

//Deconstructor (needs to be implemented)
Movie::~Movie() {}

// Printing out the movie
ostream& operator<<(ostream& Os, const Movie& M) {
	Os << " Title: " << M.Title << " Director: " << M.Director << " Quantity: " << M.Quantity;
	return Os;
}

//Beginning of Movie Factory
MovieFactory::MovieFactory() {}

//clears the entire map of movies deconstuctor
MovieFactory::~MovieFactory() {}

//creates a movie of a certain type and returns a movie pointer of that type
Movie* MovieFactory::makeMovie(char type)
{
	if (type == 'F')
	{
		return new Comedy();
	}
	if (type == 'D')
	{
		return new Drama();
	}
	if (type == 'C')
	{
		return new Classic();
	}
	else
	{
		cout << "BAD MOVIE TYPE" << endl;
		//return nullptr;
	}
	return nullptr;
}

//increase the Quanity
void Movie::increaseQuanity()
{
	++Quantity;
}

void Movie::decreaseQuanity()
{
	--Quantity;
}

//Beginning of all the Genres

//Beginning Of Comedy Class
Comedy::Comedy() : Movie()
{
	MovieType = 'F';
	Director = "";
	Title = "";
	Quantity = 0;
	ReleaseYear = 0;
}

Comedy::~Comedy() {}

//printing out the comedy movie
ostream& operator<<(ostream& Os, const Comedy& M)
{
	Os << "Type:" << M.MovieType << " Director:" << M.Director << " Title: " << M.Title << ", " << " Release Year " <<  M.ReleaseYear;
	return Os;
}

// overloading the compare operator for comedy movies
bool operator<(const Comedy& lhs, const Comedy& rhs)
{
	if (lhs.Title < rhs.Title)
	{
		return true;
	}
	else if (lhs.Title == rhs.Title)
	{
		return false;
	}
	return false;
}

// overloading equals to operator for Classic
bool operator==(const Comedy& lhs, const Comedy& rhs)
{
	if (
		lhs.MovieType == rhs.MovieType &&
		lhs.Director == rhs.Director &&
		lhs.Title == rhs.Title &&
		lhs.ReleaseYear == rhs.ReleaseYear
		)
	{
		return true;
	}
	return false;
}

//Beginning Of Drama Class
Drama::Drama() : Movie()
{
	MovieType = 'D';
	Director = "";
	Title = "";
	Quantity = 0;
	ReleaseYear = 0;
}

//Drama deconstructor
Drama::~Drama() {}

//Printing the Drama movie out
ostream& operator<<(ostream& Os, const Drama& M)
{
	Os << "Type:" << M.MovieType << " Director:" << M.Director << " Title:" << M.Title << ", " << " Release Year " << M.ReleaseYear;
	return Os;
}

// overloading the compare operator for drama movies
bool operator<(const Drama& lhs, const Drama& rhs)
{
	if (lhs.Director < rhs.Director)
	{
		return true;
	}
	else if (lhs.Director == rhs.Director)
	{
		return false;
		//return (this->Title < rhs.Title);
	}
	return false;
}

// overloading equals to operator for Drama
bool operator==(const Drama& lhs, const Drama& rhs)
{
	if (
		lhs.MovieType == rhs.MovieType &&
		lhs.Director == rhs.Director &&
		lhs.Title == rhs.Title &&
		lhs.ReleaseYear == rhs.ReleaseYear
		)
	{
		return true;
	}
	return false;
}

//Beginning Of Classic Class
Classic::Classic()
{
	MovieType = 'C';
	Director = "";
	Title = "";
	Quantity = 0;
	ReleaseYear = 0;
	ReleaseMonth = 0;
	ActorFirstName = "";
	ActorLastName = "";
}

//classic deconstructor
Classic::~Classic() {}

//printing the classic Movie
ostream& operator<<(ostream& Os, const Classic& M)
{
	Os << "Type:" << M.MovieType << "," << M.Title << " " <<
		M.ActorFirstName << " " << M.ActorLastName << " " << M.ReleaseMonth
		<< " " << M.ReleaseYear;
	return Os;
}

// overloading the compare operator for drama movies
bool operator<(const Classic& lhs, const Classic& rhs)
{
	// comparing release year
	if (lhs.ReleaseYear < rhs.ReleaseYear)
	{
		return true;
	}
	else if (lhs.ReleaseYear == rhs.ReleaseYear)
	{
		// comparing release month
		if (lhs.ReleaseMonth < rhs.ReleaseMonth)
		{
			return true;
		}
		else if (lhs.ReleaseMonth == rhs.ReleaseMonth)
		{
			// comparing actor first name
			if (lhs.ActorFirstName < rhs.ActorFirstName)
			{
				return true;
			}
			else if (lhs.ActorFirstName == rhs.ActorFirstName)
			{
				return false;
				//return (this->ActorLastName < rhs.ActorLastName);
			}
		}
	}
	return false;
}

// overloading equals to operator for Classic
bool operator==(const Classic& lhs, const Classic& rhs)
{
	if (
		lhs.MovieType == rhs.MovieType &&
		lhs.Director == rhs.Director &&
		lhs.Title == rhs.Title &&
		lhs.ActorFirstName == rhs.ActorFirstName &&
		lhs.ActorLastName == rhs.ActorLastName &&
		lhs.ReleaseMonth == rhs.ReleaseMonth &&
		lhs.ReleaseYear == rhs.ReleaseYear
		)
	{
		return true;
	}
	return false;
}
