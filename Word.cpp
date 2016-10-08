#include "Word.h"
#include <stdio.h>
#include <iostream>

Word::Word()
{
	std::cout << "Called Word::Word() [default constructor]" << std::endl;
	word = NULL;
	next = NULL;
}

Word::Word(char* in)
{
	std::cout << "Called Word::Word(char* in) [default constructor]" << std::endl;
	int i = 0;
	//length of char* in
	for(i = 0; in[i] != '\0'; i++);
	i++;
	word = (char*)malloc(sizeof(char)*i);
	strncopy(word,in, i);
	next = NULL;
}

//Copy Constructor used for overloading	
Word::Word(const Word& otherWord){
	std::cout << "Called Word::Word() [copy constructor]" << std::endl;
	
	int i = 0;
	//length of char* in
	for(i = 0; otherWord.word[i] != '\0'; i++);
	i++;
	word = (char*)malloc(sizeof(char)*i);
	strncopy(word, otherWord.word, i);
	this->next = NULL;
}

//assignment operator overload
Word& Word::operator =(const Word& otherWord){
	std::cout << "Called Word::operator=((Word)) [assignment operator]" << std::endl;
	
	Word* dummy = this;
	int i = 0;
	free(dummy->word);
	for(i = 0; otherWord.word[i] != '\0'; i++);
	i++;
	word = (char*)malloc(sizeof(char)*i);
	strncopy(dummy->word, otherWord.word, i);
	return *dummy;
}
//deconstructor #Big 3
Word::~Word(){
	std::cout << "Called Word::~Word() [destructor]" << std::endl;
	std::cout << " Destroying: " << this->word << std::endl;
	free(this->word);
}

//Append word to front of sentence
const Sentence& Word::operator +(Sentence& otherSentence){
	Sentence* dummy;
	std::cout << "Called Word::operator+(Sentence). Will return a new Sentence with the Word added to the beginning" << std::endl;
	return *dummy;
}

//Create new sentence from two words
Sentence* Word::operator +(Word& otherWord){
	std::cout << "Called Word::operator+(Word). Will return a new Sentence containing two Words" << std::endl;

	Sentence* sen = new Sentence();
	Word* tempThis = new Word(this->word);
	tempThis->next = new Word(otherWord.word);
	sen->wordHead = tempThis;
	otherWord.next = NULL;
	return sen;
}

//Makes entire word uppercase
Word& Word::operator ++(int)
{
	std::cout << "Called Word::operator++() [postfix ++] Will return this word in all caps" << std::endl;
	return *this;
}

//Makes entire word lowercase
Word& Word::operator --(int)
{
	std::cout << "Called Word::operator--() [postfix --] Will return this word in all lowercase" << std::endl;
	return *this;
}

//Capitalize first letter
Word& Word::operator+(int num){
	if(num == 1){
		std::cout << "Called Word::operator+(int). If a is a Word, capitalizes the first letter" << std::endl;
	}else{}
	return *this;
}

//Pig latin
Word& Word::operator ++()
{
	std::cout << "Called Word::operator++(int) [prefix ++] Will return this word in Pig Latin (if it isn't already)" << std::endl;
	return *this;
}
//Unpigyay atinlay
Word& Word::operator --()
{
	std::cout << "Called Word::operator--(int) [prefix --] Will return this Word converted from Pig Latin to English" << std::endl;
	return *this;
}

//Outputs characters of the word
std::ostream& operator <<(std::ostream& out, const Word & word){
	return out << word.word;
}

void Word::show(){
	
}

char* Word::strncopy(char *dest, const char *src, int n){
	int i = 0;

	for(i = 0; i < n-1 && src[i]!='\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}