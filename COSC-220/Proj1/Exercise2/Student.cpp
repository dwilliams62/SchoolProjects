#include "Student.h"

//constructor
Student::Student(int i, string n)
{
    id = i;
    name = n;
}

//copy constructor accepting another student object
Student::Student(const Student &obj)
{
    id = obj.id;
    name = obj.name;
    courseCount = obj.courseCount;
    ptr = new Course[obj.courseCount];
    for (int i = 0; i < obj.courseCount; i++)
    {
        ptr[i] = obj.ptr[i];
    }
}

//set the student ID
void Student::setID(int i)
{
    id = i;
}

//set the student name
void Student::setName(string n)
{
    name = n;
}

//return the student ID
int Student::getID()
{
    return id;
}

//return the student name
string Student::getName()
{
    return name;
}

//Add a course to the pointer of course objects
void Student::AddCourse(Course c)
{
    int newSize = courseCount + 1;
    Course* newPtr = new Course[newSize];
    for (int i = 0; i < courseCount; i++)
    {
        newPtr[i] = ptr[i];
    }
    newPtr[courseCount] = c;
    courseCount = newSize;
    ptr = newPtr;
}

//Remove a course from the pointer of course objects
void Student::DeleteCourse(Course c)
{
    int found = 0;
    for (int i = 0; i < courseCount; i++)
    {
        if (ptr[i].getCode() == c.getCode())
        {
            found = i;
            break;
        }
    }

    for (int n = found; n < courseCount; n++)
    {
        ptr[n].setCode(ptr[n + 1].getCode());
        ptr[n].setName(ptr[n + 1].getName());
    }

    int newSize = courseCount - 1;
    Course* newPtr = new Course[newSize];
    for (int i = 0; i < newSize; i++)
    {
        newPtr[i] = ptr[i];
    }
    courseCount = newSize;
    ptr = newPtr;
}

//return the list of courses
Course* Student::getCourses()
{
    return ptr;
}

//overload the = operator to set the student name, ID, and courseload
void Student::operator=(const Student &right)
{
    id = right.id;
    name = right.name;
    courseCount = right.courseCount;
    ptr = new Course[right.courseCount];
    for (int i = 0; i < courseCount; i++)
    {
        ptr[i].setCode(right.ptr[i].getCode());
        ptr[i].setName(right.ptr[i].getName());
    }
}

// Friend functions for streaming.
ostream &operator << (ostream &out, const Student &c)
{
    out << "Name: " << c.name << " ID: " << c.id << endl;
    out << "This student is taking ";
    for (int i = 0; i < c.courseCount; i++)
    {
        out << c.ptr[i] << " ";
    }
    out << endl;
    return out;
}