//Dylan Williams
//Created 09/16/2022
//Last Updated 09/16/2022
//A program used to practice using classes
//Lab03 InLab #3
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

using namespace std;

#ifndef COIN_H
#define COIN_H

class Coin
{
    private:
        string sideUp;
    public:
        Coin();
        void Toss();
        string getSideUp() const;
};

#endif