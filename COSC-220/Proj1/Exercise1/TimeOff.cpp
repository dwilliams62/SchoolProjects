#include "TimeOff.h"

//constructor that requires a name and employee ID
TimeOff::TimeOff(string name, double ID)
{
    employeeName = name;
    employeeID = ID;
}

//accepts a string to change the employee name
void TimeOff::setEmployeeName(string name)
{
    employeeName = name;
}

//accepts a double to change the employee ID
void TimeOff::setEmployeeID(double ID)
{
    employeeID = ID;
}

//calculate the max amount of sick hours a person has using the amout of months they've worked
void TimeOff::setMaxSickDays(double months)
{
    maxSickDays = months * 8;
}

//set the amount of sick leave already taken
void TimeOff::setSickTaken(double num)
{
    sickTaken = num;
}

//calculate the max amount of vacation hours a person can use
void TimeOff::setMaxVacation(double months)
{
    maxVacation = months * 12;
    if (maxVacation > 240) {maxVacation = 240;}
}

//set the amount of the vacation hours taken
void TimeOff::setVacTaken(double num)
{
    vacTaken = num;
}

//set the max amount of unpaid 
void TimeOff::setMaxUnpaid(double num)
{
    maxUnpaid = num * 3;
}

//set the amount of unpaid time already taken
void TimeOff::setUnpaidTime(double num)
{
    unpaidTaken = num;
}

//return the employee name
string TimeOff::getEmployeeName()
{
    return employeeName;
}

//return the employee ID
double TimeOff::getEmployeeID()
{
    return employeeID;
}

//return the maximum amount of sick hours the employee can have
double TimeOff::getMaxSickDays()
{
    return maxSickDays;
}

//return the amout of sick hours taken
double TimeOff::getSickTaken()
{
    return sickTaken;
}

//return the max amount of vacation hours an employee can have
double TimeOff::getMaxVacation() const
{
    return maxVacation;
}

//return the amount of vacation an employee has taken
double TimeOff::getVacTaken()
{
    return vacTaken;
}

//return the max amount of unpaid time the employee can have
double TimeOff::getMaxUnpaid()
{
    return maxUnpaid;
}

//return how much unpaid time off an employee can have
double TimeOff::getUnpaidTime()
{
    return unpaidTaken;
}