#ifndef STORY
#define STORY
#include "Paragraph.h"
#include <ostream>

class Paragraph;

class Story{
	private:
	public:
		Paragraph* paragraphHead;
		Story();
		Story(const Paragraph& otherParagraph);
		//Creating a story from the file
		Story(char const* inFile);
		//Copy Constructor used for overloading	
		Story(const Story& otherStory);
		//assignment operator overload
		Story& operator=(const Story& otherStory);
		//deconstructor #Big 3
		~Story();
		
		//Append second story's paragraphs to end of existing story's
		void operator +(Story& otherStory);
		//Apend new paragraph to end of existing story's
		void operator +(Paragraph& otherParagraph);
		//Makes entire story uppercase
		Story& operator ++(int);
		//Makes entire story lowercase
		Story& operator --(int);
		//Pig latin
		Story& operator ++();
		//Unpigyay atinlay
		Story& operator --();
		//Capitalize all paragraphs' sentences' first words
		Story& operator +(int num);
		//Outputs all paragraphs with blank lines inbetween each
		friend std::ostream& operator <<(std::ostream& out, Story const& story);

		void show();
		void save(char const* outFile);
};

#endif

