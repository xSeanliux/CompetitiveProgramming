#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool primes[1000006];
long long divisors[1000006]; //storing all the divisors
long long divisorcount = 0;
int k = 0;
void findDivisors(int x)

{
    if(x == 1) return;
    long long new_x;
    //cout << "Calculating: " << x << endl;

    for(int i = 2; i <= x; i++)
    {
        if(primes[i] && x % i == 0)
        {
            //cout << "Found: " << i << endl;
            divisors[i] += 1;
            x /= i;
            divisorcount++;
            findDivisors(x);

            break;
        }
    }
}


int main()
{
    for(int i = 0 ; i < 1000006 ; i++)
    {
        primes[i] = true;

    }
    primes[0] = false;
    primes[1] = false;
    for(int i = 2 ; i*i < 1000006; i++)
    {
        if(primes[i])
        {
            for(int j = i*i; j < 1000006; j+=i)
            {
                primes[j] = false;
            }
        }
    }


    int N;
    string ans;
    while(cin >> N)
    {

        findDivisors(N);
        for(int i = 2 ; i <= N; i++)
        {

                if(divisors[i] > 1)
                {
                    cout << i << "^" << divisors[i];

                    divisorcount -= divisors[i];
                    if(divisorcount > 0) cout << " * ";
                    //else cout << endl;

                }
                else if(divisors[i] == 1)
                {
                    cout << i;
                    divisorcount -= divisors[i];
                    if(divisorcount > 0) cout << " * ";
                    //else cout << endl;
                }




            divisors[i] = 0;

        }
        cout << endl;
        divisorcount = 0;

    }


}


