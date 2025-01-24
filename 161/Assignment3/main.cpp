#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, A, B, C, B2, C2, Pi;
    Pi = 3.14159;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter A: ";
    cin >> A;
    double sinA = sin(A);
    double bsinA = b * sinA;
    bsinA = bsinA * (Pi / 180);
    if (a < bsinA){
        cout << "No solution" << endl;
    }else if (a == bsinA){
                B =  (b * sin(A)) / a;
                C = 180 - (B + A);
                cout << "Angle B = " << round(B) << " degrees" << endl;
                cout << "Angle C = " << round(C) << " degrees" << endl;
    }else if (b > a && a > bsinA){
                B =  (b * sin(A)) / a;
                C = 180 - (B + A);
                B2 = 180 - B;
                C2 = 180 - (B + A);
                cout << "Angle B = " << round(B) << " degrees" << endl;
                cout << "Angle C = " << round(C) << " degrees" << endl;
                cout << " OR " << endl;
                cout << "Angle B = " << round(B2) << " degrees" << endl;
                cout << "Angle C = " << round(C2) << " degrees" << endl;
                //reverse all if statements except error
    }else{
                cout << "error" << endl;
    }
}
