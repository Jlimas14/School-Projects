#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int GRID_SIZE = 10;

void printGrid(char grid[GRID_SIZE][GRID_SIZE]){
    for(int col = 0; col < GRID_SIZE; col++){
    }
    for(int row = 0; row < GRID_SIZE; row++){
        for(int col = 0; col < GRID_SIZE; col++){
        cout << grid[row][col];
    }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void copyGrid(char original[GRID_SIZE][GRID_SIZE], char newCopy[GRID_SIZE][GRID_SIZE]) {
    for(int r = 0; r < GRID_SIZE; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            newCopy[r][c] = original[r][c];
        }
    }
}

int checkSymbol(char grid[GRID_SIZE][GRID_SIZE], int startRow, int startCol) {
    if(startRow < 0 || startCol < 0 || startRow >= GRID_SIZE || startCol >= GRID_SIZE) {
        return 0;
    }
    if(grid[startRow][startCol] != '@') {
        return 0;
    }
    if(grid[startRow][startCol] == '@') {

        char updatedGrid[GRID_SIZE][GRID_SIZE];
        copyGrid(grid, updatedGrid);
        updatedGrid[startRow][startCol] = 'a';

    int total1 = checkSymbol(updatedGrid, startRow, startCol - 1);
    int total2 = checkSymbol(updatedGrid, startRow, startCol + 1);
    int total3 = checkSymbol(updatedGrid, startRow + 1, startCol);
    int total4 = checkSymbol(updatedGrid, startRow - 1, startCol);
    return 1 + total1 + total2 + total3 + total4;
    }

    return 0;
}

int main()
{

//    ifstream inFile("grid.txt");
//    if(inFile.fail()) {
//        cout << "File open error!";
//        exit(0);  //Close program
//    }

//    inFile.open("grid.txt");

    char grid[GRID_SIZE][GRID_SIZE] =
    {{'@','-','@','-','-','@','-','@','@','-'},
    {'@','@','@','-','@','@','-','@','-','-'},
    {'-','-','-','@','-','-','-','-','-','-'},
    {'@','@','-','@','@','@','-','@','@','@'},
    {'-','@','-','@','-','@','-','@','-','-',},
    {'@','@','-','@','@','@','-','@','@','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','@','@','@','-','@','-','-','-','-'},
    {'-','@','@','@','@','@','-','@','-','@'},
    {'-','-','-','-','-','-','-','@','-','@'}};

    printGrid(grid);
    cout << "Enter row and column:" << endl;
    int row = 0, col = 0;
    cin >> row;
    cin >> col;
    int length = checkSymbol(grid, row, col);
    cout << length << " cells" << endl;

//  inFile.close();

}
