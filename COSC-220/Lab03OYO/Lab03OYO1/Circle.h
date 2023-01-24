//Dylan Williams
//Created 09/12/2022
//Last Updated 09/13/2022
//A program used to practice using classes
//Lab03 InLab #1
#include <iostream>

#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

class Circle
{
    private:
        double radius; //hold the radius in the class object
        double x; //holds the x value of the center
        double y; //holds the y value of the center
        double pi = 3.14159263589793; //set pi
    public:
        Circle(double rad = 0.0, double xx = 0.0, double yy = 0.0);
        void setRadius(double);
        void setCenter(double, double);
        double getRadius() const;
        double getArea() const;
        double getDiameter() const;
        double getCircumference() const;
        double getCenterX() const;
        double getCenterY() const;
        bool collide(Circle);
};

#endif
