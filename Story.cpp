#include "Story.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include "DynamicArr.h"


using namespace std;

Story::Story(){
	std::cout << "Called Story::Story() [default constructor]" << std::endl;
	paragraphHead = NULL;
}

//Creating story with one paragraph
Story::Story(const Paragraph& otherParagraph){
	std::cout << "Called Story::Story(const Paragraph& otherParagraph) [default constructor]" << std::endl;
	paragraphHead = new Paragraph(otherParagraph);
}

//Creating a story from the file
Story::Story(char const* inFile){
	std::cout << "Called Story::Story(char *) [default constructor]" << std::endl;
	char singleCharacter;
	ifstream fin;
	fin.open(inFile);
	DynamicArray arr;
	paragraphHead = NULL;
	Word* firstWord = NULL;
	Word* secondWord = NULL;
	Word* iterWord = NULL;
	Sentence* tempSentence = NULL;
	Paragraph* tempParagraph = NULL;

	if(fin.is_open()){
		while(fin.get(singleCharacter)){
			if((singleCharacter == '\t' || singleCharacter == '\n') && tempParagraph){
				if(paragraphHead == NULL && tempParagraph){
					paragraphHead = new Paragraph(*tempParagraph);
					delete(tempParagraph);
					tempParagraph = NULL;
				}else if(paragraphHead->nextParagraph == NULL && tempParagraph){
					paragraphHead->nextParagraph = new Paragraph(*tempParagraph);
					delete(tempParagraph);
					tempParagraph = NULL;
				}else{
					Paragraph *iter = paragraphHead->nextParagraph;					
					while(iter->nextParagraph){
						iter = iter->nextParagraph;
					}
					iter->nextParagraph = new Paragraph(*tempParagraph);
					delete(tempParagraph);
					tempParagraph = NULL;
				}
			}else if(singleCharacter == ' ' && arr.size() != 0 && !firstWord){
				firstWord =  new Word(arr.getData());
				arr.clear();
			}else if((singleCharacter == '.' || singleCharacter == '!' || singleCharacter == '?') && arr.size() != 0 && !firstWord){
				firstWord =  new Word(arr.getData());
				Sentence* leakSentence = new Sentence(*firstWord);
				
				if(singleCharacter == '!'){
					leakSentence->printPunctuation[0] = '!';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}else if(singleCharacter == '?'){
					leakSentence->printPunctuation[0] = '?';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}else if(singleCharacter == '.'){
					leakSentence->printPunctuation[0] = '.';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}
				delete(firstWord);
				firstWord = NULL;
				delete(leakSentence);
				arr.clear();
			}else if((singleCharacter == '.' || singleCharacter == '!' || singleCharacter == '?') && arr.size() != 0 && firstWord && !tempSentence){
				secondWord =  new Word(arr.getData());
				Sentence* leakSentence = *firstWord + *secondWord;
				if(singleCharacter == '!'){
					leakSentence->printPunctuation[0] = '!';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}else if(singleCharacter == '?'){
					leakSentence->printPunctuation[0] = '?';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}else if(singleCharacter == '.'){
					leakSentence->printPunctuation[0] = '.';
					if(!tempParagraph){
						tempParagraph = new Paragraph(*leakSentence);
					}else{
						*tempParagraph + *leakSentence;
					}
				}
				delete(firstWord);
				delete(secondWord);
				firstWord = NULL;
				secondWord = NULL;
				tempSentence = NULL;
				delete(leakSentence);

				arr.clear();

			}else if(singleCharacter == ' ' && arr.size() != 0 && firstWord && !tempSentence){
				secondWord =  new Word(arr.getData());
				Sentence* leakSentence = *firstWord + *secondWord;

				tempSentence =  new Sentence(*leakSentence);
				delete(leakSentence);
				delete(firstWord);
				delete(secondWord);
				arr.clear();

			}else if(singleCharacter == ' ' && tempSentence){
				iterWord =  new Word(arr.getData());
				*tempSentence + *iterWord;
				delete(iterWord);
				arr.clear();

			}else if((singleCharacter == '.' || singleCharacter == '?' || singleCharacter == '!') && tempSentence){
				if(singleCharacter == '?'){
					tempSentence->printPunctuation[0] = '?';
				}else if(singleCharacter == '!'){
					tempSentence->printPunctuation[0] = '!';
				}else{
					tempSentence->printPunctuation[0] = '.';
				}
				if(arr.size() != 0){
					iterWord =  new Word(arr.getData());
					*tempSentence + *iterWord;
				}else{
					//do nothing
				}
				
				if(!tempParagraph){
					tempParagraph = new Paragraph(*tempSentence);
				}else{
					*tempParagraph + *tempSentence;
				}
				delete(tempSentence);
				delete(iterWord);
				firstWord = NULL;
				secondWord = NULL;
				tempSentence = NULL;
				arr.clear();

			}else if(!(isspace(singleCharacter)) && singleCharacter != '.' && singleCharacter != '!' && singleCharacter != '?'){
				//cout << "Pushing:" << singleCharacter << endl;
				arr.push_back(singleCharacter);

			}else{	
				//do nothing
			}
		}
	}
	fin.close();	
}


//Copy Constructor used for overloading	
Story::Story(const Story& otherStory){
	std::cout << "Called Story::Story() [copy constructor]" << std::endl;
	Story* dummy = this;
	paragraphHead = new Paragraph(*otherStory.paragraphHead);
	Paragraph* iter = otherStory.paragraphHead;
	Paragraph* root = paragraphHead;

	while(iter){
		std::cout << "this paragraph is being copied is: " << iter << std::endl;
		root->nextParagraph = new Paragraph(*iter);
		root = root->nextParagraph;
		iter = iter->nextParagraph;
	}
	root = paragraphHead;

}

//assignment operator overload
Story& Story::operator=(const Story& otherStory){
	std::cout << "Called Story::operator=((Story) [assignment operator]" << std::endl;
	Story* dummy = this;
	paragraphHead = new Paragraph(*otherStory.paragraphHead);
	Paragraph* iter = otherStory.paragraphHead;
	Paragraph* root = paragraphHead;

	while(iter){
		std::cout << "this paragraph is being copied is: " << iter << std::endl;
		root->nextParagraph = new Paragraph(*iter);
		root = root->nextParagraph;
		iter = iter->nextParagraph;
	}
	root = paragraphHead;

	return *dummy;
}

//deconstructor #Big 3
Story::~Story(){
	std::cout << "Called Story::~Story() [destructor]" << std::endl;
	Paragraph* iter = this->paragraphHead;
	Paragraph* dummy = this->paragraphHead;
	
	while(iter){
		iter = iter->nextParagraph;
		delete(dummy);
		dummy = iter;
	}
}

//Append second story's paragraphs to end of existing story's
void Story::operator +(Story& otherStory){
	std::cout << "Called Story::operator + Story. evaluates to a new Story containing the paragraphs of the first Story followed by the paragraphs of the second Story" << std::endl;
	/*
	Story* temp = this;
	Paragraph* tempParagraph = temp->paragraphHead;
	while(temp->paragraphHead->nextParagraph)
		temp->paragraphHead = temp->paragraphHead->nextParagraph;
	temp->paragraphHead->nextParagraph = new Paragraph(otherStory.paragraphHead);
	temp->paragraphHead = tempParagraph;
	*/
}

//Apend new paragraph to end of existing story's
void Story::operator +(Paragraph& otherParagraph){
	std::cout << "Called Story::operator + Paragraph. Will return a new (one pargraph longer) Story" << std::endl;
	Story* temp = this;
	Paragraph* tempParagraph = temp->paragraphHead;
	while(temp->paragraphHead->nextParagraph)
		temp->paragraphHead = temp->paragraphHead->nextParagraph;
	temp->paragraphHead->nextParagraph = new Paragraph(otherParagraph);
	temp->paragraphHead = tempParagraph;
}

//Makes entire story uppercase
Story& Story::operator ++(int){
	std::cout << "Called Story::operator++() [postfix ++] Will return all Words in this Story in all caps" << std::endl;
	return *this;
}

//Makes entire story lowercase
Story& Story::operator --(int){
	std::cout << "Called Story::operator--() [postfix --] Will return all Words in this Story in all lowercase" << std::endl;
	return *this;
}

//Pig latin
Story& Story::operator ++(){
	std::cout << "Called Story::operator++() [prefix ++] Will return all Words in this Story converted to Pig Latin" << std::endl;
	return *this;
}

//Unpigyay atinlay
Story& Story::operator --(){
	std::cout << "Called Story::operator--() [prefix --] Will return all Words in this Story converted to regular English" << std::endl;
	return *this;
}

//Capitalize all paragraphs' sentences' first words
Story& Story::operator +(int num){
	if(num == 1){
		std::cout << "Called Story::operator+(int). Will return all Sentences in this Story with first char in caps" << std::endl;
	}else{}
	return *this;
}

//Outputs all paragraphs with blank lines inbetween each
std::ostream& operator <<(std::ostream &out, Story const& story){
	Paragraph* iter = story.paragraphHead;
	while(iter){
		out << *iter;
		iter = iter->nextParagraph;
	}
	return out;
}

void  Story::save(char const* file){
	ofstream outFile(file);
	outFile << *this;
	outFile.close();
}