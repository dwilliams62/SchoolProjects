//A class used to track how many days a worker has worked, in 8 hour increments
//Proj1 Exercise 1

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>

using namespace std;

class NumDays
{
    private:
        double hours; //hold the amount of hours
        double days; //hold the amount of days
    public:
        NumDays(double hours = 0.0);
        void setHours(double);
        void setDays(double);
        double getHours() const;
        double getDays() const;
        NumDays operator + (NumDays);
        NumDays operator - (NumDays);
        void operator ++ ();
        void operator -- ();
};

#endif