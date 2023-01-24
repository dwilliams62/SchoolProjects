#include "Course.h"

//constructor
Course::Course(int c, string n, float testScore1, float testScore2, float testScore3)
{
    code = c;
    name = n;
    array[0] = testScore1;
    array[1] = testScore2;
    array[2] = testScore3;
}

//set the course code, unless the inputted number is greater than 3 digits
void Course::setCode(int n)
{
    if (n > 999) {cout << "The course code is too big!" << endl;}
    if (n < 999) {code = n;}
}

//set the name of the course
void Course::setName(string s)
{
    name = s;
}

//set the test score in a specific spot in the array
void Course::setTestScore(float ts, int n)
{
    array[n - 1] = ts;
}

//return the current course code
int Course::getCode()
{
    return code;
}

//return the current course name
string Course::getName()
{
    return name;
}

//return the test score at a specific spot in the array
float Course::getTestScore(int n)
{
    return array[n-1];
}

// Friend functions for streaming.
ostream &operator << (ostream &out, const Course &c)
{
    out << c.name << " " << c.code << " ";
    return out;
}