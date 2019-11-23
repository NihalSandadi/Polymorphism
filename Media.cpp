#include "Media.h"

Media::Media()
{
  MediaType = '';
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

friend ostream& operator<<(ostream& Os, const Media& M)
{
  Os << "MediaType = " << M->MediaType << " Quantity = " << M->Quantity
    << " Title = " << M->Title;
}

class MediaFactory
{
private:
map<char, Media*> MediaTypes;
public:
MediaFactory::MediaFactory();
MediaFactory::~MediaFactory();
Media* MediaFactory::makeMedia(char);
};
