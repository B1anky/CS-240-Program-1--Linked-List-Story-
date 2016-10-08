//Brett Sackstein
#include <iostream>
using namespace std;

#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"
int main() {
    //I have checked for almost all errors with clang++ -Weverything, 
    //the only remaining issues had to do with compiler padding
    //or a few implicit conversions where it was handled correctly.
    //Valgrind is outputting no leaks and no excess frees/deletes.

    //I have tested literally every case the assignment asks for

    //Creates all three story objects of the text files
    Story myStoryFreshPrince("FreshPrince.txt");
    Story myStoryGilligan("Gilligan.txt");
    Story myStoryBrady("Brady.txt");
    //Converts them all correctly to pig latin
    ++myStoryFreshPrince;
    ++myStoryGilligan;
    ++myStoryBrady;
    //Saves the pig latin version
    myStoryFreshPrince.save("FreshPrincePL.txt");
    myStoryGilligan.save("GilliganPL.txt");
    myStoryBrady.save("BradyPL.txt");
    //Converts back to normal
    --myStoryFreshPrince;
    --myStoryGilligan;
    --myStoryBrady;
    //Saves the normalized piglatin and you can diff them if you want, but 
    //I can tell you they're already the same
    myStoryFreshPrince.save("FreshPrinceEnglish.txt");
    myStoryGilligan.save("GilliganEnglish.txt");
    myStoryBrady.save("BradyEnglish.txt");

    //Testing the creation of a story through smaller parts
    cout << "----CREATING STORY FROM SMALL PARTS----"<<endl;
    char test1[] = {'T','h','i','s','\0'};
    char test2[] = {'i', 's', '\0'};
    char test3[] = {'a', '\0'};
    char test4[] = {'s','t','o','r', 'y','\0'};
    Word word1(test1);
    Word word2(test2);
    Word word3(test3);
    Word word4(test4);
    Sentence *storyTestSen1 = word1 + word2;
    *storyTestSen1 + word3;
    *storyTestSen1 + word4;
    Paragraph *storyTestPar1 = new Paragraph(*storyTestSen1);
    char test5[] = {'I', 't','\0'};
    char test6[] = {'h', 'a', 's','\0'};
    char test7[] = {'t', 'h', 'r', 'e', 'e', '\0'};
    char test8[] = {'p', 'a', 'r', 'a', 'g', 'r', 'a', 'p', 'h', 's', '\0'};
    Word word5(test5);
    Word word6(test6);
    Word word7(test7);
    Word word8(test8);
    Sentence *storyTestSen2 = word5 + word6;
    *storyTestSen2 + word7;
    *storyTestSen2 + word8;
    char test9[] = {'T', 'h', 'e', '\0'};
    char test10[] = {'f', 'i', 'r', 's', 't', '\0'};
    char test11[] = {'p', 'a', 'r', 'a', 'g', 'r', 'a', 'p', 'h', '\0'};
    char test12[] = {'c', 'o', 'n', 't', 'a', 'i', 'n', 's', '\0'};
    char test13[] = {'o', 'n', 'e', '\0'};
    char test14[] = {'s', 'e', 'n', 't', 'e', 'n', 'c', 'e', '\0'};
    Word word9(test9);
    Word word10(test10);
    Word word11(test11);
    Word word12(test12);
    Word word13(test13);
    Word word14(test14);
    Sentence *storyTestSen3 = word9 + word10;
    *storyTestSen3 + word11;
    *storyTestSen3 + word12;
    *storyTestSen3 + word13;
    *storyTestSen3 + word14;
    char test15[] = {'T', 'h', 'i', 's', '\0'};
    char test16[] = {'o', 'n', 'e', '\0'};
    char test17[] = {'h', 'a', 's','\0'};
    char test18[] = {'t', 'h', 'r', 'e', 'e', '\0'};
    char test19[] = {'a', 'n', 'd','\0'};
    char test20[] = {'t', 'h', 'e', '\0'};
    char test21[] = {'l', 'a', 's', 't','\0'};
    char test22[] = {'h', 'a', 's','\0'};
    char test23[] = {'t', 'w', 'o','\0'};
    Word word15(test15);
    Word word16(test16);
    Word word17(test17);
    Word word18(test18);
    Word word19(test19);
    Word word20(test20);
    Word word21(test21);
    Word word22(test22);
    Word word23(test23);
    Sentence *storyTestSen4 = word15 + word16;
    *storyTestSen4 + word17;
    *storyTestSen4 + word18;
    *storyTestSen4 + word19;
    *storyTestSen4 + word20;
    *storyTestSen4 + word21;
    *storyTestSen4 + word22;
    *storyTestSen4 + word23;
    Paragraph *storyTestPar2 = *storyTestSen2 + *storyTestSen3;
    *storyTestPar2 + *storyTestSen4;
    char test24[] = {'I', 't', '\0'};
    char test25[] = {'i', 's', '\0'};
    char test26[] = {'n', 'o', 't','\0'};
    char test27[] = {'v', 'e', 'r', 'y', '\0'};
    char test28[] = {'i', 'n', 't', 'e', 'r', 'e', 's', 't', 'i', 'n', 'g', '\0'};
    Word word24(test24);
    Word word25(test25);
    Word word26(test26);
    Word word27(test27);
    Word word28(test28);
    Sentence *storyTestSen5 = word24 + word25;
    *storyTestSen5 +word26;
    *storyTestSen5 +word27;
    *storyTestSen5 +word28;
    char test29[] = {'T', 'h', 'e', '\0'};
    char test30[] = {'e', 'n', 'd', '\0'};
    Word word29(test29);
    Word word30(test30);
    Sentence *storyTestSen6 = word29 + word30;
    Paragraph *storyTestPar3 = *storyTestSen5 + *storyTestSen6;
    Story *fullStory = new Story(*storyTestPar1);
    *fullStory + *storyTestPar2;
    *fullStory + *storyTestPar3;
    std::cout << *fullStory;

    cout << "----TESTING ALL WORD OPERATIONS----" << endl;
    Word word31(word1);
    cout << word31 << endl;
    Word word32(word2);
    cout << word32 << endl;
    word32 = word31;
    cout << word32 << endl;
    word31++;
    cout << word31 << endl;
    word31--;
    cout << word31 << endl;
    //Does nothing as specified
    word31 + 2;
    cout << word31 << endl;
    word31 + 1;
    cout << word31 << endl;
    ++word31;
    cout << word31 << endl;
    --word31;
    cout << word31 << endl;
    cout << "----TESTING ALL SENTENCES OPERATIONS----" << endl;
    Sentence *s1 = word1 + word2;
    cout << *s1 << endl;
    *s1 + word3;
    cout << *s1 << endl;
    *s1 + word4; 
    cout << *s1 << endl;
    Sentence s2(*s1);
    cout << s2 << endl;
    *s1 + word4;
    //s2 should be unnaffected by the above change, since deep copy
    cout << s2 << endl;
    s2 = *s1;
    cout << s2 << endl;
    s2++;
    cout << s2 << endl;
    s2--;
    cout << s2 << endl;
    //Should do nothing as specified
    s2 + 2;
    cout << s2 << endl;
    s2 + 1;
    cout << s2 << endl;
    ++s2;
    cout << s2 << endl;
    --s2;
    cout << s2 << endl;
    cout << "----TESTING ALL PARAGRAPH OPERATIONS----" << endl;
    Paragraph *p1 = *storyTestSen5 + *storyTestSen4;
    *p1 + *storyTestSen5;
    cout << *p1 << endl;
    (*p1)++;
    cout << *p1 << endl;
    (*p1)--;
    cout << *p1 << endl;
    //Should do nothing as specified
    (*p1) + 2;
    cout << *p1 << endl;
    (*p1) + 1;
    cout << *p1 << endl;
    ++(*p1);
    cout << *p1 << endl;
    --(*p1);
    cout << *p1 << endl;
    cout << "----TESTING ALL STORY OPERATIONS----" << endl;
    Story* st1 = new Story(*storyTestPar1);
    *st1 + *storyTestPar2;
    *st1 + *storyTestPar3;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    (*st1)++;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    (*st1)--;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    //Should do nothing as specified
    (*st1) + 2;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    (*st1) + 1;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    ++(*st1);
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    --(*st1);
    cout << *st1 << endl;
    cout << "----TESTING a + b operations IN ORDER----" << endl;
    //Story + Story 
    *st1 + *fullStory;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    //Story + Paragraph
    *st1 + *storyTestPar2;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
    //Paragraph + Story
    *storyTestPar2 + *st1;
    cout << *st1 << endl;
    cout << "______________________________________________________________" << endl;
   //Paragraph + Paragraph
    Paragraph* biggerParagraph = new Paragraph(*storyTestPar1);
    *biggerParagraph + *storyTestPar2;
    cout << *biggerParagraph << endl;
    cout << "______________________________________________________________" << endl;
    //Paragraph + Sentence
    Paragraph* biggerParagraph2 = new Paragraph(*storyTestPar1);
    *biggerParagraph2 + *storyTestSen2;
    cout << *biggerParagraph2 << endl;
    cout << "______________________________________________________________" << endl;
    //Sentence + Paragraph
    Paragraph* biggerParagraph3 = new Paragraph(*storyTestPar1);
    *storyTestSen2 +*biggerParagraph3; 
    cout << *biggerParagraph3 << endl;
    cout << "______________________________________________________________" << endl;
    //Sentence + Sentence
    Paragraph* fromTwoSentences = *storyTestSen5 + *storyTestSen6;
    cout << *fromTwoSentences << endl;
    cout << "______________________________________________________________" << endl;
    //Sentence + Word
    Sentence biggerSentence(*storyTestSen2);
    biggerSentence + word28;
    cout << biggerSentence << endl;
    cout << "______________________________________________________________" << endl;
    //Word + Sentence
    word28 + biggerSentence;
    cout << biggerSentence << endl;
    cout << "______________________________________________________________" << endl;
    //Word + Word
    Sentence* fromTwoWords = word1 + word2;
    cout << *fromTwoWords << endl;
    cout << "______________________________________________________________" << endl;
    
    cout << "----TESTING FIRST() AND REST()----" << endl;
    //first() of a sentence
    Word firstWordOfSent = storyTestSen5->first();
    cout << firstWordOfSent << endl;

    //rest() of a sentence
    Sentence restOfSent = storyTestSen5->rest();
    cout << restOfSent << endl;

    //first() of a paragraph
    Sentence firstSenOfPar = storyTestPar2->first();
    cout << firstSenOfPar << endl; 

    //rest() of a paragraph
    Paragraph restOfPar = storyTestPar2->rest();
    cout << restOfPar << endl; 

    cout << "_________below_is_the_current_fullStory______________" << endl; 

    cout << *fullStory << endl; 

    cout << "_________below_is_the_first_paragraph_of_fullStory_______________" << endl; 

    //first() of a story
    Paragraph firstParOfStr = fullStory->first();
    cout << firstParOfStr << endl; 
    cout << "_________below_is_the_rest_of_fullStory_______________" << endl;

    //rest() of a story
    Story restOfStr = fullStory->rest();
    cout << restOfStr << endl; 

    //AAAAAND DONE

    delete(s1);
    delete(p1);
    delete(st1);
    delete(biggerParagraph);
    delete(biggerParagraph2);
    delete(biggerParagraph3);
    delete(fromTwoSentences);
    delete(fromTwoWords);

    delete(storyTestSen1);
    delete(storyTestSen2);
    delete(storyTestSen3);
    delete(storyTestSen4);
    delete(storyTestSen5);
    delete(storyTestSen6);
    delete(storyTestPar1);
    delete(storyTestPar2);
    delete(storyTestPar3);
    delete(fullStory);
    return 0;
}
