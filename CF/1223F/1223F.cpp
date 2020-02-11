#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stack>
#define int long long int
#define pii pair<int,int>
#define tp tuple<int,int,int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


const int maxN = 3e5 + 10, MOD1 = 1e9 + 7, MOD2 = 1e7 + 9, MOD3 = 2147483647, BASE = 3e5 + 7;

int q, n, Mp1[maxN], Mp2[maxN], Mp3[maxN];
vector<int> arr;
map<tp, int> mp;
stack<int> stk;

inline int madd(int a, int b, int m){
    return (a + b) % m;
}

inline int msub(int a, int b, int m){
    return (a - b + m) % m;
}

struct Hasher{
    int h1, h2, h3, len;
    Hasher(){
        h1 = h2 = h3 = len = 0;
    }
    tp getTup(){
        return {len, h1, h2, h3};
    }
    void add(int x){
        h1 = madd(h1, (Mp1[len] * x) % MOD1, MOD1);
        h2 = madd(h2, (Mp2[len] * x) % MOD2, MOD2);
        h3 = madd(h3, (Mp3[len] * x) % MOD3, MOD3);
        len++;
    }
    void sub(int x){
        len--;
        h1 = msub(h1, (Mp1[len] * x) % MOD1, MOD1);
        h2 = msub(h2, (Mp2[len] * x) % MOD2, MOD2);
        h3 = msub(h3, (Mp3[len] * x) % MOD3, MOD3);
    }
} hsh;

int solve(int l, int r){
    if(r - l == 1) return 0;
    if(r - l == 2) return (arr[l] == arr[r - 1]);
    int m = (l + r) / 2;
    int res = solve(l, m) + solve(m, r);
    mp = map<tp, int>();
    stk = stack<int>();
    hsh = Hasher();
    for(int i = m; i < r; i++){
        if(stk.size() && stk.top() == arr[i]){
            hsh.sub(stk.top());
            stk.pop();
        } else {
            stk.push(arr[i]);
            hsh.add(stk.top());
        }
        mp[hsh.getTup()]++;
    }
    hsh = Hasher();
    stk = stack<int>();
    for(int i = m - 1; i >= l; i--){
        if(stk.size() && stk.top() == arr[i]){
            hsh.sub(stk.top());
            stk.pop();
        } else {
            stk.push(arr[i]);
            hsh.add(stk.top());
        }
        res += mp[hsh.getTup()];
    }
    return res;
}

signed main(){
    ericxiao;
    Mp1[0] = Mp2[0] = Mp3[0] = 1;
    for(int i = 1; i < maxN; i++){
        Mp1[i] = (Mp1[i - 1] * BASE) % MOD1;
        Mp2[i] = (Mp2[i - 1] * BASE) % MOD2;
        Mp3[i] = (Mp3[i - 1] * BASE) % MOD3;
    }
    cin >> q;
    while(q--){
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << solve(0, n) << endl;
    }
}
