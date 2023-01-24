//A class used to track student details
//Proj1 Exercise 2

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Course.h"

using namespace std;

class Student
{
    private:
        int id; //hold the student ID
        string name; //hold the student name
        Course* ptr; //hold the student's courses
        int courseCount = 0; //keep track of how many courses the student is taking
    public:
        Student(int, string);
        Student(const Student &obj);
        void setID(int);
        void setName(string);
        int getID();
        string getName();
        void AddCourse(Course);
        void DeleteCourse(Course);
        Course* getCourses();
        void operator=(const Student &right);
        friend ostream &operator << (ostream &, const Student &);
};

#endif