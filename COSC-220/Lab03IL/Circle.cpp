//Dylan Williams
//Created 09/12/2022
//Last Updated 09/13/2022
//A program used to practice using classes
//Lab03 InLab #1
#include <iostream>

using namespace std;

class Circle
{
    private:
        double radius; //hold the radius in the class object
        double pi = 3.14159263589793; //set pi
    public:
        Circle(double rad);
        void setRadius(double);
        double getRadius() const;
        double getArea() const;
        double getDiameter() const;
        double getCircumference() const;
};

Circle::Circle(double rad = 0.0) //default constructor that accepts a double argument
{
    radius = rad;
}

void Circle::setRadius(double r) //accepts a double to change the radius
{
    radius = r;
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