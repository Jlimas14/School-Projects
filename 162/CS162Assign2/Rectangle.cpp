#include <iostream>
#include <cmath>
using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle(){
    Point(0,0);
    height = 0;
    width = 0;
}

Rectangle::Rectangle(Point p1, double heightValue, double widthValue){
    upperLeftVertex = p1;
    height = heightValue;
    width = widthValue;
}

Point Rectangle::getUpperLeftVertex() const{
    return upperLeftVertex;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getHeight() const{
    return height;
}

double Rectangle::getArea() const{
    double area = 0;
    area = width * height;
    return area;
}

double Rectangle::getPerimeter() const{
    double perimeter = 0;
    perimeter = 2 * (width + height);
    return perimeter;
}

Point Rectangle::getCenter() const{
    double x = (upperLeftVertex.getX() + height) / 2;
    double y = (upperLeftVertex.getY() + width) / 2;
    Point center(x,y);
    return center;
}

void Rectangle::translate(double x, double y){
   height += x;
   width += y;
}

bool Rectangle::contains(Point p) const{
   Point lowerRightVertex(height + upperLeftVertex.getX(), width + upperLeftVertex.getY());
   if(p.getX() >= upperLeftVertex.getX() && p.getX() <= lowerRightVertex.getX()){
       if(p.getY() >= upperLeftVertex.getY() && p.getY() <= lowerRightVertex.getY()){
        return true;
       }
   }
   else{
       return false;
   }
}
