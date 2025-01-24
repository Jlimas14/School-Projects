/**
  * @brief Assigment 1 Problem 1
  * @author Jacob Limas
  */

#include <iostream>

using namespace std;

int main()
{
    int inches;
    cout << "Enter the number of inches: ";
    cin >> inches;
    int miles = inches / 63360;
    inches = inches % 63360;
    cout << miles << " mile(s)" << endl;
    int yards = inches / 36;
    inches = inches % 36;
    cout << yards << " yard(s)" << endl;
    int foot = inches / 12;
    inches = inches % 12;
    cout << foot << " foot/feet" << endl;
    cout << inches << " inch(es)" << endl;
    return 0;
}
