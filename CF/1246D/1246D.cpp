#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int n, a;

vector<int> adj[maxN], tgt, todo, tree, maxDep, dep, anc;

void getDep(int p, int x){
    maxDep[x] = dep[x] = dep[p] + 1;
    for(int u : adj[x]){
        if(u == p) continue;
        getDep(x, u);
        maxDep[x] = max(maxDep[x], maxDep[u]);
    }
}

void getTree(int p, int u){
    sort(adj[u].begin(), adj[u].end(), [](int a, int b){
        return maxDep[a] < maxDep[b];
    });
    for(int v : adj[u]){
        if(v == p) continue;
        tree.push_back(v);
        getTree(u, v);
    }
}

void getDo(int p, int u){
    while(anc[u] != tgt[u]){
        anc[u] = anc[anc[u]];
        todo.push_back(u);
    }
    for(int v : adj[u]){
        if(v == p) continue;
        getDo(u, v);
    }
}

int main(){
    ericxiao;
    cin >> n;
    maxDep.resize(n);
    dep.resize(n);
    tgt.resize(n);
    anc.resize(n);
    tgt[0] = 0;
    for(int i = 1; i < n; i++){
        cin >> a;
        tgt[i] = a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dep[0] = -1;
    getDep(0, 0);
    tree.push_back(0);
    getTree(0, 0);

    anc[0] = 0;
    //cout << "A" << endl;
    for(int i = 1; i < n; i++){
        anc[tree[i]] = tree[i - 1];
        //cout << "anc[" << tree[i] << "] = " << tree[i - 1] << endl;
    }

    getDo(0, 0);
    for(int u : tree) cout << u << " ";
    cout << todo.size() << endl;
    for(int u : todo) cout << u << " ";
}
