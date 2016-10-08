#include "Paragraph.h"
#include <iostream>

Paragraph::Paragraph(){
	std::cout << "Called Paragraph::Paragraph() [default constructor]" << std::endl;
	sentenceHead = NULL;
	nextParagraph = NULL;
}

//Creating a paragraph with one sentence
Paragraph::Paragraph(const Sentence& otherSentence){
	std::cout << "Called Paragraph::Paragraph() [default constructor]" << std::endl;
	sentenceHead = new Sentence(otherSentence);
	nextParagraph = NULL;
}

Paragraph::Paragraph(const Paragraph& otherParagraph){
	std::cout << "Called Paragraph::Paragraph() [copy constructor]" << std::endl;

	Paragraph* dummy = this;
	sentenceHead = new Sentence(*otherParagraph.sentenceHead);
	nextParagraph = NULL;
	Sentence* iter = otherParagraph.sentenceHead->sentenceNext;
	Sentence* root = sentenceHead;

	while(iter){
		//std::cout << "This sentence being copied is: " << *iter << std::endl;
		root->sentenceNext = new Sentence(*iter);
		root = root->sentenceNext;
		iter = iter->sentenceNext;
	}
	root = sentenceHead;
}

Paragraph& Paragraph::operator=(const Paragraph& otherParagraph){
	std::cout << "Called Paragraph::operator=((Paragraph) [assignment operator]" << std::endl;
	Paragraph* dummy = this;
	sentenceHead = new Sentence(*otherParagraph.sentenceHead);
	nextParagraph = NULL;
	Sentence* iter = otherParagraph.sentenceHead;
	Sentence* root = sentenceHead;

	while(iter->sentenceNext){
		//std::cout << "this sentence being copied is: " << iter << std::endl;
		root->sentenceNext = new Sentence(*iter);
		root = root->sentenceNext;
		iter = iter->sentenceNext;
	}
	root = sentenceHead;
	return *dummy;
}

Paragraph::~Paragraph(){
	std::cout << "Called Paragraph::~Paragraph() [destructor]" << std::endl;
	Sentence* iter = this->sentenceHead;
	Sentence* dummy = this->sentenceHead;
	
	while(iter){
		iter = iter->sentenceNext;
		delete(dummy);
		dummy = iter;
	}
}

Story& Paragraph::operator +(Story& story){
	std::cout << "Paragraph + Story evaluates to a new Story with an additional paragraph at the beginning" << std::endl;
	return story;
}

Paragraph& Paragraph::operator +(Paragraph& otherParagraph){
	std::cout << "Called Paragraph::operator+(Paragraph): Will return a (new and bigger) Paragraph" << std::endl;
	return *this;
}

//Append sentence to end of current paragraph
void Paragraph::operator+(Sentence& otherSentence){
	std::cout << "Paragraph + Sentence evaluates to a new Paragraph with an additional Sentence at the end" << std::endl;
	Paragraph* temp = this;
	Sentence* tempSentence = temp->sentenceHead;
	while(temp->sentenceHead->sentenceNext)
		temp->sentenceHead = temp->sentenceHead->sentenceNext;
	temp->sentenceHead->sentenceNext = new Sentence(otherSentence);
	temp->sentenceHead = tempSentence;	
}

Paragraph& Paragraph::operator ++(int){
	std::cout << "If a is a Paragraph, makes the whole paragraph all caps" << std::endl;
	return *this;
}

Paragraph& Paragraph::operator --(int){
	std::cout << "If a is a Paragraph, makes the whole paragraph all lowercase" << std::endl;
	return *this;
}

Paragraph& Paragraph::operator +(int num){
	if(num == 1){
		std::cout << "Called Paragraph::operator+(int): Will return this Paragraph with initial letters of Sentences capitalized" << std::endl;
	}else{}
	return *this;
}

Paragraph& Paragraph::operator ++(){
	std::cout << "If a is a Paragraph, converts the whole paragraph to Pig Latin" << std::endl;
	return *this;
}

Paragraph& Paragraph::operator --(){
	std::cout << "If a is a Paragraph, converts all contained Words that are in Pig Latin back to English" << std::endl;
	return *this;
}

std::ostream& operator <<(std::ostream& out, const Paragraph& paragraph){
	Sentence* iter = paragraph.sentenceHead;
	out << '\t';
	
	while(iter){
		out << *iter;
		iter = iter->sentenceNext;
		
	}
	out << '\n';
	if(paragraph.nextParagraph){
		return out << '\n';	
	}else{
		return out;
	}
	
}
