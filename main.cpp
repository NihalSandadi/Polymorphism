#include <ostream>
#include <string>

#include "Movie.h"

using namespace std;

int main()
{
  cout << "===TESTING COMEDY INITIALIZATION===" << endl;
  Movie* Movie1 = new Movie('F', "Nihal Sandadi");
  cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
  cout << "===END OF TESTS===" << endl;
  return 0;
}
