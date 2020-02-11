#include <iostream>
using namespace std;

int phi[105];

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void getPhi(){
    for(int i = 1; i <= 100; i++){
        phi[i] = 0;
        for(int j = 1; j <= i; j++){
            phi[i] += (gcd(i, j) == 1);
        }
    }
}

int exp(int b, int e, int m){
    if(!e) return 1;
    if(!b) return 0;
    int r = exp(b, e / 2, m);
    r = r * r % m;
    if(e % 2) r = r * b % m;
    return r;
}

int f(int a, int b){
    if(a == 1) return 7 % b;
    if(b == 1) return 0;
    return exp(7, f(a - 1, phi[b]), b);
}

int main(){
    //cout << exp(7, 43, 100) << endl;
    //getPhi();
    int k, r;
    cin >> k;
    if(k == 1) cout << "07" << endl;
    else cout << 43 << endl;
    return 0;
    while(cin >> k){
        r = f(k, 100);
        if(r < 10) cout << 0;
        cout << r << endl;
    }

}
