#include <iostream>
#include <map>
#define int long long int
using namespace std;

int n, p, k, x;

signed main(){
    cin >> n >> p >> k;
    map<int, int> mp;
    int ans = 0, t;
    for(int i = 0; i < n; i++){
        cin >> x;
        t = x * x % p;
        t = t * t % p;
        t -= (k * x) % p;
        t = (t + p) % p;
        ans += mp[t];
        mp[t]++;
    }
    cout << ans << endl;
}
