#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

string query;
long long num = 1;
int f[5000000][2];
int newf[10000000];
bool isPrime[10000000];
int k = 10000000;


void findPrimes()
{
    for(int i = 2; i*i <= k; i++)
    {
        if(isPrime[i])
        {

            for(int j = i*i; j < k; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void factorize(int n)
{
    int i = 0;
    for(i = 2; i <= n; i++)
    {
        if(isPrime[i] && n % i == 0)
        {
            //cout << i << " divides " << n << endl;
            newf[i]++;
            factorize(n/i);
            return;
        }
    }
    return;
}

int main()
{
    cout <<"g" << endl;
    for(int i = 0; i < k; i++) isPrime[i] = true;
    cout <<"g" << endl;
    findPrimes();
    cout <<"g" << endl;


    string currentStr = "";
    int currentInt = 0;
    int head = 0;
    bool isNum = true;
    while(getline(cin, query))
    {
        cout <<"g" << endl;
        for(int i = 0; i < k; i++)
        {
            f[i][0] = 0;
            f[i][1] = 0;
            newf[i] = 0;
        }
        num = 1;
        if(query == "0") return 0;
        for(int i = 0; i < query.length(); i++)  //parsing
        {
            if(query[i] == ' ' || i == query.length() - 1)
            {
                currentStr += query[i];
                currentInt = stoi(currentStr);
                if(isNum)
                {
                    f[head][0] = currentInt; //is a base
                }
                else
                {
                    f[head][1] = currentInt; //is an exponent
                    //cout << f[head][0] << "^" << f[head][1] << "*" << endl;
                    head++;

                }

                isNum = !isNum;
                currentStr = "";
            }
            else
            {
                currentStr += query[i];
            }
        }
        for(int i = 0; i < head; i++)
        {
            num *= pow(f[i][0], f[i][1]);
        }
        num--;
        cout << "Num: " << num << endl;
        //factorize
        factorize(num);
        for(int i = num; i >= 0; i--)
        {
            if(newf[i] > 0)
            {
                cout << i << " " << newf[i]<< " ";
            }
        }
        cout << endl;
    }


}

