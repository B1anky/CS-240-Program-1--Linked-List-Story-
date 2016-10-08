#ifndef PARAGRAPH
#define PARAGRAPH

#include "Story.h"
#include "Sentence.h"

class Sentence;
class Story;


class Paragraph{
	private:
	public:
		Sentence* sentenceHead;
		Paragraph* nextParagraph;	
		Paragraph();
		Paragraph(const Sentence& otherSentence);
		//Copy Constructor used for overloading	
		Paragraph(const Paragraph& otherParagraph);
		//assignment operator overload
		Paragraph& operator=(const Paragraph& otherParagraph);
		//deconstructor #Big 3
		~Paragraph();

		//Evaluates to a new Story with an additional paragraph at the beginning
		Story& operator +(Story& story);
		//Append second paragraph's sentences to end of existing paragraph's sentences
		Paragraph& operator +(Paragraph& otherParagraph);
		//Append sentence to end of current paragraph
		void operator+(Sentence& otherSentence);
		//Makes entire paragraph uppercase
		Paragraph& operator ++(int);
		//Makes entire paragraph lowercase
		Paragraph& operator --(int);
		//Pig latin
		Paragraph& operator ++();
		//Unpigyay atinlay
		Paragraph& operator --();
		//Capitalize all sentences' first words
		Paragraph& operator +(int num);
		//Outputs all paragraphs' sentences, leading with a tab and followed with "endl"
		friend std::ostream& operator <<(std::ostream& out, const Paragraph& paragraph);

		void show();
		//void insertParagraph(NodeStory paragraph);	
};

#endif