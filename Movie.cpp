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
		throw "BAD MOVIE TYPE";
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
	MovieType = 'C';
	Director = "";
	Title = "";
	Quantity = 0;
	ReleaseYear = 0;
}

Comedy::~Comedy() {}

//printing out the comedy movie
ostream& operator<<(ostream& Os, const Comedy& M)
{
	 Os << M.MovieType << " Title " << M.Title << ", " << M.ReleaseYear;
	return Os;
}

// overloading the compare operator for comedy movies
bool Comedy::operator<(const Comedy& rhs) const
{
  if (this->Title < rhs.Title)
  {
    return true;
  }else if (this->Title == rhs.Title)
  {
    return (this->ReleaseYear < rhs.ReleaseYear);
  }
  return false;
}

// overloading equals to operator for Classic
bool Comedy::operator==(const Comedy& rhs) const
{
  if (
    this->MovieType == rhs.MovieType &&
    this->Director == rhs.Director &&
    this->Title == rhs.Title &&
    this->ReleaseYear == rhs.ReleaseYear
    )
  {
    return true;
  }
  return false;
}

//Beginning Of Drama Class
Drama::Drama() : Movie()
{
	MovieType = 'C';
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
	Os << M.MovieType << " F " << ", " << M.Title <<  ", " << M.ReleaseYear;
	return Os;
}

// overloading the compare operator for drama movies
bool Drama::operator<(const Drama& rhs) const
{
  if (this->Director < rhs.Director)
  {
    return true;
  }else if (this->Director == rhs.Director)
  {
    return (this->Title < rhs.Title);
  }
  return false;
}

// overloading equals to operator for Drama
bool Drama::operator==(const Drama& rhs) const
{
  if (
    this->MovieType == rhs.MovieType &&
    this->Director == rhs.Director &&
    this->Title == rhs.Title &&
    this->ReleaseYear == rhs.ReleaseYear
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
	Os << M.MovieType << " C " << ", " << M.Title << " " <<
		M.ActorFirstName << " " << M.ActorLastName << " " << M.ReleaseMonth
		<< " " << M.ReleaseYear;
	 return Os;
}

// overloading the compare operator for drama movies
bool Classic::operator<(const Classic& rhs) const
{
  // comparing release year
  if (this->ReleaseYear < rhs.ReleaseYear)
  {
    return true;
  }else if (this->ReleaseYear == rhs.ReleaseYear)
  {
    // comparing release month
    if (this->ReleaseMonth < rhs.ReleaseMonth)
    {
      return true;
    } else if (this->ReleaseMonth == rhs.ReleaseMonth)
    {
      // comparing actor first name
      if (this->ActorFirstName < rhs.ActorFirstName)
      {
        return true;
      } else if (this->ActorFirstName == rhs.ActorFirstName)
      {
        return (this->ActorLastName < rhs.ActorLastName);
      }
    }
  }
  return false;
}

// overloading equals to operator for Classic
bool Classic::operator==(const Classic& rhs) const
{
  if (
    this->MovieType == rhs.MovieType &&
    this->Director == rhs.Director &&
    this->Title == rhs.Title &&
    this->ActorFirstName == rhs.ActorFirstName &&
    this->ActorLastName == rhs.ActorLastName &&
    this->ReleaseMonth == rhs.ReleaseMonth &&
    this->ReleaseYear == rhs.ReleaseYear
    )
  {
    return true;
  }
  return false;
}
