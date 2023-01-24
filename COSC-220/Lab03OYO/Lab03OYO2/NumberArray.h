//Dylan Williams
//Created 09/16/2022
//Last Updated 09/16/2022
//A program used to practice using classes
//Lab03 InLab #2

#include <iostream>

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

using namespace std;

class NumberArray
{
    private:
        double* array;
        int size;
    public:
        NumberArray(int newSize);
        void setElement(int, double);
        double getElement(int) const;
        double getHighest();
        double getLowest();
        double getAverage();
        ~NumberArray();
};

#endif
