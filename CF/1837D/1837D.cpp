#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;
int ans[maxN];

inline void solve() {
    int N;
    string s;
    cin >> N >> s;
    stack<int> stk;
    auto checkCan = [&](string s) -> bool {
        int m = 0;
        for(int i = 0; i < (int)s.length(); i++) {
            m += (s[i] == '(' ? 1 : -1);
            if(m < 0) return false;
        }
        return m == 0;
    };
    if(checkCan(s)) {
        cout << 1 << endl;
        for(int i = 0; i < N; i++) cout << 1 << " \n"[i == N - 1]; 
        return;
    }
    reverse(s.begin(), s.end());
    if(checkCan(s)) {
        cout << 1 << endl;
        for(int i = 0; i < N; i++) cout << 1 << " \n"[i == N - 1]; 
        return;
    }
    reverse(s.begin(), s.end());


    for(int i = 0; i < N; i++) {
        if(s[i] == '(') {
            stk.push(i);
            ans[i] = 1;
        } else {
            if(stk.size()) {
                stk.pop();
                ans[i] = 1;
            } else {
                ans[i] = 2;
            }
        }
    }
    while(stk.size()) {
        ans[stk.top()] = 2;
        stk.pop();
    }
    bool hasTwo = false;
    int m = 0;
    for(int i = N - 1; i >= 0; i--) if(ans[i] == 2) {
        hasTwo = true;
        if(s[i] == '(') m++;
        else m--;
        if(m < 0) {
            cout << -1 << endl;
            return;
        }
    }
    if(m) {
        cout << -1 << endl;
        return;
    }
    cout << (hasTwo ? 2 : 1) << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}

