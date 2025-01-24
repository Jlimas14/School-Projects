/**
  * @brief Assignment 7
  * @author Jacob Limas
  */

#include <iostream>
#include <iomanip>

using namespace std;

#include "gradeFunctions.h"

int main()
{
/*
    int randomnumbers[10] = {70, 85, 75, 65, 82, 96, 58, 93, 86, 90};
    getArrayData(randomnumbers, 10);
*/

/*
    double mean;
    int randomnumbers[10] = {70, 85, 75, 65, 82, 96, 58, 93, 86, 90};
    mean = average(randomnumbers, 10);
    cout << mean << endl;
*/

/*
    double mean, stdDev;
    int randomnumbers[10] = {70, 85, 75, 65, 82, 96, 58, 93, 86, 90};
    mean = average(randomnumbers, 10);
    stdDev = standardDeviation(randomnumbers, 10, mean);
    cout << setprecision(3) << stdDev << endl;
*/
/*
    double mean, stdDev;
    int givennumbers[10] = {70, 85, 75, 65, 82, 96, 58, 93, 86, 90};
    for(int i = 0; i < 10; i++){
    cout << givennumbers[i] << " ";
    }
    cout << endl;
    mean = average(givennumbers, 10);
    stdDev = standardDeviation(givennumbers, 10, mean);
    for(int i = 0; i < 10; i++){
        char grade = getLetterGrade(givennumbers[i], mean, stdDev);
        cout << grade << "  ";
    }
*/

    int givennumbers[10];
    getArrayData(givennumbers, 10);
    int students[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << setprecision(3);
    double mean = average(givennumbers, 10);
    cout << "The average is: " << mean << endl;
    double stdDev = standardDeviation(givennumbers, 10, mean);
    cout << "The standard deviation is: " << stdDev << endl;
    cout << "Students:  ";
    for(int i = 0; i < 10; i++){
        cout << students[i] << "   ";
    }
    cout << endl;
    cout << "Grades:    ";
    for(int i = 0; i < 10; i++){
        char grade = getLetterGrade(givennumbers[i], mean, stdDev);
        cout << grade << "   ";
    }
    cout << endl;
}
