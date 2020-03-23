#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxP = 800;

int powsum[maxP], T, N, K, x;

inline void solve(){
    for(int i = 0; i < maxP; i++) powsum[i] = 0;
    for(int i = 0; i < N; i++){
        cin >> x;
        for(int i = 0; i < maxP; i++){
            powsum[i] += (x % K);
            x /= K;
        }
    }
    for(int i = 0; i < maxP; i++){
        if(powsum[i] > 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        solve();
    }
}
