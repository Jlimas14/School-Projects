#include <iostream>
#include <iomanip>

#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe(){
   currentPlayer = 'X';
   for(int i = 1; i < 4; i++) {
       for(int j = 1; j < 4; j++) {
            board[i][j] = 45;
       }
   }
}

void TicTacToe::print(){
   cout << "  1 2 3" << endl;
   for(int i = 1; i < 4; i++) {
       cout << i;
       for(int j = 1; j < 4; j++) {
           cout << " ";
           cout << board[i][j];
       }
       cout << endl;
   }
}

char TicTacToe::getCurrentPlayer(){
    return currentPlayer;
}

char TicTacToe::getWinner(){
   char winner = 45;
   for(int i = 1; i < 4; i++) {
     int score = 0;
     int secondScore = 0;
       for(int j = 1; j < 4; j++) {
        if(board[i][j] == currentPlayer){
            score++;
        }else{
            secondScore++;
            if(score == 3){
                winner = currentPlayer;
                return winner;
            }else if (secondScore == 3){
                winner = 'O';
                return winner;
            }
        }
       }
   }
    return winner;
}

bool TicTacToe::isDone(){
    int goal = 0;
    for(int i = 1; i < 4; i++) {
        for(int j = 1; j < 4; j++) {
            if(board[i][j] != 45){
                goal++;
            }
        }
    }
    if(goal >= 9){
        TicTacToe::print();
        return true;
    }else{
        return false;
    }
}

bool TicTacToe::isValidMove(int row, int col){
    if(board[row][col] == 45){
        return true;
    }else{
        return false;
    }
}

void TicTacToe::makeMove(int row, int col){
    board[row][col] = currentPlayer;
    if(currentPlayer == 'X'){
        currentPlayer = 'O';
    }else{
        currentPlayer = 'X';
    }
}
