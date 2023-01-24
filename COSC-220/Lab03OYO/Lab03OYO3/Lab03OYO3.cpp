//Dylan Williams
//Created 09/16/2022
//Last Updated 09/16/2022
//A program used to practice using classes
//Lab03 InLab #3

#include "Coin.h" //include the class code
#include <iostream>

using namespace std;

int main()
{
    Coin coin; //create a coin object
    cout << "The coin is currently facing: " << coin.getSideUp() << endl;

    int headsCounter = 0; //to hold how many times it lands on heads
    int tailsCounter = 0; //to hold how many times it lands on  tails

    //flip the coin twenty times and show results
    for (int i = 0; i < 20; i++) 
    {
        coin.Toss();
        cout << "After the toss, the coin is now facing: " << coin.getSideUp() << endl;
        if (coin.getSideUp() == "Heads") {headsCounter++;}
        if (coin.getSideUp() == "Tails") {tailsCounter++;}
    }

    //display how many times it landed both ways
    cout << "The coin landed on heads " << headsCounter << " times!" << endl;
    cout << "The coin landed on tails " << tailsCounter << " times!" << endl;
    return 0;
}