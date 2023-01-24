#include "PreferredCustomer.h"

void PreferredCustomer::setPurchaseAmount(double n)
{
    if (n > 0)
    {
        purchaseAmout = n;
        if (purchaseAmout >= 500) {discoutLevel = 5;}
        if (purchaseAmout >= 1000) {discoutLevel = 6;}
        if (purchaseAmout >= 1500) {discoutLevel = 7;}
        if (purchaseAmout >= 2000) {discoutLevel = 10;}
    }
    else {cout << "The sales number cannot be negative!";}
}

void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord();
    cout << "Amount Purchased: " << purchaseAmout << endl;
    cout << "Discount Level: " << discoutLevel << "%" << endl;
}

string PreferredCustomer::getRecord()
{
    string str = CustomerData::getRecord();
    str = str + " / Account: " + to_string(purchaseAmout);
    str = str + " / Discount: " + to_string(discoutLevel) + "%";
    return str;
}