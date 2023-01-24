//Dylan Williams
//Created 10/5/2022
//Last Updated 10/5/2022
//Designed to achieve practice with mutators and inheritence and a user
//driven menu
//Lab05 On-Your-Own 

#include <iostream>

#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

void PrintMenu();
void PrintPersonalDataInput();
void PrintCustomerDataInput();
void PrintPreferredCustomerDataInput();

int mInput = 0, dataBaseSize = 0, cNumberInput;
string fNameInput, lNameInput, addInput, zipInput, cityInput, stateInput, phoneInput, mailInput;
double pAmountInput;
PersonData *people[10];

int main() 
{
    while (mInput != 6)
    {
        PrintMenu();
        cin >> mInput;

        //Add Personal Data Object
        if (mInput == 1)
        {
            PrintPersonalDataInput();
            people[dataBaseSize] = new PersonData;
            people[dataBaseSize]->setName(fNameInput, lNameInput);
            people[dataBaseSize]->setAddress(addInput, cityInput, stateInput, zipInput);
            people[dataBaseSize]->setPhone(phoneInput);
            dataBaseSize ++;
        }

        //Add Customer Data Object
        if (mInput == 2)
        {
            PrintPersonalDataInput();
            PrintCustomerDataInput();
            CustomerData *customer = new CustomerData;
            customer->setName(fNameInput, lNameInput);
            customer->setAddress(addInput, cityInput, stateInput, zipInput);
            customer->setPhone(phoneInput);
            customer->setCustomerNumber(cNumberInput);
            if (mailInput == "Y") {customer->setMailingList(true);}
            people[dataBaseSize] = customer;
            dataBaseSize ++;
        }

        //Add preferred customer data object
        if (mInput == 3)
        {
            PrintPersonalDataInput();
            PrintCustomerDataInput();
            PrintPreferredCustomerDataInput();
            PreferredCustomer *customer = new PreferredCustomer;
            customer->setName(fNameInput, lNameInput);
            customer->setAddress(addInput, cityInput, stateInput, zipInput);
            customer->setPhone(phoneInput);
            customer->setCustomerNumber(cNumberInput);
            if (mailInput == "Y") {customer->setMailingList(true);}
            customer->setPurchaseAmount(pAmountInput);
            people[dataBaseSize] = customer;
            dataBaseSize ++;
        }

        //View database long form
        if (mInput == 4)
        {
            for (int i = 0; i < dataBaseSize; i++)
            {
                people[i]->PrintRecord();
                cout << endl;
            }
        }

        //View database short
        if (mInput == 5)
        {
            for (int i = 0; i < dataBaseSize; i++)
            {
                string str = people[i]->getRecord();
                cout << str;
                cout << endl;
            }
        }

        //Quit the program
        if (mInput == 6)
        {
            break;
        }
    }

    return 0;
}

void PrintMenu()
{
    cout << endl;
    cout << "1. Add Personal Data Object" << endl;
    cout << "2. Add Customer Data Object" << endl;
    cout << "3. Add Preferred Customer Data Object" << endl;
    cout << "4. View Database Long Form" << endl;
    cout << "5. View Database Short Form" << endl;
    cout << "6. Quit" << endl;
    cout << "Choice: ";
}

void PrintPersonalDataInput()
{
    cout << "Enter first name: ";
    cin >> fNameInput;
    cout << "Enter last name: ";
    cin >> lNameInput;
    cout << "Enter Address: ";
    cin >> addInput;
    cout << "Enter City: ";
    cin >> cityInput;
    cout << "Enter State: ";
    cin >> stateInput;
    cout << "Enter ZIP: ";
    cin >> zipInput;
    cout << "Enter Phone Number: ";
    cin >> phoneInput;
}

void PrintCustomerDataInput()
{
    cout << "Enter customer number: ";
    cin >> cNumberInput;
    cout << "Does this customer wish to be on the mailing list? (Y/N): ";
    cin >> mailInput;
}

void PrintPreferredCustomerDataInput()
{
    cout << "Enter the amount the customer has spent: ";
    cin >> pAmountInput;
}