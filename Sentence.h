#ifndef SENTENCE
#define SENTENCE

#include "Word.h"
#include "Paragraph.h"

class Word;
class Paragraph;

class Sentence{
	private:
		
	public:
		Word *wordHead;
		Sentence *sentenceNext;
		char* printPunctuation;
		
		Sentence();

		Sentence(const Word& otherWord);
		//Copy Constructor used for overloading	
		Sentence(const Sentence& otherSentence);
		//assignment operator overload
		Sentence& operator=(const Sentence& otherSentence);
		//deconstructor #Big 3
		~Sentence();

		//Append sentence to front of paragraph
		Paragraph& operator +(Paragraph& otherParagraph);
		//Create new paragraph from two sentences
		Paragraph* operator +(Sentence& otherSentence);
		//Append word to end of current sentence
		void operator+(Word& otherWord);
		//Makes entire sentence uppercase
		Sentence& operator ++(int);
		//Makes entire sentence lowercase
		Sentence& operator --(int);
		//Pig latin
		Sentence& operator ++();
		//Unpigyay atinlay
		Sentence& operator --();
		//Capitalize first letter of first word of the sentence
		Sentence& operator +(int num);
		//Outputs all words of the sentence with a space, null pointer gets punctuation and a single space
		friend std::ostream& operator <<(std::ostream& out, const Sentence& sentence);

		void show();

		char* strncopy(char *dest, const char *src, int n);
};
#endif