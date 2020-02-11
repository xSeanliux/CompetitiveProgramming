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

const ll maxN = 30, MOD = 1e3 + 23;
time_t st;
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

bool cur[30], _t[30];

ll vals[30][30], N, ans = 0;

void dfs(int pos, int zPos = -1, int oPos = -1, int ones = 0){
    if(clock() - st > CLOCKS_PER_SEC * 6.7) return;
    //cout << "Running dfs(" << pos << ", " << zPos << ", " << oPos << ", " << ones << ", " << endl;
    if(ones + (2 * N - pos - 1) < N - 1 || ones > N - 1) return;
    if(pos == 2 * N - 1){ //oh yay
        //cout << "YES:" << endl;
        //cout << "OPOS = " << zPos << ", 1POS = " << oPos << endl;
        //for(int i = 0; i< 2 * N -1 ;i++) cout << cur[i];
        //cout << endl;
        if(zPos == -1 || oPos == -1) return;
        static ll val, hsh;
        for(int i = 0; i < 2 * N - 1; i++) _t[i] = cur[i];
        _t[zPos] ^= 1;
        _t[oPos] ^= 1;
        val = 0, hsh = 0;
        for(int i = 0; i < 2 * N - 1; i++){
            hsh *= 2;
            hsh += _t[i];
        }
        val = getVal(hsh);
        //cout << "Oldhash = " << hsh << endl;
        //cout << "Original val = " << val << endl;
        for(int i = 0; i < 2 * N - 1; i++){
            if(i == zPos || i == oPos) continue;
            if(_t[i]){
                val += vals[zPos][i] - vals[oPos][i];
            } else {
                val += vals[oPos][i] - vals[zPos][i];
            }
        }
        val -= vals[oPos][2 * N - 1];
        val += vals[zPos][2 * N - 1];
        if(ans < val) ans = val;
        //cout << "val = " << val << endl;
        hsh = 0;
        for(int i = 0; i < 2 * N - 1; i++){
            hsh *= 2;
            hsh += cur[i];
        }
        //cout << "My hash = " << hsh << endl;
        //cout << endl;
        ins(hsh, val);
        return;
    } else {
        cur[pos] = 0;
        if(oPos >= 0 && zPos == -1){
            dfs(pos + 1, pos, oPos, ones);
        } else {
            dfs(pos + 1, zPos, oPos, ones);
        }
        cur[pos] = 1;
        if(oPos == -1){
            dfs(pos + 1, zPos, pos, ones + 1);
        } else {
            dfs(pos + 1, zPos, oPos, ones + 1);
        }
    }
}

int main(){
    random_device rd;
    mt19937 g(rd());
    srand(time(NULL));
    st = clock();
    cin >> N;
    for(int i = 0; i < 2 * N; i++) for(int j = 0; j < 2 * N; j++) cin >> vals[i][j];

    int ids[2 * N];
    iota(ids, ids + 2 * N, 0);
    shuffle(ids, ids + 2 * N, g);
    //cout << "New ids = " << endl;
    //for(int i = 0; i < 2 * N; i++) cout << ids[i] << " ";
    //cout << endl;
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
    /*
    cout << "new vals " << endl;
    for(int i = 0; i < 2 * N; i++){
        //ith player is actually id[i]th
        for(int j = 0; j < 2 * N; j++){
            cout << vals[i][j] << " ";
        }
        cout << endl;
    }
    */
    ll val = 0;
    for(int i = 0; i < N; i++){
        for(int j = N; j < 2 * N; j++) val += vals[i][j];
    }
    ans = val;
    ins((1LL << (N - 1)) - 1, val);
    dfs(0);
    cout << ans << endl;
}
