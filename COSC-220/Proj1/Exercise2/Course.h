//A class used to track course details
//Proj1 Exercise 2

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course
{
    private:
        int code; //hold the course code
        string name; //hold the course name
        float array[3] = {0.0, 0.0, 0.0}; //hold three test scores
    public:
        Course(int code = 120, string name = "CSI", float testScore1 = 0.0, float testScore2 = 0.0, float testScore3 = 0.0);
        void setCode(int);
        void setName(string);
        void setTestScore(float, int);
        int getCode();
        string getName();
        float getTestScore(int);
        friend ostream &operator << (ostream &, const Course &);
};

#endif