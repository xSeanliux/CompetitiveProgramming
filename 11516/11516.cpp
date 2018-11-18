#include <iostream>
#include <math.h>
using namespace std;

float housearr[100000 + 5];
bool inRange[100000 + 5];
int cases, points, houses;

int main()
{
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        cin >> points >> houses;
        if(points >= houses)
        {
            cout << "0" << endl;
            continue;
        }
        for(int i = 0 ; i < houses; i++)
        {
            inRange[i] = false;
        }
        for(int i = 0; i < houses; i++)
        {
            cin >> housearr[i];
        }

        sort(housearr, housearr + houses);
        int upperRadius = 1000000;
        int lowerRadius = 1;
        int middleRadius = (upperRadius + lowerRadius)/2;
        int numOfAp = 0;
        for(int i = 0; i < houses; i++)
        {
            if(!inRange[i])
            {
                numOfAp++;
                for(int j = 0; j < houses; j++)
                {
                    if(abs(housearr[i]+middleRadius - housearr[j] <= middleRadius))
                    {
                        inRange[j] = true;
                    }
                }
            }
        }
        if(numOfAp > points)
        {
            lowerRadius = middleRadius;
            middleRadius = (upperRadius + lowerRadius)/2;
        }
        else
        {
            upperRadius = middleRadius;
            middleRadius = (upperRadius + lowerRadius)/2;
        }
        while(abs(numOfAp - points) >= 1)
        {
            cout << numOfAp << endl;
            for(int i = 0 ; i < houses; i++)
            {
                inRange[i] = false;
            }
            numOfAp = 0;
            for(int i = 0; i < houses; i++)
            {
                if(!inRange[i])
                {
                    numOfAp++;
                    for(int j = 0; j < houses; j++)
                    {
                        if(abs(housearr[i]+middleRadius - housearr[j] <= middleRadius))
                        {
                            inRange[j] = true;
                        }
                    }
                }
            }
            if(numOfAp > points)
            {
                lowerRadius = middleRadius;

            }
            else
            {
                upperRadius = middleRadius;

            }
            middleRadius = (upperRadius + lowerRadius)/2;

        }
        cout << middleRadius << endl;



    }
}
