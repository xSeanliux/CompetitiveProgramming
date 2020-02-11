#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int n, m;
vector<int> vals, ans;

inline void add(int l, int r, int val){
    ans[l] += val;
    ans[r] -= val;
}

signed main(){
    ericxiao;
    cin >> n >> m;
    vals.resize(m);
    ans.resize(n + 2);
    fill(ans.begin(), ans.end(), 0);
    for(int i = 0; i < m; i++){
        cin >> vals[i];
    }
    int a, b;
    for(int i = 0; i < m - 1; i++){
        a = vals[i], b = vals[i + 1];
        if(a == b) continue;
        if(a > b) swap(a, b);
        add(1, a, b - a);
        add(a, a + 1, b - 1);
        add(a + 1, b, b - a - 1);
        add(b, b + 1, a);
        add(b + 1, n + 1, b - a);
    }
    for(int i = 1; i <= n; i++){
        ans[i] += ans[i - 1];
        cout << ans[i] << " \n"[i == n];
    }
}
