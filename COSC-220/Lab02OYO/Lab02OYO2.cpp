//Dylan Williams
//Created 09/07/2022
//Last Updated 09/07/2022
//A program used to practice using pointers and arrays
//Lab02 On-Your-Own Problem #2

#include <iostream>

using namespace std;

void displayArray(const int *, int);
int* ConcatenateArray(int*, int*, int, int);
int* ReverseArray(int*, int);
int* ArrayExpander(int*, int);
int* ElementShiftRight(int*, int);
int* ElementShiftLeft(int*, int);
int *getRandomNumbers(int);

int main()
{
    cout << "Input array size: ";
    int arraySize; //to keep track of array size
    cin >> arraySize; //input array size

    int* ptr = getRandomNumbers(arraySize); //fill up array with random numbers
    cout << "The original array: ";
    displayArray(ptr, arraySize); //display array

    int* arrayExpand = ArrayExpander(ptr, arraySize); //expand the array
    cout << "The array expanded: ";
    displayArray(arrayExpand, arraySize * 2); //display array

    int* shiftRightArray = ElementShiftRight(ptr, arraySize); //shift array right
    cout << "The array shifted right: ";
    displayArray(shiftRightArray, arraySize); //display array

    int* shiftLeftArray = ElementShiftLeft(ptr, arraySize); //shift left
    shiftLeftArray = ElementShiftLeft(shiftLeftArray, arraySize); //shift left twice to show change
    cout << "The array shifted left: ";
    displayArray(shiftLeftArray, arraySize); //display array
    ptr = ElementShiftRight(ptr, arraySize); //put array back

    int* ptr2 = getRandomNumbers(arraySize); //make another array to add
    int* connectedArray = ConcatenateArray(ptr, ptr2, arraySize, arraySize); //add them together
    cout << "The array connected to another array: "; 
    displayArray(connectedArray, arraySize * 2); //display array

    int* reverseArray = ReverseArray(ptr, arraySize); //reverse array
    cout << "The array reversed: ";
    displayArray(reverseArray, arraySize); //display array

    delete[] ptr; //delete and remove everything
    ptr = nullptr;
    delete[] ptr2;
    ptr2 = nullptr;
    delete[] arrayExpand;
    arrayExpand = nullptr;
    delete[] shiftLeftArray;
    shiftLeftArray = nullptr;
    delete[] shiftRightArray;
    shiftRightArray = nullptr;
    delete[] connectedArray;
    connectedArray = nullptr;
    delete[] reverseArray;
    reverseArray = nullptr;
    return 0;
}

void displayArray(const int* array, int maxSize) //displays the contents of the array
{
    for (int x = 0; x < maxSize; x++) //print the array
    {
        cout << *(array + x) << " ";
    }
    cout << endl;
}

int* ConcatenateArray(int* arr1, int* arr2, int arr1Len, int arr2Len) //adds two arrays together
{
    int newLen = (arr1Len + arr2Len); //calculate new max size
    int* newArray = new int[newLen]; //make new array
    for (int i = 0; i < arr1Len; i++) //add the first array
    {
        *(newArray + i) = *(arr1 + i);
    }
    for (int i = arr1Len; i < newLen; i++) //add the second array
    {
        *(newArray + i) = *(arr2 + i - arr1Len);
    }
    return newArray;
}

int* ReverseArray(int* arr, int len)
{
    int* newArray = new int[len]; //make new array
    int count = 0; //used to keep track of where numbers are being added to new array
    for (int i = len - 1; i > -1; i--) //add numbers in reverse order from old array to new array
    {
        *(newArray + i) = *(arr + count);
        count++;
    }
    return newArray;
}

int* ArrayExpander(int* arr, int len) //expand the array to fit more variables
{
    int newLen = len * 2; //calculate new length
    int* newArray = new int[newLen]; //make new array to fill with values of old one
    for (int i = 0; i < newLen; i++) //initalize all values as 0
    {
        *(newArray + i) = 0;
    }
    for (int i = 0; i < len; i++) //put old array in new one
    {
        *(newArray + i) = *(arr + i);
    }
    return newArray;
}

int* ElementShiftRight(int* arr, int len) //shift elements right
{
    int temp = *(arr + len - 1); //hold on to the last element
    for (int i = len; i > 0; i--) //shift all elements right
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr) = temp; //put previous last element in first slot
    return arr;
}

int* ElementShiftLeft(int* arr, int len) //shift elements left
{
    int temp = *(arr); //hold the first element
    for (int i = 0; i < len - 1; i++) //shift elements left
    {
        *(arr + i) = *(arr + i + 1);
    }
    *(arr + len - 1) = temp; //put previous first element as last element
    return arr;
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