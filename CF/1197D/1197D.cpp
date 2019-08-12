#include <iostream>
#include <vector>
#include <set>
#define int long long int
using namespace std;

vector<int> vec;
int n, m, k, mvs[15];

signed main(){
    cin >> n >> m >> k;

    vec.resize(n + 1);
    vec[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
        vec[i] += vec[i - 1]; //is pre
    }
    int ans = 0, R;
    for(int r = 0; r < m; r++){ //len is mod m
        fill(mvs, mvs + m + 1, k);
        for(int i = 0; i <= n; i++){
            R = i % m;
            int rem = (m + R - r + 1) % m;
            int z = vec[i] - k * (i/m);
            int _ans = z - mvs[rem];
            if(R >= rem){
                _ans -= k;
            }
            ans = max(ans, _ans);
            mvs[(R + 1) % m] = min(mvs[(R + 1) % m], vec[i] - k * ((i + 1) / m));
        }
    }
    cout << ans << endl;
}
