#include <iostream>
#define int long long int
using namespace std;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

int divs(int k){
    int r = 0;
    for(int i = 1; i * i <= k; i++){
        if(!(k % i)){
            r++;
            if(k != i * i) r++;
        }
    }
    return r;
}

int N, v, g;

signed main(){
    cin >> N;
    cin >> g;
    for(int i = 1; i < N; i++){
        cin >> v;
        g = gcd(v, g);
    }
    cout << divs(g) << endl;
}
