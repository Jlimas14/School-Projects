#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <string>
using namespace std;

const int ROWS = 12;
const int COLS = 10;

/**
 * @brief printKey prints all the words that are being hidden
 * @param grid creates a 12 x 10 grid
 * @return all correct letters from the grid
 */
void printKey(const char grid[ROWS][COLS]);

/**
 * @brief printPuzzle prints all words and adds random letters into grid
 * @param grid creates a 12 x 10 grid
 * @return all letters from grid
 */
void printPuzzle(const char grid[ROWS][COLS]);

/**
 * @brief countSpaces counts all the letters that aren't part of the key
 * @param grid creates a 12 x 10 grid
 * @return all the empty spaces in grid
 */
int countSpaces(const char grid[ROWS][COLS]);

/**
 * @brief checkHorizontalFit checks to see if there is room in
 *        the location given
 * @param grid creates a 12 x 10 grid, startRow is the start location for row,
 *        startCol is the start location for column,
 *        string word uses the word given
 * @return true or false depending if word can fit in location
 */
bool checkHorizontalFit(const char grid[ROWS][COLS],
                        int startRow,int startCol,const string& word);

/**
 * @brief placeHorizontal puts a word in the horizontal axis
 * @param grid creates a 12 x 10 grid, startRow is the start location for row,
 *        startCol is the start location for column,
 *        string word uses the word given
 * @return the grid with a new word
 */
bool placeHorizontal(char grid[ROWS][COLS],
                     int startRow, int startCol, const string& word);

/**
 * @brief placeDiagonal puts a word in the grid diagonally
 * @param grid uses a 12 x 10 grid, startRow is the start location for row,
 *        startCol is the start location for column,
 *        string word uses the word given
 * @return the grid with a new word and may replace other words
 */
void placeDiagonal(char grid[ROWS][COLS],
                   int startRow, int startCol, const string& word);

/**
 * @brief printLargestGaps prints the biggest gap between
 *        all the letters for each row
 * @param grid uses the 12 x 10 grid
 * @return the biggest gap between all the letters in each row
 */
void printLargestGaps(const char grid[ROWS][COLS]);


#endif // WORDSEARCH_H
