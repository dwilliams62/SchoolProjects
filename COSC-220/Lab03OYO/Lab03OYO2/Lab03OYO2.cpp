//Dylan Williams
//Created 09/12/2022
//Last Updated 09/16/2022
//A program used to practice using classes
//Lab03 InLab #2

#include <iostream>
#include "NumberArray.h" //include the class code

using namespace std;

int main()
{
    cout << "What is the size of the array? (Starting counting at 0)" << endl;
    double size; //to hold the size locally
    cin >> size;
    NumberArray numberArray(size); //create a NumberArray class objecct

    cout << "What number would you like to add to the array?" << endl;
    double num; //to hold the number locally
    cin >> num;
    cout << "And in which slot would you like to add it to in the array? (Starting counting at 1)" << endl;
    int slot; //which slot to add it to
    cin >> slot;
    numberArray.setElement(slot, num); //add number to array
    cout << "The element in slot " << slot << " is " << numberArray.getElement(slot) << endl;

    cout << "The largest element in the array is " << numberArray.getHighest() << endl;
    cout << "The smallest element in the array is " << numberArray.getLowest() << endl;
    cout << "The average of all elements in the array is " << numberArray.getAverage() << endl;
    return 0;
}
