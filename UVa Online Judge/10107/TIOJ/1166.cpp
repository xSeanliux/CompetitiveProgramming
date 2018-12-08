#include <iostream>
using namespace std;
long long int a, b;

int gcd(long long int a, long long int b){
    return (a == 0) ? b : gcd(b % a, a);
}

int main(){
    while(cin >> a >> b){
        if(!a && !b) return 0;
        cout << gcd(a, b) << endl;
    }
}
