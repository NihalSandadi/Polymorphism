#include "Media.h"

Media::Media()
{
	MediaType = '\0';
}

ostream& operator<<(ostream& Os, const Media& M)
{
	Os << "MediaType = " << M.MediaType;
	return Os;
}

MediaFactory::MediaFactory()
{
	// not being implemented
	/*
	MediaTypes = {);
	MediaTypes['D'] = new DVD();
	*/
}

MediaFactory::~MediaFactory()
{
	MediaTypes.clear();
}

Media* MediaFactory::makeMedia(char Type)
{
	return MediaTypes[Type];
}
