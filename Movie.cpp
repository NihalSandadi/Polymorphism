// Movie implementation
#include "Movie.h"
#include  <iomanip>
using namespace std;

// virtual function
void Movie::display() const {}

// Default Constructor
Movie::Movie()
{
	MovieType = '\0';
	Quantity = 0;
}

// Printing out the movie
ostream& operator<<(ostream& Os, const Movie*& M)
{
	Os << " Title: " << M->Title << " Director: " << M->Director <<
		" Quantity: " << M->Quantity;
	return Os;
}

// creates a movie of a certain type and returns a movie pointer of that type
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
	}
	return nullptr;
}

// decrease the amount of movies stored in a database
void Movie::increaseQuantity()
{
	++Quantity;
}

// decreases the amount of movies stored in a database
void Movie::decreaseQuantity()
{
	// edge case
	if (0 >= Quantity) {
		cout << "QUANTITY UNDER 0 Cannot Borrow: " << this->Title << endl;
		return;
	}

	--Quantity;
}

//==============================================================================
//=============================Beginning of Genres==============================
//==============================================================================

// beginning of comedy

// Comedy constructor
Comedy::Comedy() : Movie()
{
	MovieType = 'F';
	Director = "";
	Title = "";
	ReleaseYear = 0;
}

// displays the comparable attributes
void Comedy::display() const
{

	cout << "Comedy " <<
		this->Title << " " <<
		this->Director <<
		" " << this->ReleaseYear;
}

// printing out the comedy movie
ostream& operator<<(ostream& Os, const Comedy& M)
{
	Os << "Comedy" <<
		setw(9) << M.Quantity << " "
		<< setw(35) << M.Title <<
		setw(25) << M.Director <<
		setw(12) << M.ReleaseYear;
	return Os;
}

// overloading the less than operator for comedy movies
bool operator<(const Comedy& lhs, const Comedy& rhs)
{
	if (lhs.Title < rhs.Title)
	{
		return true;
	}
	else if (lhs.Title == rhs.Title)
	{
		if (lhs.ReleaseYear < rhs.ReleaseYear)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return false;
}

// overloading equals to operator for Comedy
bool operator==(const Comedy& lhs, const Comedy& rhs)
{
	return
		(
			lhs.Title == rhs.Title &&
			lhs.ReleaseYear == rhs.ReleaseYear
			) ? true : false;
}

// Beginning Of Drama Class

// basic drama Constructor
Drama::Drama() : Movie()
{
	MovieType = 'D';
	Director = "";
	Title = "";
	ReleaseYear = 0;
}

// displays the comparable attributes
void Drama::display() const
{
	cout << "Drama " <<
		this->Title << " " <<
		this->Director <<
	" "<< this->ReleaseYear;
}

// Printing the Drama movie out formatted
ostream& operator<<(ostream& Os, const Drama& M)
{
	Os << "Drama " <<
		setw(9) << M.Quantity << " "
		<< setw(35) << M.Title <<
		setw(25) << M.Director <<
		setw(12) << M.ReleaseYear;
	return Os;
}

// overloading the less than operator for drama movies
bool operator<(const Drama& lhs, const Drama& rhs)
{
	if (lhs.Director < rhs.Director)
	{
		return true;
	}
	else if (lhs.Director == rhs.Director)
	{
		return (lhs.Title < rhs.Title);
	}
	return false;
}

// overloading equals to operator for Drama
bool operator==(const Drama& lhs, const Drama& rhs)
{
	return
		(lhs.Director == rhs.Director &&
			lhs.Title == rhs.Title);
}

// Beginning Of Classic Class

// basic constructor for classic movies
Classic::Classic() : Movie()
{
	MovieType = 'C';
	Director = "";
	Title = "";
	ReleaseYear = 0;
	ReleaseMonth = 0;
	ActorFirstName = "";
	ActorLastName = "";
}

// displays the comparable attributes
void Classic::display() const
{

	cout << "Classic " <<
		this->Title <<
		" " << this->ActorFirstName <<
		" " << this->ActorLastName <<
		setw(8) << this->ReleaseMonth << " " << this->ReleaseYear;
}

// printing the classic Movie
ostream& operator<<(ostream& Os, const Classic& M)
{
	Os << "Classic" <<
		setw(8) << M.Quantity << " "
		<< setw(35) << M.Title <<
		setw(17) << M.ActorFirstName <<
		" " << M.ActorLastName <<
		setw(8) << M.ReleaseMonth << " " << M.ReleaseYear;
	return Os;
}


// overloading the compare operator for classic movies
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
				// comparing actor last name
				return (lhs.ActorLastName < rhs.ActorLastName);
			}
		}
	}
	return false;
}

// overloading equals to operator for Classic
bool operator==(const Classic& lhs, const Classic& rhs)
{
	return
		(
			lhs.ActorFirstName == rhs.ActorFirstName &&
			lhs.ActorLastName == rhs.ActorLastName &&
			lhs.ReleaseMonth == rhs.ReleaseMonth &&
			lhs.ReleaseYear == rhs.ReleaseYear
			) ? true : false;
}
