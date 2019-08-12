#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int frq[2000];
int n, k, t;

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> t;
        frq[t]++;
    }
    int o = 0, ans = 0;
    for(int i = 1; i <= k; i++){
        ans += (frq[i]/2) * 2;
        o += frq[i] % 2;
    }
    ans += (o + 1)/2;
    cout << ans << endl;
}
