#include <iostream>
#include <vector>
using namespace std;

const int maxN = 5e5 + 10;

int N, u, v;
vector<int> leaves, adj[maxN];

void dfs(int p, int u){
    if(adj[u].size() == 1) leaves.push_back(u);
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
    }
}

int main(){
    cin >> N;
    if(N == 2){
        cout << "1\n";
        cout << "1 2\n";
        return 0;
    }
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        if(adj[i].size() > 1){
            dfs(i, i);
            break;
        }
    }
    cout << (leaves.size() + 1) / 2 << endl;
    for(int i = 0; 2 * i < (int)leaves.size(); i++){
        cout << leaves[i] << " " << leaves[i + leaves.size() / 2] << endl;
    }
    //if(leaves.size() % 2) cout << leaves[0] << " " << leaves[leaves.size() - 1] << endl;
}
