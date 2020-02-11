#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

int n, m, x, ans = 0;

vector<int> a, b, mina, minb, prea, preb;

signed main(){
    cin >> n >> m;
    a.resize(n), mina.resize(n + 1), prea.resize(n);
    b.resize(m), minb.resize(m + 1), preb.resize(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        prea[i] = a[i];
        if(i) prea[i] += prea[i - 1];
        mina[i + 1] = prea[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        preb[i] = b[i];
        if(i) preb[i] += preb[i - 1];
        minb[i + 1] = preb[i];
    }
    cin >> x;
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            mina[i] = min(mina[i], prea[j] - prea[j - i]);
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = i; j < m; j++){
            minb[i] = min(minb[i], preb[j] - preb[j - i]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mina[i] * minb[j] <= x){
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;
}
