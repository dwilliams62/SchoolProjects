#include "NumDays.h"

//constructor that adds hours and days to the object
NumDays::NumDays(double h)
{
    hours = h;
    days = h / 8;
}

//set the amount of hours and automatically update the days
void NumDays::setHours(double h) 
{
    hours = h;
    days = h / 8;
}

//set the amount of days and automatically update the hours
void NumDays::setDays(double d)
{
    days = d;
    hours = d * 8;
}

//return the amount of hours
double NumDays::getHours() const
{
    return hours;
}

//return the amount of days
double NumDays::getDays() const
{
    return days;
}

//return the sum of the two numdays hours
NumDays NumDays::operator + (NumDays obj)
{
    double newHours = hours + obj.hours;
    NumDays newDay(newHours);
    return newDay;
}

//return the difference of the two numdays hours
NumDays NumDays::operator - (NumDays obj)
{
    double newHours = hours - obj.hours;
    NumDays newDay(newHours);
    return newDay;
}

void NumDays::operator ++ ()
{
    hours = hours + 1;
    days = hours / 8;
}

void NumDays::operator -- ()
{
    hours = hours - 1;
    days = hours / 8;
}
