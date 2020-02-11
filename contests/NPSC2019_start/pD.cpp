#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>
#include <string.h>
#include <random>
#include <ctime>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>
#define pii pair<int, ll>
#define F first
#define S second
#define ll long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const ll maxN = 30, MOD = 3e7 + 23;

ll N, vals[maxN][maxN];

inline int getHash(string &s){
    static int r = 0;
    r = 0;
    for(char c : s){
        r *= 2;
        r += (c - '0');
    }
    return r;
}

vector<pii> mp[MOD];

inline ll getVal(int x){
    static int t;
    t = x % MOD;
    for(pii u : mp[t]) if(x == u.F) return u.S;
    return -1;
}

inline void ins(int k, ll v){
    static int t;
    t = k % MOD;
    mp[t].emplace_back(k, v);
}

signed main(){
    random_device rd;
    mt19937 g(rd());
    srand(time(NULL));
    time_t st = clock();
    ericxiao;
    cin >> N;
    for(int i = 0; i < 2 * N; i++) for(int j = 0; j < 2 * N; j++) cin >> vals[i][j];
    //get the value for first N then second N
    ll v = 0;
    string h = "";
    for(int i = 0; i < N; i++) h += '0';
    for(int i = 0; i < N - 1; i++) h += '1';
    ll oPos, zPos;
    for(int i = 0; i < N; i++){
        for(int j = N; j < 2 * N; j++) v += vals[i][j];
    }

    int ids[2 * N];
    iota(ids, ids + 2 * N, 0);
    shuffle(ids, ids + 2 * N, g);

    int nv[30][30];
    for(int i = 0; i < 2 * N; i++){
        //ith player is actually id[i]th
        for(int j = 0; j < 2 * N; j++){
            nv[i][j] = vals[ids[i]][ids[j]];
        }
    }
    for(int i = 0; i < 2 * N; i++){
        //ith player is actually id[i]th
        for(int j = 0; j < 2 * N; j++){
            vals[i][j] = nv[i][j];
        }
    }

    ll ans = v, val;
    int hsh, i, j;
    ins(getHash(h), ans);
    //cout << "Ans = " << ans << endl;
    while(next_permutation(h.begin(), h.end())){
        if(clock() - st >= CLOCKS_PER_SEC * 6.5){
            cout << ans << endl;
            return 0;
        }
        oPos = zPos = -1;
        //cout << "Current h = " << h << endl;
        for(i = 0; i < 2 * N - 1; ++i){
            if(h[i] == '1' && oPos == -1) oPos = i;
            if(h[i] == '0' && oPos != -1 && zPos == -1) zPos = i;
            if(oPos >= 0 && zPos >= 0) break;
        }
        //cout << "1Pos = " << oPos << ", 0Pos = " << zPos << endl;
        swap(h[oPos], h[zPos]);
        hsh = getHash(h);
        val = getVal(hsh);
        //cout << "Coming from " << h << endl;
        //cout << "Old val = "  << val << endl;
        //remember that there's a 0 at the -1th position!
        for(i = 0; i < 2 * N - 1; ++i){
            if(i == zPos || i == oPos) continue;
            //cout << "i = " << i << endl;
            if(h[i] == '1'){
                val += vals[zPos][i] - vals[oPos][i];
            } else {
                val += vals[oPos][i] - vals[zPos][i];
            }
            //cout << "val = " << val << endl;
        }
        val -= vals[oPos][2 * N - 1];
        val += vals[zPos][2 * N - 1];
        //cout << "New val = " << val << endl;
        swap(h[oPos], h[zPos]);
        hsh += (1LL << oPos) - (1LL << zPos);
        ins(hsh, val);
        ans = max(ans, val);
    }
    cout << ans << '\n';
}
