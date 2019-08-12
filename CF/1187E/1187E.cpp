#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5;

int N, a, b, ans = 0;
vector<int> adj[maxN + 10], sts;

void getsts(int p, int c){
    sts[c] = 1;
    for(int u : adj[c]){
        if(u == p) continue;
        getsts(c, u);
        sts[c] += sts[u];
    }
}

void getans(int p, int c, int currentans){
    ans = max(ans, currentans);
    int ori;
    for(int u : adj[c]){
        if(u == p) continue;
        sts[c] = N - sts[u];
        ori = sts[u];
        sts[u] = N;
        getans(c, u, currentans + N - 2 * ori);
    }
}

signed main(){
    ericxiao;
    cin >> N;
    sts.resize(N + 1);
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getsts(1, 1);
    for(int i = 1; i <= N; i++){
        ans += sts[i];
        //cout << "sts[" << i << "] = " << sts[i] << endl;
    }
    getans(1, 1, ans);
    cout << ans << endl;
}
