/**
  * @brief Assigment 1 Problem 2
  * @author Jacob Limas
  */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double voltage;
    double resistance;
    double watts;
    cout << "Enter the voltage: ";
    cin >> voltage;
    cout << "Enter the resistance: ";
    cin >> resistance;
    cout << endl;
    watts = voltage * voltage / resistance;
    cout << "The component consumes " << watts << " watts" << endl;
}
