#ifndef GRADEFUNCTIONS_H
#define GRADEFUNCTIONS_H

/**
 * @brief getArrayData gets a value from the user
 * @param scores used for array, size used to know how much is in array
 * @return all numbers from the score
 */
void getArrayData(int scores[], int size);

/**
 * @brief average gets the mean of all the values
 * @param scores is used for given array, size used to know amount in array
 * @return the mean of the array
 */
double average(const int scores[], int size);

/**
 * @brief standardDeviation uses sigma notation to get the difference value
 * @param scores used to store given numbers, size used as the amount in the array,
 *        mean is used as the average of the sum of the array
 * @return the standard deviation of the given array
 */
double standardDeviation(const int scores[], int size, double mean);

/**
 * @brief getLetterGrade finds a letter grade based of averages and standard
 *          deviation
 * @param scores used to store given numbers, mean used as sum average of the array
 *          stdDev used to compare the standard deviation with the scores
 * @return the letter grade that was calculated
 */
char getLetterGrade(int score, double mean, double stdDev);

#endif // GRADEFUNCTIONS_H
