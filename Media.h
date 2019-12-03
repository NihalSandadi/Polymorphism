// ------------------------------------------------ Media.h --------------------------------------------------------
// Jayden Stipek Nihal CSS 343 B
// Creation: 10/25/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Encapsulates Movies as a Media type ('D')
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		Purpose of this is for abstraction and expandability
//		Now able to have different types of Media such as DVD'S,CD'S , etc
//		Able to have Quantity outside the movie itself in order for higher Inheritance/Abstraction
// -----------------------------------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <map>

#include <string>
#include "Movie.h"
using namespace std;

//forward declaration - MediaFactory creates Movie objects

class Media
{
	public: // protected
		char MediaType;
		Media();
		virtual ~Media() {};
    friend ostream& operator<<(ostream& Os, const Media& M);
};

class MediaFactory
{
private:
	map<char, Media*> MediaTypes;
public:
    MediaFactory();
    ~MediaFactory();
    Media* makeMedia(char);
};
