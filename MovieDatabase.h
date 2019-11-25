#include <string>
#include <vector>
#include "BST.cpp"

using namespace std;

//forward declaration
class Movie;

class MovieDatabase {
private:
	 // vector<BST<Movie*>> Movies;
	 vector<Movie*> Movies;

public:
	MovieDatabase();
	~MovieDatabase();
	Movie* getMovie(string);
	bool add(Movie* movie);
	bool remove(Movie* movie);
	bool clear();
	void showInventory();
	int getHash(string);
};
