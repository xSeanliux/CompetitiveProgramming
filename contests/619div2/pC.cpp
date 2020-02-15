#include <iostream>
#define int long long int
using namespace std;

int T, n, m;

inline int choose(int x){
    return x * (x + 1) / 2;
}

void solve(){
    cin >> n >> m;
    if(m >= n / 2){
        cout << choose(n) - (n - m) << endl;
        return;
    }
    int k = (n - m) / (m + 1);
    int a = m + 1 - (n - m) % (m + 1), b = (n - m) % (m + 1);
    cout << choose(n) - (a * choose(k) + b * choose(k + 1)) << endl;
}

signed main(){
    cin >> T;
    while(T--) solve();
}
