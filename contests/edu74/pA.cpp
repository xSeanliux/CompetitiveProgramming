#include <iostream>
#include <vector>
#include <string.h>
#define int long long int
using namespace std;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int a, b, q;

signed main(){
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a - b > 1){
            cout << "YES" << endl;
        } else
            cout <<"NO" << endl;
    }
}
