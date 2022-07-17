#include <iostream>
using namespace std;

inline void solve() {
    int N, M;
    cin >> N >> M;
    if(M == 1) {
        cout << "YES" << endl;
        for(int i = 1; i <= N; i++) cout << i << endl;
        return;
    }
    if(N & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int o = 1, e = 2;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
           if(i & 1) {
               cout << o << " ";
               o += 2;
           } else {
               cout << e << " ";
               e += 2;
           }
        }
        cout << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
