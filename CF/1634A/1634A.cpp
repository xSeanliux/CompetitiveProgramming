#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

inline void solve() {
    string s, s_;
    int k, n;
    cin >> n >> k >> s;
    s_ = s;
    reverse(s_.begin(), s_.end());
    if(s == s_) {
        cout << 1 << endl;
        return;
    }
    cout << (k > 0) + 1 << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
