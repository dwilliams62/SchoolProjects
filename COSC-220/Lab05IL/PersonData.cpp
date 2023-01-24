#include "PersonData.h"

//set the first and last name
void PersonData::setName(string fN, string lN)
{
    firstName = fN;
    lastName = lN;
}

//set the address lines
void PersonData::setAddress(string add, string c, string s, string z)
{
    address = add;
    city = c;
    state = s;
    zip = z;
}

//set the phone number
void PersonData::setPhone(string p)
{
    phoneNumber = p;
}

void PersonData::PrintRecord()
{
    cout << firstName << ", " << lastName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phoneNumber << endl;
}

string PersonData::getRecord()
{
    string str = firstName + ", " + lastName;
    str = str + " / " + address + " / ";
    str = str + city + ", " + state + " " + zip;
    str = str + " / " + phoneNumber;
    return str;
}
