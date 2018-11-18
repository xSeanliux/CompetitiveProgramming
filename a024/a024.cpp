#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main()
{
    long long int a, b;
    while(cin >> a >> b)
    {
        //cout << a << " " << b << endl;

        cout << gcd(a, b) << endl;

    }



}
