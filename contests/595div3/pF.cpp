#include <iostream>
#include <vector>
using namespace std;

const int maxN = 226, INF = 1e7;

vector<int> adj[maxN], wei;
int distSums[maxN][maxN];

int n, k, a, b;

void getDists(int p, int c){
    distSums[c][0] = 0;
    for(int i = 1; i <= k; i++) distSums[c][i] = wei[c];
    for(int u : adj[c]){
        if(u == p) continue;
        getDists(c, u);
        for(int i = 1; i <= k; i++) distSums[c][i] += distSums[c][i - 1];
    }
}

int main(){
    cin >> n >> k;
    wei.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> wei[i];
    }
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0, cs, maxDiff;
    for(int i = 1; i <= n; i++){
        getDists(i, i);
        for(int md = 0; md <= k; md++){
            cs = 0;
            if(2 * md <= k){ //everything is k
                for(int u : adj[i]) cs += distSums[u][md];
            } else { //one with md and the rest are k - md
                maxDiff = 0;
                for(int u : adj[i]){
                    cs += distSums[u][k - md];
                    maxDiff = max(maxDiff, distSums[u][md] - distSums[u][k - md]);
                }
                cs += maxDiff;
            }
            ans = max(ans, cs);
        }
    }
    cout << ans << endl;
}
