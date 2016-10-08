#ifndef WORD
#define WORD

#include <ostream>
#include "Sentence.h"
#include <stdlib.h>

class Sentence;

class Word{
	private:

	public:

		Word *next;
		char *word;
		
		Word();
		Word(char *in);
		//Copy Constructor used for overloading	
		Word(const Word& otherWord);
		//assignment operator overload
		Word& operator=(const Word& otherWord);
		//deconstructor #Big 3
		~Word();

		//Append word to front of sentence
		const Sentence& operator +(Sentence& otherSentence);
		//Create new sentence from two words
		Sentence* operator +(Word& otherWord);
		//Makes entire word uppercase
		Word& operator ++(int);
		//Makes entire word lowercase
		Word& operator --(int);
		//Pig latin
		Word& operator ++();
		//Unpigyay atinlay
		Word& operator --();
		//Capitalize first letter
		Word& operator +(int num);
		//Outputs characters of the word
		friend std::ostream& operator <<(std::ostream& out, const Word & word);

		void show();
		//void insertParagraph(NodeStory paragraph);	

		char* strncopy(char *dest, const char *src, int n);
};
#endif