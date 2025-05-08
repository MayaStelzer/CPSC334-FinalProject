#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Package{
	int id;
	double weight;
	int width;
	int length;
	int height;
};

struct LetterOccurrence{
	int count;
	double frequency;
};

Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
void printPackageInfo(const Package packageInfo[], const string driverName, const int numPackages, const int heaviestId, const double heaviestWeight, const double avgWeight);
void extraCredit(LetterOccurrence letters[]);
void printHistogram(const LetterOccurrence letters[]);
void calculateFrequency(LetterOccurrence letters[], int size);


#endif
