#include <iostream>
using namespace std;

const int maxN = 1e3 + 10;
int N, arr[maxN], used[maxN], ans[maxN];

inline void solve() {
    cin >> N;
    fill(used, used + N + 1, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];
    if(N == 1) {
        cout << -1 << endl;
        return;
    }
    bool f = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!used[j] && (j != arr[i])) {
                used[j] = 1;
                ans[i] = j;
                break;
            } else if(j == N) {
                f = 1;
                for(int k = 1; k <= N; k++) if(!used[k]) {
                    used[k] = 1;
                    ans[i] = k;
                }
            }
        }
    }
    if(f) swap(ans[N - 1], ans[N - 2]);
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];

}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
