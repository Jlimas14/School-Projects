#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#include "gradeFunctions.h"

void getArrayData(int scores[], int size){
    int number;
    cout << "Enter 10 scores: ";
    for(int i = 0; i < size; i++){
    cin >> number;
    scores[i] = number;
}
}

double average(const int scores[], int size){
    double sum = 0, mean;
    for(int a = 0; a < size; a++){
        sum += scores[a];
}
        mean = sum / size;
    return mean;
}

double standardDeviation(const int scores[], int size, double mean){
    double  sum, squared, secondsum = 0, squaredMean, squareroot;
    for (int x = 0; x < size; x++) {
        sum = (scores[x] - mean);
        squared = pow(sum, 2);
        secondsum += squared;
}
        squaredMean = (1.0 / size) * secondsum;
        squareroot = sqrt(squaredMean);
    return squareroot;
}

char getLetterGrade(int score, double mean, double stdDev){
    char grade;
    double difference = abs(mean - score) / stdDev;
    if((difference >= 1) && (score > mean)){
        grade = 'A';
    }else if((difference < 1) && (difference > 0.5) && (score > mean)){
        grade = 'B';
    }else if(difference < 0.5){
        grade = 'C';
    }else if((difference < 1) && (difference > 0.5) && (score < mean)){
        grade = 'D';
    }else{
        grade = 'F';
    }
    return grade;
}
