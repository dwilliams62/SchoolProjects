//A class used to track how many days a worker has taken sick leave and how many vacation days they have
//Proj1 Exercise1

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <iostream>

using namespace std;

class TimeOff
{
    private:
        string employeeName = " "; //hold the employee name
        double employeeID = 0; //hold the employee ID
        double maxSickDays = 0; //hold the max amount of sick days
        double sickTaken = 0; //hold the amount of sick days an employee has taken
        double maxVacation = 0; //hold the max amount of vacation days
        double vacTaken = 0; //hold the amount of vacation days an employee has taken
        double maxUnpaid = 0; //hold the max amount of unpaid days an employee can take
        double unpaidTaken = 0; //hold the amount of unapid time off an employee has taken
    public:
        TimeOff(string name, double ID);
        void setEmployeeName(string);
        void setEmployeeID(double);
        void setMaxSickDays(double);
        void setSickTaken(double);
        void setMaxVacation(double);
        void setVacTaken(double);
        void setMaxUnpaid(double);
        void setUnpaidTime(double);
        string getEmployeeName();
        double getEmployeeID();
        double getMaxSickDays();
        double getSickTaken();
        double getMaxVacation() const;
        double getVacTaken();
        double getMaxUnpaid();
        double getUnpaidTime();
};

#endif