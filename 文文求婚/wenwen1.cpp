#include <iostream>
using namespace std;

bool isLeap(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    int N, a;
    while(cin >> N)
    {
        for(int i = 1 ; i <= N; i++){
            cin >> a;
            if(isLeap(a))
            {
                printf("Case %d: a leap year\n", i);

            }
            else
            {
                printf("Case %d: a normal year\n", i);
            }

        }

        //if(N == 0) return 0;

    }



}
