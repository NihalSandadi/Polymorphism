#include "Media.h"

Media::Media()
{
  MediaType = '\0';
  Quantity = 0;
  Title = "";
}

Media::~Media() {}

void Media::increaseQuanity()
{
  ++Quantity;
}

void Media::decreaseQuanity()
{
  --Quantity;
}

ostream& operator<<(ostream& Os, const Media& M)
{
  Os << "MediaType = " << M.MediaType << " Quantity = " << M.Quantity
    << " Title = " << M.Title;
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
