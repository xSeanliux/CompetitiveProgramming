#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int t, N, mx[maxN], mn[maxN], lis[maxN], sz;
string s;

inline void solve(){
    cin >> N >> s;
    mn[0] = mx[0] = 1;
    for(int i = 1; i < N; i++){
        if(s[i - 1] == '<'){
            mn[i] = mn[i - 1] + 1;
            mx[i] = mx[i - 1] + maxN;
        } else {
            mn[i] = mn[i - 1] - maxN;
            mx[i] = mx[i - 1] - 1;
        }
    }
    for(int i = 0; i < N; i++) lis[i] = mn[i];
    sort(lis, lis + N);
    sz = unique(lis, lis + N) - lis;
    for(int i = 0; i < N; i++) cout << lower_bound(lis, lis + sz, mn[i]) - lis + 1 << " \n"[i == N - 1];

    for(int i = 0; i < N; i++) lis[i] = mx[i];
    sort(lis, lis + N);
    sz = unique(lis, lis + N) - lis;
    for(int i = 0; i < N; i++) cout << lower_bound(lis, lis + sz, mx[i]) - lis + 1 << " \n"[i == N - 1];


}

signed main(){
    ericxiao;
    cin >> t;
    while(t--) solve();
}
