/**
  * @brief Assignment 9
  * @author Jacob Limas
  */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct playStore{
    string app;
    string category;
    double rating;
    int reviews;
    double installs;
    string type;
    string contentRating;
};

void printData(const playStore company[], int recordNumber){
    cout << fixed;
    cout << company[recordNumber].app << " (" << company[recordNumber].category << ")" << endl;
    cout << setprecision(1) << "Star Rating: " << company[recordNumber].rating << " (Reviews: " << company[recordNumber].reviews << ")" << endl;
    cout << setprecision(6) << "Amount of installs: " << company[recordNumber].installs << " (" << company[recordNumber].type << ")" << endl;
    cout << "Content Rating: " << company[recordNumber].contentRating << endl;
    cout << endl;
}

void readData (playStore company[]){
  ifstream inFile("googleplaystoreUpdated.csv");
  inFile.close ();
  inFile.open ("googleplaystoreUpdated.csv");
  for (int record = 0; record < 100; record++)
    {
      string part1, part2, part3, part4, part5, part6, part7, part8, part9;
      getline (inFile, part1, ',');
      getline (inFile, part2, ',');
      getline (inFile, part3, ',');
      getline (inFile, part4, ',');
      getline (inFile, part5, ',');
      getline (inFile, part6, ',');
      getline (inFile, part7, ',');
      getline (inFile, part8, ',');
      getline (inFile, part9);
      company[record].app = part1;
      company[record].category = part2;
      company[record].rating = stod (part3);
      company[record].reviews = stoi (part4);
      company[record].installs = stod (part5);
      company[record].type = part6;
      company[record].contentRating = (part7);
      printData(company, record);
    }
}

void getRecord(const playStore company[], int recordNumber){
    cout << "Outputting record " << recordNumber << ":" << endl;
    recordNumber -= 1;
    printData(company, recordNumber);
}

void specificRanking(const playStore company[], double rating){
    cout << "All apps above " << setprecision(1) << rating << ": " << endl;
    for(int rank = 0; rank < 100; rank++){
         if(company[rank].rating >= rating){
            cout << company[rank].app << endl;
        }
    }
    cout << endl;
}

void highestRanking(const playStore company[]){
    cout << "The highest ranked app in ART_AND_DESIGN: " << endl;
    double best = 0.0;
    int bestRank = 0;
    for(int rank = 0; rank < 100; rank++){
       if(company[rank].category == "ART_AND_DESIGN"){
         if(company[rank].rating > best){
            best = company[rank].rating;
            bestRank = rank;
        }
    }
}
    printData(company, bestRank);
}

void lowestRanking(const playStore company[]){
    cout << "The lowest ranked app in ART_AND_DESIGN: " << endl;
    double worst = 5.0;
    int worstRank = 0;
    for(int rank = 0; rank < 100; rank++){
       if(company[rank].category == "ART_AND_DESIGN"){
         if(company[rank].rating < worst){
            worst = company[rank].rating;
            worstRank = rank;
        }
    }
}
    printData(company, worstRank);
}

void averageRatings(const playStore company[]){
    cout << "The average rating for all ART_AND_DESIGN apps is: " << endl;
    double ratings = 0.0;
    int average = 0;
    for(int amount = 0; amount < 100; amount++){
       if(company[amount].category == "ART_AND_DESIGN"){
            ratings += company[amount].rating;
            average++;
        }
    }
    ratings /= average;
    cout << setprecision(2) << ratings << endl;
}

int main(){
    ifstream inFile("googleplaystoreUpdated.csv");
    if(inFile.fail()) {
        cout << "File open error!";
        exit(0);
    }
    playStore company[100];
    readData(company);
    int recordNumber = 20;
    getRecord(company, recordNumber);
    recordNumber = 80;
    getRecord(company, recordNumber);
    specificRanking(company, 4.7);
    highestRanking(company);
    lowestRanking(company);
    averageRatings(company);
}


