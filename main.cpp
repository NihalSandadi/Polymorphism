#include <ostream>
#include <string>

#include "Movie.h"
//#include "bsttest.cpp"

using namespace std;

void testComedy()
{
  cout << "===TESTING COMEDY INITIALIZATION===" << endl;
  Movie* Movie1 = new Movie('F', "Nihal Sandadi");
  cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
  cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
  cout << "===!!!WORKS!!!===" << endl;
}

void testDrama()
{
  cout << "===TESTING DRAMA INITIALIZATION===" << endl;
  Movie* Movie1 = new Movie('D', "Nihal Sandadi");
  cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
  cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
  cout << "===!!!WORKS!!!===" << endl;
}

void testClassic()
{
  cout << "===TESTING CLASSIC INITIALIZATION===" << endl;
  Movie* Movie1 = new Movie('C', "Nihal Sandadi");
  cout << "Printing Director for Movie1 : " << Movie1->Director << endl;
  cout << "Printing MovieType for Movie1 : " << Movie1->MovieType << endl;
  cout << "===!!!WORKS!!!===" << endl;
}

void testMovieFactory()
{
  cout << "===TESTING MOVIE FACTORY===" << endl;
  MovieFactory* Factory1 = new MovieFactory();
  Factory1->MovieTypes['F'] = new Movie('F', "Nihal");
  Factory1->MovieTypes['D'] = new Movie('D', "Jayden");
  Factory1->MovieTypes['C'] = new Movie('C', "Pisan");

  cout << "Printing Director for movie F : " <<
    Factory1->MovieTypes['F']->Director << endl;
  cout << "Printing Director for movie D : " <<
    Factory1->MovieTypes['D']->Director << endl;
  cout << "Printing Director for movie C : " <<
    Factory1->MovieTypes['C']->Director << endl;

  cout << "===!!!WORKS!!!===" << endl;
}

//int main()
//{
//  //testComedy();
//  //testDrama();
//  //testClassic();
//  //testMovieFactory();
//  cout << "===END OF TESTS===" << endl;
//  return 0;
//}
