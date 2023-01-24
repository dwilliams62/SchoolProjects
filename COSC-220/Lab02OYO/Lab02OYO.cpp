//Dylan Williams
//Created 09/06/2022
//Last Updated 09/07/2022
//A program used to practice using the bubble sort with arrays and pointers
//Lab02 On-Your-Own Problem #1

#include <iostream>
#include <cstdlib>

using namespace std;

int *duplicateArray(const int *, int);
void displayArray(const int *, int);
int *getRandomNumbers(int);
void sort(int *, int);
bool sorted(const int *, int);

int main()
{
    cout << "Input array size: ";
    int arraySize; //to keep track of array size
    cin >> arraySize; //input array size

    int* ptr = getRandomNumbers(arraySize); //fill up array with random numbers

    displayArray(ptr, arraySize); //display array
    sort(ptr, arraySize); //sort array
    displayArray(ptr, arraySize); //display array

    if (sorted(ptr, arraySize)) {cout << "The array is sorted";} //check if sorted
    else {cout << "The array is not sorted.";} //display a message depending on yes or no

    delete[] ptr; //remove array from memory
    return 0;
}

int *duplicateArray(const int* array, int maxSize) //copy the old array into a new one
{
    int* newArray;
    for (int i = 0; i < maxSize; i++)
    {
        *(newArray + i) = *(array + i);
    }
    return newArray;
}

void displayArray(const int* array, int maxSize) //displays the contents of the array
{
    for (int x = 0; x < maxSize; x++) //print the array
    {
        cout << *(array + x) << " ";
    }
    cout << endl;
}

int* getRandomNumbers(int maxSize) //fills the array with random numbers
{
    int *array = new int[maxSize]; //create a pointer reference to an array

    for (int i = 0; i < maxSize; i++) //add random numbers to array
    {
        *(array + i) = rand() % 100;
    }
   
    return array;
}

void sort(int *array, int maxSize) //sorts the array
{
    bool isSorted = false; //keep track of whether or not it is finished sorting
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < (maxSize - 1); i++)
        {
            if (*(array + i) > *(array + i + 1))
            {
                int temp = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = temp;
                isSorted = false;
            }
        }
    }
}

bool sorted(const int* array, int counter) //check if the array is sorted
{
    if (counter == 0 || counter == 1) {return 1;}
    if (*(array + counter - 1) < *(array + counter - 2)) {return 0;}
    return sorted(array, counter - 1);
}