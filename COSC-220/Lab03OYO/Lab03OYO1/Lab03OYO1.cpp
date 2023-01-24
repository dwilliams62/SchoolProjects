//Dylan Williams
//Created 09/14/2022
//Last Updated 09/14/2022
//A program used to practice using classes with circles
//Lab03 On-Your-Own problem #1

#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    Circle circles[1000]; //create an array of circles to hold the thousand circles

    for (int i = 0; i < 1000; i++) //fill the circles with random radius and centers
    {
        double radius = rand() % 2 + 1;
        circles[i].setRadius(radius);
        double x = rand() % 40;
        x = x - 20;
        double y = rand() % 40;
        y = y - 20;
        circles[i].setCenter(x, y);
    }

    for (int i = 0; i < 1000; i++) //for each circle
    {
        for (int n = 0; n < 1000; n++) //and for each circle it is compared to
        {
            if (circles[i].collide(circles[n]) && i != n) //if the circles collide, display a message saying so
            {
                cout << "Circle number " << i + 1 << " and circle number " << n + 1 << " collided!";
                cout << endl;
            }
        }
    }

    return 0;
}
