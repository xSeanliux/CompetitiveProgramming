#include <iostream>
using namespace std;

unsigned long long int q, n, a, b;

int main(){
    cin >> q;
    while(q--){
        cin >> n >> a >> b;
        if(2*a < b){ //us
            cout << a * n << endl;
        } else {
            cout << b * (n / 2) + a * (n & 1) << endl;
        }
    }
}
