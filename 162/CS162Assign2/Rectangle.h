#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

/**
 * @brief The Rectangle class represents a rectangle on a Cartesian plane
 */
class Rectangle
{
public:

    /**
     * @brief Rectangle constructs a rectangle at 0, 0 with a width and height set to 0
     */
    Rectangle();

    /**
     * @brief Rectangle constructs a rectangle based on given coordinates and values
     * @param p1 sets the first point in rectangle
     * @param heightValue sets the height to given value
     * @param widthValue sets the width to given value
     */
    Rectangle(Point p1, double heightValue, double widthValue);

    /**
     * @brief getUpperLeftVertex Accesses the coordinate set to upperLeftVertex
     * @return upper-left coordinate
     */
    Point getUpperLeftVertex() const;

    /**
     * @brief getWidth Accesses the width of the rectangle
     * @return length of the width
     */
    double getWidth() const;

    /**
     * @brief getHeight Accesses the height of the rectangle
     * @return length of the height
     */
    double getHeight() const;

    /**
     * @brief getArea Calculates area of rectangle based on height and width
     * @return the area of the rectangle
     */
    double getArea() const;

    /**
     * @brief getPerimeter Caluclates perimeter of rectangle based on height and width
     * @return the perimeter of the rectangle
     */
    double getPerimeter() const;

    /**
     * @brief getCenter Calculates x and y coordinate and make a point called center
     * @return the coordinates of center
     */
    Point getCenter() const;

    /**
     * @brief translate Moves the rectangle to the given coordinates
     * @param x adds to height and moves the x-coordinate
     * @param y adds to width and moves the y-coordinate
     */
    void translate(double x, double y);

    /**
     * @brief contains Checks if a point is represented in the rectangle
     * @param p Point used compare the inside of rectangle
     * @return True if coordinates are within the rectangle. Else false.
     */
    bool contains(Point p) const;



private:
    Point upperLeftVertex;
    double height;
    double width;

};

#endif // RECTANGLE_H
