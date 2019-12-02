//Media.h 

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
		virtual ~Media();
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
