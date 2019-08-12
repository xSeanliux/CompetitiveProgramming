#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
LCA By Doubling
*/

int V, a, b, root, maxH;
vector<int> parent, dep;
vector<vector<int> > db, adj;
vector<bool> visited;

void dfs(int currentNode){
    visited[currentNode] = true;
    for(int i : adj[currentNode]){
        if(!visited[i]){
            dep[i] = dep[currentNode] + 1;
            maxH = max(dep[i], maxH);
            dfs(i);
        }
    }
}

int kthAncestor(int x, int k){
    int ans = x;
    for(int i = 0; i < 10; i++){
        if((1 << i) & k){
            ans = db[i][x];
        }
    }
    return ans;
}

int LCA(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    int toJump = dep[b] - dep[a];
    b = kthAncestor(b, toJump);
    if(a == b){ //one is a subtree of the other
        return a;
    }
    //now they're on the same depth, we can binary search the LCA
    int U = maxH + 1, L = -1, M = U + L >> 1;
    while(L + 1 < U){
        if(kthAncestor(a, M) == kthAncestor(b, M)) U = M;
        else L = M;
        M = U + L >> 1;
    }
    return parent[kthAncestor(a, M)];
}

int main(){
    cin >> V;
    parent.resize(V);
    adj.resize(V);
    visited.resize(V);
    int D = ceil(log2(V + 1));
    db.resize(D);
    dep.resize(V);
    db[0].resize(V);


    for(int i = 0; i < V; i++){
        cin >> parent[i];
        visited[i] = false;
        if(parent[i] == -1){
            root = i;
            db[0][i] = i;
        } else {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
            db[0][i] = parent[i];
        }
    }

    for(int i = 1; i < D; i++){
        db[i].resize(V);
        for(int j = 0; j < V; j++){
            db[i][j] = db[i-1][ db[i-1][j] ];
        }
    }

    maxH = 0;
    dep[root] = 0;
    dfs(root);

    while(cin >> a >> b){ //find LCA of a, b
        cout << LCA(a, b) << endl;
    }
}


