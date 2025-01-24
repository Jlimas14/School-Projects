#include <cstring>

using namespace std;

#include "DNAStrand.h"


DNAStrand::DNAStrand(const char* startingString){
    length = 0;
    for(int i = 0; startingString[i] != '\0'; i++) {
         length++;
    }
    bases = new char [length + 1];
    for(int i = 0; i < length; i++) {
          bases[i] = startingString[i];
    }
}


DNAStrand::DNAStrand(const DNAStrand& other){
    if(this != &other){
    length = other.length;
    bases = new char [length + 1];
    for(int i = 0; i < length; i++){
        bases[i] = other.bases[i];
    }
  }
}


DNAStrand& DNAStrand::operator=(const DNAStrand& other){
    if(this != &other){
    length = other.length;
    bases = new char [length + 1];
    for(int i = 0; i <  length; i++){
    bases[i] = other.bases[i];
        }
    }
    return *this;
}


DNAStrand::~DNAStrand(){
  delete [] bases;
}


bool DNAStrand::operator==(const DNAStrand& other) const{
    int a = 0;
    if(length == other.length){
        for(int i = 0; i < length; i++) {
            if(bases[i] == other.bases[i]){
                a++;
            }
        }
    if(a == length){
        return true;
    }else{
        return false;
      }
    }
    return false;
}


char DNAStrand::operator[](int index) const{
    if(index < length && index >= 0){
        char letter = bases[index];
        return letter;
    }else{
        throw out_of_range("");
    }

}

DNAStrand DNAStrand::operator+(const DNAStrand& other) const{
    DNAStrand newDNA(length + other.length);
    for(int i = 0; i < length; i++){
        newDNA.bases[i] = bases[i];
    }
    for(int j = 0; j < other.length; j++){
       // cout << j << " " <<  length << endl; used to find error
        newDNA.bases[j + length] = other.bases[j];
    }
    return newDNA;
}


int DNAStrand::getLength() const{
    return length;
}


DNAStrand DNAStrand::getComplement() const{
    DNAStrand newDNA(length);
    newDNA.length = length;
    for(int i = 0; i < length; i++){
         switch (bases[i])
           {
           case 'A': bases[i] = 'T';
               break;
           case 'T': bases[i] = 'A';
               break;
           case 'C': bases[i] = 'G';
               break;
           case 'G': bases[i] = 'C';
               break;
           }
    newDNA.bases[i] = bases[i];
    }
    return newDNA;
}


//DNAStrand DNAStrand::substr(int start, int length) const{
//    int newLength = start + length;
//    if(newLength <= length && newLength >= 0){
//        DNAStrand newDNA(length);
//        newDNA.length = length;
//        for (int j = 0; j < length; j++){
//            for(int i = start; i  < length; i++){
//                newDNA.bases[j] = bases[i];
//            }
//        }
//        return newDNA;
//    }else{
//       throw out_of_range("");
//    }
//}


std::ostream& operator<<(std::ostream& dest, const DNAStrand& source){
    for(int i = 0; i < source.length; i++) {
    dest << source[i];
    }
    return dest;
}


DNAStrand::DNAStrand(int length){
    length += 1;
    for(int i = 0; i < length; i++) {
          bases = new char [i];
    }
}






