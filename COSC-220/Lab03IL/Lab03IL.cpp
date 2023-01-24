//Dylan Williams
//Created 09/12/2022
//Last Updated 09/13/2022
//A program used to practice using classes
//Lab03 InLab #1

#include "Circle.cpp" //include the class code
#include <iostream>

using namespace std;

int main()
{
    cout << "What is the radius of the circle?" << endl;
    double radius; //to hold the radius locally
    cin >> radius;

    Circle circle(radius); //create a circle class objecct
    cout << "The circle's area is: " << circle.getArea() << endl;
    cout << "The circle's diameter is: " << circle.getDiameter() << endl;
    cout << "The circle's circumference is: " << circle.getCircumference() << endl;
    return 0;
}