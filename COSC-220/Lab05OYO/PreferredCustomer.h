//A class used to track a customer's data
//Lab05 OYO

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include <iostream>
#include "CustomerData.h"

using namespace std;

class PreferredCustomer: public CustomerData
{
    private:
        double purchaseAmout = 0; //the amount the customer has spent
        double discoutLevel = 0; //the level of discount the customer has
    public:
        void setPurchaseAmount(double);
        virtual void PrintRecord();
        virtual string getRecord();
};

#endif