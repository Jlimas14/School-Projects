/**
  * @brief Assignment 5
  * @author Jacob Limas
  */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream logFile;
    logFile.open("WebLog.txt");
    cout << "Username" << "\t" << "Date" << "\t" << "\t" << "Time" << "\t" << "\t" << "Minutes" << endl;
    while(!logFile.eof()){
    string IPAddress, Username, Date, Time, Minutes;
    logFile >> IPAddress >> Username >> Date >> Time >> Minutes;
    if(Date.find("Apr") != string::npos){
        cout << Username << "\t" << Date << "\t" << Time << "\t" << Minutes << endl;
    }
    if(logFile.fail()){
        cout << "\b" << "\b" << "Done";
        break;
        }
    }
}
