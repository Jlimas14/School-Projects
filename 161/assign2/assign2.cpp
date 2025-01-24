/**
  * @brief Assigment 2
  * @author Jacob Limas
  */

#include <iostream>

using namespace std;

int main()
{
    double GPA;
    int SAT;
    cout << "Enter GPA: ";
    cin >> GPA;
    if (GPA > 3.99){
        cout << "Admit" << endl;
        //Added another if statement in an if statement
    }else if (GPA < 4 && GPA > 3.49){
        cout << "Enter SAT: ";
        cin >> SAT;
        if (SAT > 1400){
            cout << "Admit" << endl;
        }else if (SAT < 1401 && SAT > 1099){
            cout << "Waitlist" << endl;
        }else
            cout << "Deny" << endl;
    }else if (GPA < 3.5 && GPA > 2.9){
        cout << "Enter SAT: ";
        cin >> SAT;
        if (SAT > 2000){
            cout << "Admit" << endl;
        }else if (SAT < 2001 && SAT > 1499){
            cout << "Waitlist" << endl;
        }else
            cout << "Deny" << endl;
    }else if (GPA < 3.0 ){
        cout << "Enter SAT: ";
        cin >> SAT;
        if (SAT > 2199){
            cout << "Admit" << endl;
        }else
            cout << "Deny" << endl;
    }else{
        cout << "Error" << endl;
    }
}
