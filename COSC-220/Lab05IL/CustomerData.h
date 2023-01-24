//A class used to track a customer's data
//Lab05 IL

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <iostream>
#include "PersonData.h"

using namespace std;

class CustomerData: public PersonData
{
    private:
        int customerNumber = 0; //hold the customer number
        bool mailingList; //hold whether or not they are in the mailing list
    public:
        void setCustomerNumber(int);
        void setMailingList(bool);
        virtual void PrintRecord();
        virtual string getRecord();
};

#endif