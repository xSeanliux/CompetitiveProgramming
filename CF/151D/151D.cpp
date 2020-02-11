#include <iostream>
#include <numeric>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 2e3 + 5;

int dsu[maxN], n, m, k, cc;

int pow(int b, int e){
    b %= MOD;
    if(!b) return 0;
    if(!e) return 1;
    int res = pow(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

void flat(int x){
    if(dsu[x] == x) return;
    flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    flat(a);
    flat(b);
    if(dsu[a] == dsu[b]) return;
    cc--;
    dsu[dsu[a]] = dsu[b];
}

signed main(){
    cin >> n >> m >> k;
    cc = n;
    iota(dsu, dsu + n, 0);
    for(int i = 0; i + k <= n; i++){
        for(int j = 0; j < k / 2; j++){
            //cout << "Merging " << i + j << " and " <<i + k - j - 1 << endl;
            Merge(i + j, i + k - j - 1);
        }
    }
    cout << pow(m, cc) << endl;
}


