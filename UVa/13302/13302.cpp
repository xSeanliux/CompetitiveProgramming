#pragma GCC optimize ("O3")
#include <iostream>
#include <math.h>
using namespace std;

long long int L, n, d;

long long int gcd(long long int a, long long int b){
    return (!b) ? a : gcd(b, a % b);
}

int main(){
    while(scanf("%lld%lld%lld", &L, &n, &d)){
        if(!(L | n | d)) return 0;
        long long int ansa = 1, ansb = 1, g, a; //just cut the whole thing
        for(long long int b = max(0LL, 2*n/3 - 1); b <= n; b++){
            a = ceil((b*d+0.0)/L);
            if(ansb * a < ansa * b){
                ansa = a;
                ansb = b;
            }
        }
        ansa *= L;
        g = gcd(ansa, ansb);
        ansa /= g;
        ansb /= g;
        printf("%lld/%lld\n", ansa, ansb);
    }
}
