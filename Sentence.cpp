#include "Sentence.h"
#include <iostream>
#include <stdio.h>

Sentence::Sentence(){
	std::cout << "Called Sentence::Sentence() [default constructor]" << std::endl;
	wordHead = NULL;
	sentenceNext = NULL;
	printPunctuation = (char*)malloc(sizeof(char));
	printPunctuation[0] = '.';
}

Sentence::Sentence(const Word& otherWord){
	wordHead = new Word(otherWord);
	sentenceNext = NULL;
	printPunctuation = (char*)malloc(sizeof(char));
	printPunctuation[0] = '.';
}
//Copy Constructor used for overloading	
Sentence::Sentence(const Sentence& otherSentence){
	std::cout << "Called Sentence::Sentence(Sentence &) [copy constructor]" << std::endl;

	Sentence* dummy = this;
	wordHead = new Word(otherSentence.wordHead->word);
	sentenceNext = NULL;
	Word* iter = otherSentence.wordHead;
	Word* root = wordHead;
	printPunctuation = (char*)malloc(sizeof(char));
	strncopy(this->printPunctuation, otherSentence.printPunctuation, 1);

	while(iter->next){
		root->next = new Word(iter->next->word);
		root = root->next;
		iter = iter->next;
	}
}

//assignment operator overload
Sentence& Sentence::operator=(const Sentence& otherSentence){
	std::cout << "Called Sentence::operator=((Sentence) [assignment operator]" << std::endl;
	Sentence* dummy = this;
	if(this != &otherSentence){
		while(this->wordHead){
			Word* prev = this->wordHead->next;
			delete(this->wordHead);
			this->wordHead = prev;
		}

		wordHead = new Word(otherSentence.wordHead->word);
		sentenceNext = NULL;
		free(printPunctuation);
		printPunctuation = (char*)malloc(sizeof(char));
		strncopy(this->printPunctuation, otherSentence.printPunctuation, 1);

		Word* iter = otherSentence.wordHead;
		Word* root = wordHead;

		while(iter->next){
			root->next = new Word(iter->next->word);
			root = root->next;
			iter = iter->next;
		}
	}
	return *dummy;
}

//deconstructor #Big 3
Sentence::~Sentence(){
	std::cout << "Called Sentence::~Sentence() [destructor]" << std::endl;
	Word* iter = this->wordHead;
	Word* dummy = this->wordHead;
	free(printPunctuation);
	while(iter){
		//std::cout << " on " << iter->word <<  " with address: " << iter << std::endl;
		//std::cout << " with its next address value being " << iter->next << std::endl;
		iter = iter->next;
		delete(dummy);
		dummy = iter;
	}

}

//Append sentence to front of paragraph
Paragraph& Sentence::operator +(Paragraph& otherParagraph){
	std::cout << "Called Sentence::operator+(Paragraph). Will return a new Paragraph with an additional Sentence at the beginning" << std::endl;
	return otherParagraph;
}

//Create new paragraph from two sentences
Paragraph* Sentence::operator +(Sentence& otherSentence){
	std::cout << "Called Sentence::operator+(Sentence). Will return a new Paragraph containing two Sentences" << std::endl;
	Paragraph* para = new Paragraph();
	Sentence* tempThis = new Sentence(*this);
	tempThis->sentenceNext = new Sentence(otherSentence);
	para->sentenceHead = tempThis;
	otherSentence.sentenceNext = NULL;
	return para;
}

//Append word to end of current sentence
void Sentence::operator+(Word& otherWord){
	std::cout << "Called Sentence::operator+(Word). Will return a new Sentence with one Word appended." << std::endl;
	
	Sentence* temp = this;
	Word* tempWord = temp->wordHead;
	while(temp->wordHead->next != NULL)
		temp->wordHead = temp->wordHead->next;
	temp->wordHead->next = new Word(otherWord.word);
	temp->wordHead = tempWord;
	/*
	if(wordHead){
		Word* tempWord = wordHead;
		Word* par = tempWord;
		while(tempWord){
			par = tempWord;
			tempWord = tempWord->next;
		}
		par->next = new Word(otherWord);
	}
	else{
		wordHead = new Word(otherWord);
	}
	return this;
	*/
}

//Makes entire sentence uppercase
Sentence& Sentence::operator ++(int){
	std::cout << "Called Sentence::operator++() [postfix ++] Will return this Sentence with all Words in all caps" << std::endl;
	return *this;
}

//Makes entire sentence lowercase
Sentence& Sentence::operator --(int){
	std::cout << "Called Sentence::operator--() [postfix --]  Will return this Sentence with all Words lowercase" << std::endl;
	return *this;
}

//Capitalize first letter of first word of the sentence
Sentence& Sentence::operator +(int num){
	if(num == 1){
		std::cout << "Called Sentence::operator--() [postfix --]  Will return this Sentence with all Words lowercase" << std::endl;
	}else{}
	return *this;
}

//Pig latin
Sentence& Sentence::operator ++(){
	std::cout << "Called Sentence::operator++(int) [prefix ++] Will return this Sentence with all Words in Pig Latin" << std::endl;
	return *this;
}

//Unpigyay atinlay
Sentence& Sentence::operator --(){
	std::cout << "Called Sentence::operator--(int) [prefix --] Will return this Sentence with all Pig Latin words converted back to English" << std::endl;
	return *this;
}

//Outputs all words of the sentence with a space, null pointer gets punctuation and a single space
std::ostream& operator <<(std::ostream &out, const Sentence& sentence){
	Word* temp = sentence.wordHead;
	int i = 0;
	while(temp != NULL){
		out << *temp;
		temp = temp->next;
		if(temp != NULL)
			out << " ";
	}
	out <<  sentence.printPunctuation[0];
	return out <<  " ";
}

void Sentence::show(){
	int i = 0;
	while(this->wordHead != NULL){
		for(int i = 0; this->wordHead->word[i] != '\0'; i++){
			std::cout << this->wordHead->word[i];
		}
		wordHead = wordHead->next;
		
		if(this->wordHead != NULL){
			std::cout << " ";
		}
	}
}

char* Sentence::strncopy(char *dest, const char *src, int n){
	dest[0] = src[0];
	return dest;
}