/*
 Name: Maya Stelzer
 Class: CPSC 122, Spring 2023
 Date: Feburary 16, 2023
 Programming Assignment: PA3                                                                      
 Description: Pointers
 Notes:
*/

#ifndef PA3_H
#define PA3_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std;

// task 1
void answerIntegerQuestions(const int num, bool *, bool *, bool *);
bool ifMultiple(int num);
bool ifSumEvenOrOdd(int num);
bool ifPrime(int num);
void runTask1();


// task 2
bool findWinningLotteryTicket(int, const int *, const int);
void runTask2();


// task 3
string * createWordsArray(ifstream&, const int);
void generateSentence(string *, const string *, const int, const string *, const int, const string *, const int, const string *, const int);
void bubbleSortArrayGaddis(string * array, int size);
void swap(int &a, int &b);
void runTask3();

#endif