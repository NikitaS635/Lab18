#include <stdio.h>
#include "C:\Users\User2\CLionProjects\untitled\libs\data_structures\string\string_.h"
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
void test1()
{
    char s1[] = "fine line ten";
    removeNonLetters(s1);
    assert(strcmp(s1, "finelineten") == 0);
}
void test2()
{
    char s1[] = "fine   line     ten";
    removeExtraSpaces(s1);
    assert(strcmp(s1, "fine line ten") == 0);
}
void test3()
{
    char s1[] = "A32BC1";
    char *start = s1;
    WordDescriptor word;
    while(getWord(start,&word))
    {
        digitToStart(word);
        start = word.end;
    }
    assert(strcmp(s1, "123ABC") == 0);
}
void test4()
{
    char s1[] = "A32BC1";
    char *rez = replaceDigitsWithSpaces(s1);
    assert(strcmp(rez, "A     BC ") == 0);
}
void test5()
{
    char S[] = "line time play fine";
    char s1[] = "time";
    char s2[] = "car";
    replace(S, s1, s2);
    assert(strcmp(S, "line car play fine") == 0);
}
void test6()
{
    char s1[] = "apple banana citrus";
    assert(areWordsLexicographicallyOrdered(s1) == 1);
    char s2[] = "banana apple citrus";
    assert(areWordsLexicographicallyOrdered(s2) == 0);
}
void test7()
{
    char s1[] = "A BC D";
    BagOfWords del;
    getBagOfWords(&del,s1);
    for (int i = del.size - 1; i >= 0; i --)
    {
        printf("%.*s\n", (int)(del.words[i].end - del.words[i].begin), del.words[i].begin);
    }
    assert(del.size == 3);
    assert(strncmp(del.words[0].begin,"A", del.words[0].end-del.words[0].begin) == 1);
    assert(strncmp(del.words[1].begin,"BC", del.words[1].end-del.words[1].begin) == 1);
    assert(strncmp(del.words[2].begin,"D", del.words[2].end-del.words[2].begin) == 0);
}
void test8()
{
    char S[] = "level, tenet, time";
    printf("&s\n",S);
    char *token = strtok(S, ", ");
    int col = 0;
    while (token != NULL)
    {
        if(isPalindrome(token))
        {
            col++;
        }
        token = strtok(NULL, ", ");
    }
    assert(col == 2);
}
void test9()
{
    char S1[50] = "one three five";
    char s2[50] = "two four six";
    char rez[50+2];
    alternateWords(S1, s2, rez);
    assert(strcmp(rez, "one two three four five six") == 1);
}
void test10()
{
    char S[] = "one three five tree";
    reverseWords(S);
    assert(strcmp(S, "tree five three one") == 0);
}
void test11()
{
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);
    char s2[] = "ABC";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);
    char s3[] = "C A";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char s4[] = "BC D";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}
void test12()
{
    char S1[] = "one thre five tree";
    char s2[] = "five";
    WordDescriptor Word = lastWordInFirstStringInSecondString(S1, s2);
    char rez[25];
    wordDescriptorToString(Word, rez);
    assert(strcmp(rez, "five") == 0);
}
void test13()
{
    char S1[] = "one three five tree one";
    assert(hasDuplicateWords(S1) == 1);
}
void test14()
{
    char S1[] = "five veif";
    assert(hasPairWithSameLetters(S1) == 1);
}
void test15()
{
    char a[] = "hello world";
    removeLastWord(a);
    assert(strcmp(a, "hello") == 0);
}
void test16()
{
    char s1[] = "Hello max!";
    char s2[] = "This is a max.";
    char w1[20], w2[20], c[20];
    int i, j, f;
    f = 0;
    w1[0] = '\0';
    w2[0] = '\0';
    c[0] = '\0';
    i = 0;

    while (s1[i] != '\0' && f == 0) {
        prir(w1, c);
        read_word(s1, &i, w1);
        j = 0;
        while (s2[j] != '\0' && f == 0) {
            read_word(s2, &j, w2);
            f = proverka(w1, w2);
        }
    }
    assert(strcmp(c, "Hello") == 0);
}
void test17()
{
    char S[] = "ten tenet";
    removePalindromes(S);
    removeNonLetters(S);
    assert(strcmp(S, "ten") == 0 );
}
void test18()
{
    char S[100] = "a";
    char S1[100] = "a b";
    char S2[200] = "";
    strcpy(S2, S);
    copyLastWords(S1, S2);
    assert(strcmp(S2, "a b") == 0);
}
void test19()
{
    char S[] = "stpr";
    char S1[] = "sttt r ppp";
    assert(wordInString(S, S1) == 1);
}

void alltest()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();

    printf("Все тесты пройдены");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    alltest();
    return 0;
}
