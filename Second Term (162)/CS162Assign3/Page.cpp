#include <iostream>
#include <cstring>

using namespace std;

#include "Page.h"

Page::Page(){
    url = "";
    visits = 0;
    for(int i = 0; i < 3; i++){
        links[i] = nullptr;
    }
    usedLinks = 0;
}

Page::Page(string urlValue){
    url = urlValue;
    visits = 0;
    for(int i = 0; i < 3; i++){
        links[i] = nullptr;
    }
    usedLinks = 0;
}

string Page::getURL() const{
    return url;
}

int Page::getNumLinks() const{
    return usedLinks;
}

Page* Page::getRandomLink() const{
    int l = 0;
    for(int i = 0; i < 3; i++){
    if(links[i] != nullptr){
        l++;
        }
    }
    int i = rand() % l + 0;
    return links[i];
}

void Page::addLink(Page* other){
    for(int i = 0; i < 3; i++){
        if(links[i] == nullptr){
            links[i] = other;
            break;
        }
    }
    usedLinks++;
}

void Page::visit(){
    visits++;
}

int Page::getNumVisits() const{
    return visits;
}
