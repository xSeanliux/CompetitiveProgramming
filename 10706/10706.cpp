#include <iostream>
#include <math.h>
using namespace std;

int k, c;

int main()
{
    cin >> c;
    for(int i = 0 ; i < c;i ++){
        cin >> k;
        int n = floor((sqrt(8*k-7)-1)/2);
        //cout << n << endl;
        cout << k - n*(n+1)/2 << endl;
    }
}
