CXX := clang++
FLAGS := -g 
#FLAGS := -g -Wextra -Wpedantic -Wall -Wno-unused-parameter -Wno-uninitialized 

all:	clean Program1

Program1:	Story.o Paragraph.o Sentence.o Word.o testProgram.o DynamicArr.o
	$(CXX) $(FLAGS) Story.o Paragraph.o Sentence.o Word.o testProgram.o DynamicArr.o -o prog1

Story.o:		Story.cpp 
	$(CXX) $(FLAGS) -c Story.cpp

Paragraph.o:		Paragraph.cpp
	$(CXX) $(FLAGS)-c Paragraph.cpp

Sentences.o:		Sentences.cpp
	$(CXX) $(FLAGS) -c Sentences.cpp

Word.o:		Word.cpp 
	$(CXX) $(FLAGS)-c Word.cpp

testProgram.o:	testProgram.cpp
	$(CXX) $(FLAGS)-c testProgram.cpp

DynamicArr.o:	DynamicArr.cpp
	$(CXX) $(FLAGS)-c DynamicArr.cpp

clean:
	rm -f *.o prog1
