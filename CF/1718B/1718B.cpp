#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int maxK = 61, maxN = 200;
int fib[maxK], fibpre[maxK], N, arr[maxN];
bool canDo = 0;

bool dfs(int idx, int last) {
    //cout << "running " << idx << " " << last << endl;
    if(idx == -1) return true;
    for(int i = 0; i < N; i++) {
        if(i != last && arr[i] >= fib[idx]) {
            arr[i] -= fib[idx];
            if(dfs(idx - 1, i)) {
                arr[i] += fib[idx];
                return true;
            }
            arr[i] += fib[idx];
        }
    }
    return false;
}

inline void solve() {
    int sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    canDo = 0;
    for(int idx = 0; idx < maxK; idx++) {
        if(fibpre[idx] == sum) {
            cout << (dfs(idx, -1) ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "No" << endl;
}
signed main() {
    fib[0] = fib[1] = fibpre[0] = 1;
    for(int i = 2; i < maxK; i++) fib[i] = fib[i - 1] + fib[i - 2];
    for(int i = 1; i < maxK; i++) fibpre[i] = fibpre[i - 1] + fib[i]; //fib is actually fibpre

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}

