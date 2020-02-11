#include <iostream>
#define int long long int
using namespace std;

int X;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

signed main(){
    cin >> X;
    int a, b;
    for(int i = 1; i * i <= X; i++){
        if(!(X % i) && gcd(i, X / i) == 1){
            a = i;
            b = X / i;
        }
    }
    cout << a << " " << b << endl;
}
