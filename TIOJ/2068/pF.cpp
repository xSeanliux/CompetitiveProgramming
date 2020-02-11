#include <iostream>
#define int long long int
using namespace std;

const int MOD = 998244353, maxK = 5005;

int choose[maxK][maxK];

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

inline int inv(int x){
    return modexp(x, MOD - 2);
}

int n, m, k;

signed main(){
    choose[0][0] = 1;
    for(int i = 1; i < maxK; i++){
        choose[i][0] = 1;
        for(int j = 1; j < i; j++){
            choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j] ) % MOD;
        }
        choose[i][i] = 1;
    }
    cin >> n >> m >> k;
    int sums[maxK];
    sums[0] = m;
    sums[1] = n * inv(m) % MOD;
    for(int i = 2; i <= k; i++){
        for(int j = 0; j < i; j++){
            sums[i] = ((sums[i] + sums[j] * choose[i][j] % MOD)) % MOD;
        }
    }
    cout << sums[k] << endl;
}
