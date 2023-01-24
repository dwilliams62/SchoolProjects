#include "CustomerData.h"

//set the customer's number
void CustomerData::setCustomerNumber(int n)
{
    customerNumber = n;
}

//set whether or not the customer is on the mailing list
void CustomerData::setMailingList(bool m)
{
    mailingList = m;
}

void CustomerData::PrintRecord()
{
    PersonData::PrintRecord();
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On the mailing list: ";
    if (mailingList) {cout << "Yes" << endl;}
    else {cout << "No" << endl;}
}

string CustomerData::getRecord()
{
    string str = PersonData::getRecord();
    str = str + " / C#: " + to_string(customerNumber) + " / ML: ";
    if (mailingList) {str = str + "Yes";}
    else {str = str + "No";}
    return str;
}