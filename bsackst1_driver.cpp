//Brett Sackstein
#include <iostream>
#include <stdlib.h>
#include "Story.h"
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"

using namespace std;

int main(int argc, char *argv[]){

	std::cout<<"Reading in story"<<endl;
	Story s("Brady.txt");

	cout<<"Printing Story:"<<endl<<s<<endl;

	s.save("OutBrady.txt");
	cout<<"Saved story"<<endl;

	//Get Sentence, Word, and Paragraph
	Paragraph p = s.first();
	Sentence se = s.first().first();
	Word w = s.first().first().first();

	//Test print new Paragraph, sentence, word
	cout<<"Printing paragraph:"<<endl<<p<<endl;
	cout<<"Printing sentence:"<<endl<<se<<endl;
	cout<<"Printing word:"<<endl<<w<<endl;

	//enter testing of more functions
	#define MORE_TESTS
	#ifdef MORE_TESTS

	cout<<endl<<"Passed initial tests, performing more"<<endl;

	//CAP AND LOWER CASE

	s++;
	cout<<endl<<"Printing cap story"<<endl<<s<<endl;
	s--;
	cout<<endl<<"Printing lower case story"<<endl<<s<<endl;

	p++;
	cout<<endl<<"Printing cap par"<<endl<<p<<endl;
	p--;
	cout<<endl<<"Printing lower par"<<endl<<p<<endl;


	se++;
	cout<<endl<<"Printing cap sent"<<endl<<se<<endl;
	se--;
	cout<<endl<<"Printing lower sent"<<endl<<se<<endl;

	w++;
	cout<<endl<<"Printing cap word"<<endl<<w<<endl;
	w--;
	cout<<endl<<"Printing lower word"<<endl<<w<<endl;

	//CAPPING FIRST CHAR

	s+1;
	cout<<endl<<"Printing first capped story"<<endl<<s<<endl;

	p+1;
	cout<<endl<<"Printing first capped para"<<endl<<p<<endl;

	se+1;
	cout<<endl<<"Printing first capped sent"<<endl<<se<<endl;

	w+1;
	cout<<endl<<"Printing first capped word"<<endl<<w<<endl;


	//PIG LATIN
	++s;
	cout<<endl<<"Printing pig latin story"<<endl<<s<<endl;

	++p;
	cout<<endl<<"Printing pig latin story"<<endl<<p<<endl;

	++se;
	cout<<endl<<"Printing pig latin sent"<<endl<<se<<endl;

	++w;
	cout<<endl<<"Printing pig latin word"<<endl<<w<<endl;

	--s;
	cout<<endl<<"Printing unpig latin story"<<endl<<s<<endl;

	--p;
	cout<<endl<<"Printing unpig latin para"<<endl<<p<<endl;

	--se;
	cout<<endl<<"Printing unpig latin sent"<<endl<<se<<endl;

	--w;
	cout<<endl<<"Printing unpig latin word"<<endl<<w<<endl;

	#endif

	#define DO_PLUSES
	#ifdef DO_PLUSES

	cout<<endl<<"Passed other tests, moving on to plus tests"<<endl;

	//word + word = sentence
	Word w2("adding");
	Sentence *se2 = w+w2;
	cout<<"Printing added words: "<<*se2<<endl;

	//word + sentence = sentence
	Word w3("front");
	Sentence *se3 = new Sentence(*se2);
	w3 + *se3;
	cout<<"Printing word+sentence: "<<*se3<<endl;

	//sentence + word = sentence
	Word w4("end");
	Sentence *se4 = new Sentence(*se3);
	*se4 + w4;
	cout<<"Printing sentence+word: "<<*se4<<endl;

	//sentence + sentence = paragraph
	Paragraph *p2 = *se3 + *se4;
	cout<<"Printing sentence+sentence: "<<*p2<<endl;

	//sentence + paragraph = paragraph
	Paragraph *p3 = new Paragraph(*p2);
	*se2 + *p3;
	cout<<"Printing sentence+paragraph: "<<*p3<<endl;

	//paragraph  + sentence = paragraph
	Paragraph *p4 = new Paragraph(*p3);
	*p4 + *se2;
	cout<<"Printing para+sentence: "<<*p4<<endl;

	//paragraph + paragraph = paragraph1paragraph2
	Paragraph *p5 = new Paragraph(*p3);
	*p5 + *p4;
	cout<<"Printing para+para: "<<*p5<<endl;

	//para + story = story
	Story *s2 = new Story(s);
	*p2 + *s2; 
	cout<<"Printing para+story: "<<*s2<<endl;

	//story + para = story
	Story *s3 = new Story(*s2);
	*s3 + *p2;
	cout<<"Printing story+para: "<<*s3<<endl;

	//story + story = story
	Story *s4 = new Story(*s2);
	*s4 + *s3;
	cout<<"Printing story + story: "<<*s4<<endl;

	delete(se2);
	delete(se3);
	delete(se4);
	delete(p2);
	delete(p3);
	delete(p4);
	delete(p5);
	delete(s2);
	delete(s3);
	delete(s4);
	cout<<endl<<"PASSED ALL TESTS"<<endl;
	#endif
}

