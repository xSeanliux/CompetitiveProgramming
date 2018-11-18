#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c ,X;
    while(cin >> a >> b >> c >> X){
        cout << "Answer is: " << a << "x^2 + " << b << "x + " << c << " = " << pow(X, a) + b*X + c;
    }
    
}
