//Dylan Williams
//Created 09/16/2022
//Last Updated 09/16/2022
//A program used to practice using classes
//Lab03 InLab #2

#include <iostream>
#include "NumberArray.h"

//default constructor
NumberArray::NumberArray(int num = 1)
{
    array = new double[num];
    size = num;

    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}


//set an element in the array to a new number
void NumberArray::setElement(int num, double element)
{
    array[num] = element;
}

//returns an element in a specified slot
double NumberArray::getElement(int num) const
{
    return array[num];
}

//return the largest number in the array
double NumberArray::getHighest()
{
    double tempNum = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] > tempNum) 
        {
            tempNum = array[i];
        }
    }

    return tempNum;
}

//return the smallest number in the array
double NumberArray::getLowest()
{
    double tempNum = array[0];

    for (int i = 0; i < size; i++)
    {
        if (tempNum > array[i])
        {
            tempNum = array[i];
        }
    }

    return tempNum;
}

//return the average of all numbers in the array
double NumberArray::getAverage()
{
    double tempNum = 0;
    double tempSize = 0;

    for (int i = 0; i < size; i++)
    {
        tempNum = tempNum + array[i];
        tempSize = tempSize + 1;
    }

    tempNum = tempNum / tempSize;
    return tempNum;
}

//deconstructor
NumberArray::~NumberArray()
{
    delete[] array;
}
