#include <iostream>
#include <cstring>

using namespace std;

#include "cardFunctions.h"

int charToint(char digit){
    int digitNumber = static_cast<int>(digit) - 48;
    return digitNumber;
}

int doubledDigitValue(int number){
int doubled, total = 0, sum = 0;
 number = number * 2;
 doubled = number;
 if (doubled >=10){
   while (doubled != 0)
 {
     sum = sum + doubled % 10;
     doubled = doubled / 10;
 }
    cout << total;
 }else{
    cout << number;
 }
 return number;
}

string getCardType(const string& cardNumber){
    int firstDigit = cardNumber[0];
    int secondDigit = cardNumber[1];
    int totalDigit = 0;
    firstDigit = charToint(cardNumber[0]);
    secondDigit = charToint(cardNumber[1]);
    totalDigit = firstDigit + secondDigit;
    switch(firstDigit){
    case 4: cout << "Visa" << endl;
        break;
    case 5: cout << "MasterCard" << endl;
        break;
    }
    switch(totalDigit){
    case 7:
    case 10: cout << "American Express" << endl;
        break;
    default: cout << "Unknown issuer" << endl;
        break;
    }
    return cardNumber;
}

int luhnDigitSum (const string& cardNumber){
    if (cardNumber.size() % 2 == 0){
        for(unsigned n = 1; n < cardNumber.length(); n+= 2){
            char otherNumber = cardNumber.at(n);
            cout << otherNumber;
        }
    }else{
        for(unsigned n = 0; n < cardNumber.length(); n+= 2){
            char otherNumber = cardNumber.at(n);
            cout << otherNumber;
        }
    }
    return 0;
}

/*
bool isValid(const string& cardNumber);
if (cardnumber % 10){
    return true;
}
else{
    return false;
}
*/
