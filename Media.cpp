#include "Media.h"

//constructor
Media::Media()
{
	MediaType = '\0';
}

// ostream overloader to print media
ostream& operator<<(ostream& Os, const Media& M)
{
	Os << "MediaType = " << M.MediaType;
	return Os;
}

// creates a media object
MediaFactory::MediaFactory()
{
	// not being implemented
	/*
	MediaTypes = {);
	MediaTypes['D'] = new DVD();
	*/
}

// deconstructor
MediaFactory::~MediaFactory()
{
	for (auto& Media : MediaTypes)
	{
		delete Media.second;
	}
	MediaTypes.clear();
}

// makes a media type depending on the passed in
// variable and returns that object
Media* MediaFactory::makeMedia(char Type)
{
	return MediaTypes[Type];
}
