//A class used to track a customer's data
//Lab05 OYO

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <iostream>
#include "PersonData.h"

using namespace std;

class CustomerData: public PersonData
{
    public:
        int customerNumber = 0; //hold the customer number
        bool mailingList; //hold whether or not they are in the mailing list
        void setCustomerNumber(int);
        void setMailingList(bool);
        virtual void PrintRecord();
        virtual string getRecord();
};

#endif