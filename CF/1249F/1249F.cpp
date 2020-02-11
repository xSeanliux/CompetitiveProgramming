//lol accidentally did O(n^2) solution, see line 21
#include <iostream>
#include <vector>
using namespace std;

const int maxN = 210, INF = 1e7;

int dp[maxN][maxN], wei[maxN], n, k, m, a, b;
vector<int> adj[maxN];

void dfs(int p, int c){
    for(int u : adj[c]){
        if(u == p) continue;
        dfs(c, u);
    }
    for(int j = n; j >= 0; j--){
        if(j < n) dp[c][j] = max(dp[c][j + 1], dp[c][j]);
        int s = 0, minDelta = INF;
        for(int u : adj[c]){ //the sum of all things here (handshaking lemma) is O(E) = O(V) = O(n), then all depths is O(n)
            if(u == p) continue;
            s += dp[u][max(j - 1, k - j)];
            minDelta = min(minDelta, dp[u][max(j - 1, k - j)] - dp[u][j - 1]);
        }
        dp[c][j] = max(dp[c][j], s - minDelta);
        if(!j){
            s = wei[c];
            for(int u : adj[c]){
                if(u == p) continue;
                s += dp[u][k];
            }
            dp[c][j] = max(dp[c][j], s);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> wei[i];
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i <= n; i++) for(int j = 0; j <= k; j++) dp[i][j] = 0;
    dfs(1, 1);
    cout << dp[1][0] << endl;
}
