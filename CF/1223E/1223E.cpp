#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 5e5 + 10;

vector<pii>adj[maxN];

int q, n, a, b, k, w, dp[maxN][2];

void dfs(int p, int c){
    vector<int> v;
    v.resize(adj[c].size());
    iota(v.begin(), v.end(), 0);
    for(pii pr : adj[c]){
        if(pr.F == p) continue;
        dfs(c, pr.F);
    }
    sort(v.begin(), v.end(), [=](int a, int b){
        return dp[adj[c][a].F][0] + adj[c][a].S - dp[adj[c][a].F][1] > dp[adj[c][b].F][0] + adj[c][b].S - dp[adj[c][b].F][1];
    });
    dp[c][0] = dp[c][1] = 0;
    int o = 0;
    //cout << "Looking at c = " << c << endl;
    for(int i = 0; i < v.size(); i++){
        if(adj[c][v[i]].F == p) continue;
        if(dp[adj[c][v[i]].F][0] + adj[c][v[i]].S <= dp[adj[c][v[i]].F][1] || o >= k){
            dp[c][0] += dp[adj[c][v[i]].F][1];
            dp[c][1] += dp[adj[c][v[i]].F][1];
            continue;
        }
        if(o < k - 1){
            dp[c][0] += dp[adj[c][v[i]].F][0] + adj[c][v[i]].S;
            dp[c][1] += dp[adj[c][v[i]].F][0] + adj[c][v[i]].S;
            o++;
        } else if(o == k - 1) {
            dp[c][0] += dp[adj[c][v[i]].F][1];
            dp[c][1] += dp[adj[c][v[i]].F][0] + adj[c][v[i]].S;
            o++;
        }
    }
    //cout << "dp[" << c << "][0] = " << dp[c][0] << endl;
    //cout << "dp[" << c << "][1] = " << dp[c][1] << endl;

}


int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        dfs(1, 1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
}
