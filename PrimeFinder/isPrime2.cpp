#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    bool primeTable[2147483649];
    for(int i = 0; i < 2147483648; i++)
    {
        primeTable[i] = true;
    }
    primeTable[0] = false;
    primeTable[1] = false;
    int num;
    string ans;
    while(cin >> num)
    {

        int sqrt_num = ceil(sqrt(num));





        for(int i = 2; i*i <= sqrt_num; i++)
        {
            if(primeTable[i])
            {
                cout << "Found Prime: " << i << endl;
                for(int j = i*i; j <= sqrt_num; j += i)
                {
                    primeTable[j] = false;
                    cout << " => " << j << " is not prime!" << endl;
                }

            }
        }
        for(int i = 2; i <= sqrt_num; i++)
        {
            if(primeTable[i])
            {
                if(num % i == 0)
                {
                    cout << num << " | " << i << "!" << endl;
                    //return false;
                    cout << "Not Prime" << endl;;
                }
            }
        }
        //return true;
        cout << "Prime" << endl;








        //ans = (isPrime(num)) ? "質數" : "非質數";
        //cout << ans << endl;
    }
    return 0;


}
