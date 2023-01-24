//Dylan Williams
//Created 09/26/2022
//Last Updated 09/28/2022
//The first exercise in the first project of 220, includes creating a system for tracking how many days an employee 
//works and how many days of sick leave and vacation they have
//Proj1 Exercise1

#include <iostream>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

int main()
{
    double input;
    cout << "Enter how many hours the employee has worked: " << endl;
    cin >> input;
    NumDays employeeDays(input); //create a numdays object to hold the number of hours
    string nameInput;
    cout << "What is the employee's name?" << endl;
    cin >> nameInput;
    cout << "What is the employee's ID number?" << endl;
    cin >> input;
    TimeOff employeeTimeOff(nameInput, input); //create a timeoff object with the employee name and id
    cout << "How many months has the employee worked?" << endl;
    cin >> input;
    employeeTimeOff.setMaxSickDays(input); //input the number of months into the relevant functions of timeoff
    employeeTimeOff.setMaxVacation(input);
    employeeTimeOff.setMaxUnpaid(input);
    cout << employeeTimeOff.getEmployeeName() << " can take a maximum of " << employeeTimeOff.getMaxSickDays() << " sick hours." << endl;
    cout << employeeTimeOff.getEmployeeName() <<  " can take a maximum of " << employeeTimeOff.getMaxVacation() << " vacation hours." << endl;
    return 0;
}