#include <iostream>
using namespace std;

const int maxN = 1e3 + 326;
int T, N, arr[maxN], dif[maxN];

inline void solve(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    dif[0] = arr[0];
    for(int i = 1; i < N; i++) dif[i] = arr[i] - arr[i - 1];
    int x = 0;
    for(int i = N - 1; i >= 0; i -= 2) x ^= dif[i];
    cout << (!x ? "NIE" : "TAK") << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}
