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

class Coin
{
    private:
        string sideUp;
    public:
        Coin();
        void Toss();
        string getSideUp() const;
};

//default constructor
Coin::Coin()
{
    int num = rand() % 2 + 1;
    if (num == 1) {sideUp = "Heads";}
    if (num == 2) {sideUp = "Tails";}
    srand (time(NULL));
}

void Coin::Toss()
{
    int num = rand() % 2 + 1;
    if (num == 1) {sideUp = "Heads";}
    if (num == 2) {sideUp = "Tails";}
}

string Coin::getSideUp() const
{
    return sideUp;
}