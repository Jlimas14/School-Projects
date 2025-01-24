#include <iostream>
#include <cstring>
using namespace std;

#include "Page.h"

int main()
{
    Page p1("http://page1");
    Page p2("http://page2");
    Page p3("http://page3");
    Page p4("http://page4");
    p1.addLink(&p2);
    p1.addLink(&p3);
    p2.addLink(&p3);
    p3.addLink(&p1);
    p4.addLink(&p1);
    p4.addLink(&p3);
    for(int i = 0; i < 10000; i++){
        int n = rand() % 100 + 1;
        if(n < 15){
            int r = rand() % 100 + 1;
            if(r <= 25){
                p1.visit();
            }else if(r <= 50){
                p2.visit();
            }else if(r <= 75){
                p3.visit();
            }else if(r <= 100){
                p4.visit();
            }
        }
    }
    cout << p1.getURL() << " " << p1.getNumVisits() << endl;
    cout << p2.getURL() << " " << p2.getNumVisits() << endl;
    cout << p3.getURL() << " " << p3.getNumVisits() << endl;
    cout << p4.getURL() << " " << p4.getNumVisits() << endl;

}
