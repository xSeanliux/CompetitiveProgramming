#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 2260, MOD = 1e9 + 7;


int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = exp(b, e/2);
    r = r * r % MOD;
    if(e & 1) r = r * b % MOD;
    return r;
}

int inv(int x){
    return exp(x, MOD - 2);
}

int indices[maxN], lens[maxN], invfact[maxN], fact[maxN], N, M, ans;

signed main(){
    invfact[0] = fact[0] = 1;
    for(int i = 1; i < maxN; i++){
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = inv(fact[i]);
    }
    cin >> N >> M;
    ans = fact[N - M];
    //cout << "Ans is " << ans << endl;
    indices[0] = 0;
    indices[M + 1] = N + 1;
    for(int i = 1; i <= M; i++) cin >> indices[i];
    sort(indices, indices + M + 1);
    for(int i = 1; i <= M + 1; i++){
        lens[i] = indices[i] - indices[i - 1] - 1;
        //cout << "len = " << lens[i] << endl;
        ans = ans * invfact[lens[i]] % MOD;
        //cout << "Ans now " << ans << endl;
    }
    for(int i = 2; i <= M; i++){
        if(lens[i])
            ans = (ans * exp(2, lens[i] - 1) % MOD) % MOD;
    }
    cout << ans << endl;
}
