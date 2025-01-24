#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <string>
using namespace std;

const int ROWS = 12;
const int COLS = 10;

void printKey(const char grid[ROWS][COLS]);


void printPuzzle(const char grid[ROWS][COLS]);


int countSpaces(const char grid[ROWS][COLS]);


bool checkHorizontalFit(const char grid[ROWS][COLS],
                        int startRow,int startCol,const string& word);


bool placeHorizontal(char grid[ROWS][COLS],
                     int startRow, int startCol, const string& word);


void placeDiagonal(char grid[ROWS][COLS],
                   int startRow, int startCol, const string& word);


void printLargestGaps(const char grid[ROWS][COLS]);


#endif // WORDSEARCH_H
