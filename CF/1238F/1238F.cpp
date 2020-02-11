#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 10;

int q, n, a, b, ans;

vector<int> adj[maxN + 10], dp;

inline int deg(int x){
    return adj[x].size();
}

void initdp(int p, int c){
    int r = 0, cnt = 0;
    for(int u : adj[c]){
        if(u == p) continue;
        initdp(c, u);
    }
    sort(adj[c].begin(), adj[c].end(), [=](int a, int b){
        return dp[a] > dp[b];
    });
    dp[c] = 1;
    bool hasmet = (p == c);
    for(int i = 0; i < adj[c].size(); i++){
        if(adj[c][i] == p){
            hasmet = true;
            continue;
        }
        //cout << "Looking at " << adj[c][i] << endl;
        if(cnt == (1 + (p == c || deg(p) == 1)) || dp[adj[c][i]] == 1){
            dp[c] += adj[c].size() - i - !(hasmet);
            break;
        }
        else {
            dp[c] += dp[adj[c][i]];
            if(deg(adj[c][i]) > 1) cnt++;
        }
    }
    //cout << "dp[" << c << "] = " << dp[c] << endl;
}

void reroot(int p, int c){
    int oridpc = dp[c], oridpu, ndp, cnt;
    bool hasmet;
    for(int u : adj[c]){
        if(u == p) continue;
        //going from c to u

        oridpu = dp[u];
        dp[u] = dp[c] = 1;
        hasmet = false;
        cnt = 0;
        //cout << "Running reroot(" << c << ", " << u << ")" << endl;
        for(int i = 0; i < adj[c].size(); i++){
            //cout << "Looking at " << adj[c][i] << endl;
            if(adj[c][i] == u){
                hasmet = true;
                continue;
            }
            if(cnt == (1 + (deg(u) == 1)) || dp[adj[c][i]] == 1){
                dp[c] += adj[c].size() - i - !(hasmet);
                break;
            }
            else {
                dp[c] += dp[adj[c][i]];
                cnt++;
            }
        }
        cnt = 0;
        //cout << "New dp[" << c << "] = " << dp[c] << endl;
        sort(adj[u].begin(), adj[u].end(), [=](int a, int b){
            return dp[a] > dp[b];
        });
        for(int i = 0; i < adj[u].size(); i++){
            if(cnt == 2 || dp[adj[u][i]] == 1){
                dp[u] += adj[u].size() - i;
                break;
            }
            else {
                dp[u] += dp[adj[u][i]];
                if(deg(adj[u][i]) > 1) cnt++;
            }
        }

        //cout << "New dp[" << u << "] = " << dp[u] << endl;
        ans = max(ans, dp[u]);
        //cout << "root at " << u << ": " << dp[u] << endl;
        reroot(c, u);
        dp[c] = oridpc;
        dp[u] = oridpu;
    }
}

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n;
        dp.resize(n + 1);
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            dp[i] = 0;
        }
        for(int i = 0; i < n - 1; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        initdp(1, 1);
        ans = dp[1];
        //cout << "Root at 1: " << dp[1] << endl;
        reroot(1, 1);
        cout << ans << endl;
    }
}
