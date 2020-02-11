#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, maxLog = 20;

int n, m, q, dep[maxN], anc[maxLog][maxN], sts[maxN], a, _a, b, _b, lca, len, res, midpoint;
vector<int> adj[maxN];

inline int getAnces(int x, int d){ //get dth ancestor of x
    for(int i = maxLog - 1; i >= 0; i--){
        if(d >= (1 << i)){
            x = anc[i][x];
            d -= (1 << i);
        }
    }
    return x;
}

inline int LCA(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    a = getAnces(a, dep[a] - dep[b]);
    if(a == b) return a;
    for(int i = maxLog - 1; i >= 0; i--){
        if(anc[i][b] != anc[i][a]){
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

void dfs(int p, int c){
    dep[c] = dep[p] + 1;
    sts[c] = 1;
    anc[0][c] = p;
    for(int i = 1; i < maxLog; i++){
        anc[i][c] = anc[i - 1][anc[i - 1][c]];
    }
    for(int u : adj[c]){
        if(u == p) continue;
        dfs(c, u);
        sts[c] += sts[u];
    }
}

int main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dep[1] = 0;
    dfs(1, 1);
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(dep[a] < dep[b]) swap(a, b);
        if(a == b){
            cout << n << endl;
            continue;
        }
        lca = LCA(a, b);
        len = dep[a] + dep[b] - 2 * dep[lca];
        //cout << "LCA = " << lca << endl;
        if(len % 2){
            cout << 0 << endl;
            continue;
        }
        midpoint = getAnces(a, len/2);
        res = sts[midpoint];
        if(dep[a] == dep[b]){
            res = n;
            res -= sts[getAnces(a, dep[a] - dep[lca] - 1)];
            res -= sts[getAnces(b, dep[b] - dep[lca] - 1)];
        } else {
            res -= sts[getAnces(a, dep[a] - dep[midpoint] - 1)];
        }
        cout << res << endl;
    }
}
