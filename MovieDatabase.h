#include <string>
#include <vector>
#include "BST.h"

using namespace std;

//forward declaration
class Movie;

class MovieDatabase {
private:
	 vector<BST<Movie*>> Movies;

public:
	MovieDatabase();
	~MovieDatabase();
	Movie* getMovie(string);
	bool add(Movie*);
	bool remove(Movie*);
	bool clear();
	void showInventory();
	int getHash(string);
};