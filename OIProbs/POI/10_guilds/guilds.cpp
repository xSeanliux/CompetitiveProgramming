#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 10, maxM = 5e5 + 10;
vector<int> adj[maxN];

int N, M, u, v, dep[maxN];

void dfs(int p, int u){
    dep[u] = dep[p] + 1;
    for(int v : adj[u]) if(!dep[v]) dfs(u, v);
}

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) if(!dep[i]) dfs(i, i);
    //for(int i = 1; i <= N; i++)
    //    cout << "dep[" << i << "] = " << dep[i] << endl;
    for(int i = 1; i <= N; i++){
        //cout << "dep[" << i << "] = " << dep[i] << endl;
        int msk = 0;
        if((dep[i] & 1) == 0) msk |= 1;
        if((dep[i] & 1) == 1) msk |= 2;
        for(int v : adj[i]){
            if((dep[v] & 1) == 0) msk |= 1;
            if((dep[v] & 1) == 1) msk |= 2;
        }
        if(msk != 3){
            cout << "NIE" << endl;
            return 0;
        }
    }
    cout << "TAK" << endl;
    for(int i = 1; i <= N; i++){
        cout << (dep[i] & 1 ? 'K' : 'S') << endl;
    }
    cout << endl;
}
