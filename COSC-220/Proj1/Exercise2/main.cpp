//Dylan Williams
//Created 09/28/2022
//Last Updated 09/28/2022
//The second exercise in the first project of 220, this program is used to keep track of a student and their classes
//and various information about them
//Proj1 Exercise2

#include <iostream>
#include "Course.h"
#include "Student.h"

using namespace std;

int main()
{
    int studentID;
    string studentName;
    cout << "What is the student's name?" << endl;
    cin >> studentName;
    cout << "What is the student's ID?" << endl;
    cin >> studentID;
    Student student1(studentID, studentName);
    Course course1;
    Course course2(210, "MATH");
    Course course3(250, "COSC");
    student1.AddCourse(course1);
    student1.AddCourse(course2);
    student1.AddCourse(course3);
    cout << student1 << endl;

    Student student2(student1);
    student2.setName("Herald");
    student2.setID(18248);
    student2.DeleteCourse(course2);
    cout << student2 << endl;
    
    Student student3(5, "h");
    student3 = student1;
    cout << student3 << endl;

    return 0;
}