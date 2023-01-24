//A class used to track a person's information
//Lab05 OYO

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
//#include "Course.h"

using namespace std;

class PersonData
{
    public:
        string firstName = " "; //hold the first name
        string lastName = " "; //hold the last name
        string address = " "; //hold the address
        string city = " "; //hold the city
        string state = " "; //hold the state
        string zip = " "; //hold the zip address
        string phoneNumber = " "; //hold the phone number of the person
        void setName(string, string);
        void setAddress(string, string, string, string);
        void setPhone(string);
        virtual void PrintRecord();
        virtual string getRecord();
};

#endif