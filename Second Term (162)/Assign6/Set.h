#ifndef SET_H
#define SET_H

#include <iostream>

template <typename T>
class Set{
public:

   Set(){
       list = new T[size];
   }

   bool contains(T item) const{
       for(int i = 0; i < currentAmount; i++){
           if(list[i] == item){
               return true;
           }
        }

       return false;
   }

   void add(T item){
        if(contains(item) == false){
            if(currentAmount >= size){
                grow();
            }
            list[currentAmount] = item;
            currentAmount++;
        }
   }

   int getSize() const{
       return size;
   }

   void grow(){
       T* oldSize = list;
       size++;
       list = new T[size];
       for(int i = 0; i < currentAmount; i++){
           list[i] = oldSize[i];
       }
       delete [] oldSize;
   }

   Set(const Set& other){
       if(this != &other){
           currentAmount = other.currentAmount;
           size = other.size;
           list = new T [size];
           for(int i = 0; i < currentAmount; i++){
               list[i] = other.list[i];
           }
       }
   }

   Set operator=(const Set& other){
       if(this != &other){
           currentAmount = other.currentAmount;
           size = other.size;
           list = new T [size];
           for(int i = 0; i < currentAmount; i++){
               list[i] = other.list[i];
           }
       }
       return *this;
   }

   ~Set(){
    delete [] list;
   }

   void remove(T item){
        if(contains(item) == true){
            for(int i = 0; i < size; i++){
              if(list[i] == item){
                  for(int j = 0; j < size; j++){
                      list[i] = list[i + 1];
                      i++;
                  }
                 currentAmount--;
                 size--;
               }
            }
        }
   }

    void clear(){
        currentAmount = 0;
        size = 0;
    }

// T removeSmallest(){
//    for(int i = 0; i < size; i++){
//        if(list[i] <= list[i + 1]){
//            T smallest = list[i];
//            if (smallest < list[i]){
//                   smallest = list[i];
//                 }
//            for(int j = 0; j < size; j++){
//                list[i] = list[i + 1];
//                i++;
//            }
//         remove(smallest);
//         }
//    }
// }

// bool operator==(const Set<T>& other) const{
//        int n = 0;
//        if(size == other.size){
//            for(int i = 0; i < size; i++) {
//                if(list[i] != other.list[i]){
//                    contains(i);
//                }
//            }
//        if(n == size){
//            return true;
//        }else{
//            return false;
//          }
//        }
//        return false;
//    }

// string toString() const{}

// Set<type> intersectionWith(const Set<type>& other) const{}

private:
    T* list = nullptr;
    int currentAmount = 0;
    int size = 0;

};



#endif // SET_H
