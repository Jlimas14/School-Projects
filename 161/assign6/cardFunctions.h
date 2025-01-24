#ifndef CARDFUNCTIONS_H
#define CARDFUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief charToint converts a digit from char to int
 * @param digit Digit used to change char to int
 * @return the number that char contained
 */
int charToint(char digit);

/**
 * @brief doubledDigitValue Doubles the value and adds the sum
 *          if double digit
 * @param number Number used to double the value
 * @return double value or sum of two digits
 */
int doubledDigitValue(int number);

/**
 * @brief getCardType Finds the first digit to see which
 *           type of card it is
 * @param cardNumber CardNumber used to determine type
 * @return the type of card
 */
string getCardType(const string& cardNumber);

/**
 * @brief luhnDigitSum Follows the Luhn algorithm and doubles or adds values
 *              and changes depending if even or odd
 * @param cardNumber CardNumber used to find even or odd and add the values
 * @return the sum of the CardNumber
 */
int luhnDigitSum (const string& cardNumber);

/**
 * @brief isValid Finds if the card is valid or invalid based on the algorithm
 * @param cardNumber CardNumber used to determine if divisible by 10
 * @return true if total sum is divisible by 10
 */
bool isValid(const string& cardNumber);


#endif // CARDFUNCTIONS_H
