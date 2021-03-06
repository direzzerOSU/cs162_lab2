#ifndef COUNTLETTERS_H
#define COUNTLETTERS_H

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
#include<cstring>
#include<map>
// #include<limits>     // to support: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

// function prototypes
void count_letters(ifstream &, int*);
void output_letters(ofstream &, int*);
int charToInt(char character);
char intToChar(int num);
void printCounts(ofstream& outputFile, int* counts);

#endif
