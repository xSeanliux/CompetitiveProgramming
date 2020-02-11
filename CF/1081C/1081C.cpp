#include <iostream>
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 2000;
int n, m, k, C[maxN + 10][maxN + 10];

int modexp(int b, int e){
    if(!e) return 1;
    if(!b) return 0;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

int choose(int a, int b){
    b = min(b, a - b);
    if(C[a][b] != -1) return C[a][b];
    if(!b){
        return 1;
    }
    C[a][b] = (choose(a - 1, b) + choose(a - 1, b - 1)) % MOD;
    return C[a][b];
}

signed main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            C[i][j] = -1;
        }
    }
    C[0][0] = 1;
    cout << (m * choose(n - 1, k) % MOD) * modexp(m - 1, k) % MOD << endl;
}

