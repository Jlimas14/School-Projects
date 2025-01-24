/**
  * @brief Assignment 4
  * @author Jacob Limas
  */

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    cout << fixed << setprecision(2);
    const double EPSILON = 1E-0;
    int month = 0;
    double balance, payment, APR, interestRate;
    cout << "Enter balance: ";
    cin >> balance;
    cout << "Enter payment: ";
    cin >> payment;
    cout << "Enter APR: ";
    cin >> APR;
    cout << "Month " << "Int.  " << " Pay   " << '\t' << "Balance" << endl;
    cout << month << '\t' << '\t' << '\t' << balance << endl;
    while (abs(balance - 0.00) > EPSILON)
    {
        for (month = 1; month <= balance; month++){
            interestRate = APR / 12 * 10;
            APR = interestRate;
            balance = balance - payment;
            balance = balance + interestRate;
            if (payment >= balance){
                cout << month << "     " << interestRate << "  " << payment << '\t' << balance << endl;
                payment = balance;
                balance = balance - payment;
            }else {
                cout << month << "     " << interestRate << "  " << payment << '\t' << balance << endl;
            }
        }
    }
    cout << month << "     " << interestRate << "  " << payment << '\t' << balance << endl;
    return 0;
}
