#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    bool primeList[65538];
    bool flag = true;
    for(int i = 0; i < 65538; i++)
    {
        primeList[i] = true;
    }



    int sqrt_num = 65536;
    for(int i = 3; i*i <= sqrt_num; i+=2)  //init the table;
    {
        if(primeList[i])
        {
            //cout << "Found Prime: " << i << endl;
            for(int j = i*i; j <= sqrt_num; j+= i)
            {

                //cout << "=> " << j << " is not prime." << endl;
                primeList[j] = false;
            }
        }
    }



    int num;
    while(cin >> num)
    {
        /*

        int sqrt_num = ceil(sqrt(num));
        for(int i = 3; i <= sqrt_num; i+=2)  //init the table;
        {
            if(primeList[i])
            {
                //cout << "Found Prime: " << i << endl;
                for(int j = i*i; j <= sqrt_num; j+= i)
                {

                    //cout << "=> " << j << " is not prime." << endl;
                    primeList[j] = false;
                }
            }
        }
        */


        for(int i = 2; i <= sqrt_num; i++)
        {
            //cout <<  i << endl;

            //cout << "primeList[" << i << "] is " << primeList[i] << endl;
            if(primeList[i] & num % i == 0 & num != i)
            {
                //cout << num << " : " << "非質數" << endl;
                cout << "非質數" << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << "質數" << endl;


        //num++;

    }

}
