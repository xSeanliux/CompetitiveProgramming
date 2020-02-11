#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10, INF = 1e9;
int n, m, u, v, c, k, x, dp[maxN][2];
vector<bool> isi, has;
vector<pii> adj[maxN];

void dfs(int p, int c){
    dp[c][0] = 0;
    has[c] = isi[c];
    int minV = INF, cc = 0;
    for(auto E : adj[c]){
        if(E.F == p) continue;
        dfs(c, E.F);
        cc += has[E.F];
        has[c] = has[c] | has[E.F];
        if(has[E.F]){
            if(isi[c]){
                dp[c][0] += min(dp[E.F][1], dp[E.F][0]) + E.S;
                minV = min(minV, min(dp[E.F][1], dp[E.F][0]) + E.S);
            } else {
                dp[c][0] += min(dp[E.F][1] + E.S, dp[E.F][0]);
                minV = min(minV, dp[E.F][1] - min(dp[E.F][1] + E.S, dp[E.F][0]));
            }
        }
    }
    if(cc)
        dp[c][1] = min(dp[c][0], dp[c][0] - minV);
    if(!cc){
        dp[c][0] = dp[c][1] = 0;
    } else if(isi[c]) {
        dp[c][1] = INF;
    }
    //cout << "For node = " << c << ", dp[c][0] = " << dp[c][0] << ", dp[c][1] = " << dp[c][1] << endl;
}


int main(){
    cin >> n >> m;
    isi.resize(n + 1);
    has.resize(n + 1);
    for(int i = 0; i < n; i++){
        isi[i] = false;
    }

    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> x;
        isi[x] = true;
    }

    dfs(1, 1);
    cout << min(dp[1][0], dp[1][1]) << endl;
}
