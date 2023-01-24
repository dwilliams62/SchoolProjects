#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(double rad, double xx, double yy) //default constructor that accepts a double argument
{
    radius = rad;
    x = xx;
    y = yy;
}

void Circle::setRadius(double r) //accepts a double to change the radius
{
    radius = r;
}

void Circle::setCenter(double xx, double yy) //accepts two double values to change the center of the circle
{
    x = xx;
    y = yy;
}

double Circle::getRadius() const //sends the radius back
{
    return radius;
}

double Circle::getArea() const //calculates the area of the circle and returns it
{
    return radius * radius * pi;
}

double Circle::getDiameter() const //calculates the diameter of the circle and returns it
{
    return radius + radius;
}

double Circle::getCircumference() const //calculates the circumference of the circle and returns it
{
    return 2 * pi * radius;
}

double Circle::getCenterX() const //returns the current x value of the center
{
    return x;
}

double Circle::getCenterY() const //returns the current y value of the center
{
    return y;
}

bool Circle::collide(Circle circle) //checks if the inputted circle collides with the current circle
{
    double radiusSum = circle.getRadius() + radius;
    double distanceX = ((circle.getCenterX() - x) * (circle.getCenterX() - x));
    double distanceY = ((circle.getCenterY() - y) * (circle.getCenterY() - y));
    double distance = sqrt(distanceX + distanceY);

    if (distance <= radiusSum) {return true;}
    else {return false;}
}
