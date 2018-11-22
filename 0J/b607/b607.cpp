#include <iostream>
using namespace std;

int largestPrime(int ceil)
{
    bool truthtable[ceil] = {true};
    truthtable[1] = false;
    for(int i = 2; i*i < ceil; i++)
    {
        if(truthtable[i])
        {
            for(int j = i*i; j < ceil; j+=i)
            {
                !truthtable[j];
            }
        }
    }
    for(int i = ceil-1; i >=0; i--)
    {
        if(truthtable[i])
        {
            return i;
        }
    }
    return 2;
}

int largestPrime(int ceil)
{
    bool truthtable[ceil] = {true};
    truthtable[1] = false;
    for(int i = 2; i*i < ceil; i++)
    {
        if(truthtable[i])
        {
            for(int j = i*i; j < ceil; j+=i)
            {
                !truthtable[j];
            }
        }
    }
    for(int i = ceil-1; i >=0; i--)
    {
        if(truthtable[i])
        {
            return i;
        }
    }
}






int main()
{
    int num;
    int sum[];
    while(cin >> num)
    {
        while(num > 0)
        {
            if(largestPrime(num))
            {
                sum.append(largestPrime(num));
                num -= largestPrime(num);
            }
        }
        for(int i = 0; i < (sizeof(p)/sizeof(*p)); i++){
            cout << sum[i] << " ";

        }
        cout << endl;

    }
}


