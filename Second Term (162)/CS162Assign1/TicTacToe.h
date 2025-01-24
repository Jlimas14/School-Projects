#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>

using namespace std;


class TicTacToe{
private:
   char currentPlayer;
   char board[3][3];

public:
   TicTacToe();
   void print();
   char getCurrentPlayer();
   bool isDone();
   char getWinner();
   bool isValidMove(int row, int col);
   void makeMove(int row, int col);
};

/**
 * @brief Class TicTacToe creates functions that can work with a given tictactoe game
 */
//TicTacToe Class

/**
 * @brief currentPlayer is the player who starts the match or makes the next move
 */
char currentPlayer;

/**
 * @brief board[3][3] Makes a 3 by 3 array that makes a board
 */
char board[3][3];

/**
 * @brief TicTacToe() Default constructor for the private functions of the TicTacToe class
 * @return currentPlayer is X, and board set to defalut
 */
//TicTacToe();

/**
 * @brief print() creates a 3 by 3 board with any moves made
 */
void print();


/**
 * @brief getCurrentPlayer() Gets the player so they can make a move
 * @return the player that is starting or the one who hasn't made a move yet
 */
char getCurrentPlayer();

/**
 * @brief isDone() Checks the board and makes sure all dashes have been filled
 * @return true if all dashes on board are filled, else false
 */
bool isDone();

/**
 * @brief getWinner() Calculates if a row or column has 3 of the same shape
 * @return the player that won the match
 */
char getWinner();

/**
 * @brief isValidMove Checks the board to make sure the space given is valid
 * @param row and col are determined by the user
 * @return true if there are dashes in given area, else false if a shape is there
 */
bool isValidMove(int row, int col);


/**
 * @brief makeMove uses the row and column given to make a point shaped like the current player
 * @param row and col are determined by user
 */
void makeMove(int row, int col);


#endif // TICTACTOE_H
