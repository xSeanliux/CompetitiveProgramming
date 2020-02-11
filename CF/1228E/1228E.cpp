#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 300;

int C[maxN][maxN], N, M, K;

inline void getC(){
    C[0][0] = 1;
    for(int i = 0; i < maxN; i++){
        C[i][0] = C[i][i] = 1;
    }
    for(int i = 2; i < maxN; i++){
        for(int j = 1; j < i; j++){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int modexp(int b, int e){
    if(!e) return 1;
    if(!b) return 0;
    int r = modexp(b, e/2);
    r = r * r % MOD;
    if(e % 2) r = r * b % MOD;
    return r;
}

signed main(){
    getC();
    cin >> N >> K;
    int r = 0, m, t;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(!((i + j) % 2)) m = 1;
            else m = MOD - 1;
            m = (m * modexp(K - 1, N * (i + j) - i * j)) % MOD;
            m = (m * modexp(K, (N - i) * (N - j))) % MOD;
            m = (m * C[N][i]) % MOD;
            m = (m * C[N][j]) % MOD;
            //cout << "i = " << i << ", j = " << j << ", m = " << m << endl;
            r = (m + r) % MOD;
        }
    }
    cout << r << endl;
}
