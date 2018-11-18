#include <iostream>
#include <math.h>
using namespace std;

long int n, k, l, total;

void f(long int n, long int k, long int l){
    //cout << "Running N = " << n << ", K = " << k << endl;
    n += floor(l/k);
    l %= k;
    total += n;
    l += n;
    n = 0;

    //cout << l << " butts remaining" << endl;
    if(l < k) return;
    else{
        f(n, k, l);
    }
}

int main(){
    while(cin >> n >> k){
        total = 0;
        f(n, k, 0);
        cout << total << endl;
    }
}
