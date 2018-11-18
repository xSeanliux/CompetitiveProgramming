#include <iostream>
using namespace std;

int main()
{
    int N;
    int i;
    int p, q; //numerator and denominator
    while( cin >> N )
    {
        for(i = 1; i*(i+1)/2 < N; i++)
        {
            //get i
        }
        //cout <<"i: " << i << endl;
        if(i % 2 == 0)
        {
            p = i;
            q = 1;
            for(int j = 0; j < abs(i*(i+1)/2 - N); j++)
            {
                p--;
                q++;
            }

        }
        else
        {
            p = 1;
            q = i;
            for(int j = 0 ; j < abs(i*(i+1)/2 - N); j++)
            {
                p++;
                q--;
            }

        }
        cout << "TERM " << N << " IS " << p << "/" << q << endl;
    }
}
