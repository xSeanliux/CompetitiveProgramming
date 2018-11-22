#include <iostream>
using namespace std;


long long int n, m, N = 1000000007;
long long int totalArea;
long long int allStuff;

long long int gcd(long long int a, long long int b){
    //cout << "gcd(" << a << ", " << b << ")" << endl;
    return (b == 0) ? a : gcd(b , a % b);
}

long long int invmod(long long int x, long long int mod, long long int s0 = 1, long long int s1 = 0){
    return mod?invmod(mod,x%mod,s1,s0-s1*(x/mod)):s0;
}

int main(){
    //cout << gcd(2, 1) << endl;
    cin >> n >> m;
    totalArea = allStuff = 0;
    for(long long int i = 1; i <= n; i++){
        for(long long int j = 1; j <= m; j++){
            if(gcd(i, j) == 1){
                totalArea += i * j;
                totalArea %= N;
                //cout << i << "x" << j << " = " << totalArea << endl;
                allStuff++;
                allStuff %= N;
            }
        }
    }
    long long int g = gcd(totalArea, allStuff);
    totalArea /= g;
    allStuff /= g;
    //cout << totalArea << ", " << allStuff << ", " << totalArea * allStuff << endl;
    long long int ans = (totalArea * invmod(2*N + allStuff, N)) % N;
    while(ans < 0){
        ans += N;
    }
    printf("%lld\n", ans);
    //cout << totalArea << ", " << allStuff << ", " << (totalArea * allStuff) % N << endl;
}
