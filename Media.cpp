#include "Media.h"

Media::Media()
{
	MediaType = '\0';
}
Media::~Media() {}

ostream& operator<<(ostream& Os, const Media& M)
{
	Os << "MediaType = " << M.MediaType;
	return Os;
}

MediaFactory::MediaFactory()
{
	//MediaTypes = {'d'};
}

MediaFactory::~MediaFactory()
{
	MediaTypes.clear();
}

Media* MediaFactory::makeMedia(char Type)
{
	return MediaTypes[Type];
}
