#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 10, maxLog = 20;

int dep[maxN], anc[maxN][maxLog], N, u, v, q, k;
vector<int> adj[maxN], que;

void dfs(int p = 1, int u = 1){
    dep[u] = dep[p] + 1;
    anc[u][0] = p;
    for(int i = 1; i < maxLog; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int v : adj[u]) if(v != p) dfs(u, v);
}

bool isAnc(int a, int b){//b is anc of a
    if(dep[b] > dep[a]) return false;
    int dd = dep[a] - dep[b];
    for(int i = 0; i < maxLog; i++){
        if((dd >> i) & 1) a = anc[a][i];
    }
    return a == b;
}

int main(){
    cin >> N >> q;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    while(q--){
        cin >> k;
        que.resize(k);
        for(int i = 0; i < k; i++){
            cin >> que[i];
            que[i] = anc[que[i]][0];
        }
        sort(que.begin(), que.end(), [=](int a, int b){
            return dep[a] > dep[b];
        });
        bool f = true;
        for(int i = 0; i < que.size() - 1; i++){
            if(!isAnc(que[i], que[i + 1])) f = false;
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}

