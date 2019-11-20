#include <iostream>
#include <map>
#include <string>

using namespace std;

//forward declaration - MediaFactory creates Movie objects
class Movie;

class Media
{
	public:
		char MediaType;
		int Quantity;
		string Title;

		Media();
		virtual ~Media();
		void increaseQuanity();
		void decreaseQuanity();
        virtual ostream& operator<<(ostream& Os, const Media& M);
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