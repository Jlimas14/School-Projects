#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
using namespace std;

#include "wordSearch.h"

void printKey(const char grid[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLS; j++){
      cout << grid[i][j];
    }
    cout << endl;
    }
}

void printPuzzle(const char grid[ROWS][COLS]){
      srand ((unsigned int)time(NULL));
      int randomletter = rand() % 25 + 65;
      for(int i = 0; i < ROWS; i++){
          for(int j = 0; j < COLS; j++){
          if (grid[i][j] == '_'){
              randomletter = rand() % 25 + 65;
              cout << static_cast<char>(randomletter);
       }else {
              cout << grid[i][j];
          }
          }
        cout << endl;
       }
}

int countSpaces(const char grid[ROWS][COLS]){
    int t = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
        if (grid[i][j] == '_'){
            t++;
        }
    }
}
    return t;
}



/*
bool checkHorizontalFit(const char grid[ROWS][COLS],
                        int startRow,int startCol,const string& word){
    bool status;

    int wordnumber = word.length();
    for(int i = startRow; i < ROWS; i++){
        for(int j = startCol; j < COLS; j++){
        if (wordnumber == grid[ROWS][COLS]){
          status = true;
        }
    }
}
    status = false;

return status;
}


bool placeHorizontal(char grid[ROWS][COLS],
                     int startRow, int startCol, const string& word);


void placeDiagonal(char grid[ROWS][COLS],
                   int startRow, int startCol, const string& word);


void printLargestGaps(const char grid[ROWS][COLS]);

*/




