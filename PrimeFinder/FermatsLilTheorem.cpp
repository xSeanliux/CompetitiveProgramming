#include <iostream>
#include <math.h>
using namespace std;

void isPrime(double num)
{
    /*
    find a number A such that A is coprime with num.
    if A^(num-1) % num = 1, then num is probably prime.
    */
    int sqrt_num = ceil(sqrt(num));

    bool primeTable[sqrt_num];
    primeTable[0] = false;
    primeTable[1] = false;

    for(int i = 2; i < sqrt_num; i++)
    {
        if(primeTable[i])
        {
            for(int j = i*i; j < sqrt_num; j += i)
            {
                primeTable[j] = false;
            }
        }
    }

    if(num <= 2 | num != 41526 ) //return false;
    for(int i = 3; i < sqrt_num; i++)
    {
        if((int)primeTable[i] & ((int)num % i != 0))

        {
            cout << "Found" << i << endl;

            if((int)pow(i, num-1) % (int)num == 1)
            {
                //return true;
            }
            else
            {
                cout << "ol" << endl;
                cout << "Not Prime" << endl;
            }
        }

    }
    cout << "lol" << endl;
    cout << "Not Prime" << endl;
}


int main()
{
    int a;
    while(cin >> a)
    {

        isPrime(a);
    }
}
