#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

vector<vector<int> > adj, sparse;
vector<int> dep, ord, pos, reds, minDist;

int N, M, a, b;

void dfs(int p, int c){
    //cout << "DFS(" << p << ", " << c << ")" << endl;
    dep[c] = dep[p] + 1;
    pos[c] = ord.size();
    ord.push_back(c);
    for(int u : adj[c]){
        if(u == p) continue;
        dfs(c, u);
        ord.push_back(c);
    }
    if(adj[c].size() == 1) ord.push_back(c);
}

const int INF = 1e7, blockSize = 350;

void initSparse(){
    int l = ord.size();
    sparse.push_back(vector<int>());
    sparse[0].resize(l);
    for(int i = 0; i < l; i++){
        sparse[0][i] = dep[ord[i]];
    }
    //cout << "H" << endl;
    for(int i = 1; (1LL << i) <= l; i++){
        sparse.push_back(vector<int>());
        sparse[i].resize(l);
        for(int j = 0; j < (1LL << i) - 1; j++) sparse[i][j] = INF;
        for(int j = (1LL << i) - 1; j < l; j++){
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j - (1LL << (i - 1))]);
        }
    }
}

int query(int l, int r){
    if(l > r) swap(l, r);
    if(l == r) return sparse[0][l];
    int k = floor(log2(r - l + 1));
    if((1LL << (k + 1)) < (r - l + 1)) k++;
    return min(sparse[k][r], sparse[k][l + (1 << k) - 1]);
}

int dist(int a, int b){
    return dep[a] + dep[b] - 2 * query(pos[a], pos[b]);
}

void update_reds(){ //BFS
    vector<bool> visited;
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    queue<int> que;
    for(int u : reds){
        que.push(u);
        minDist[u] = 0;
    }
    int t;
    while(que.size()){
        t = que.front();
        que.pop();
        for(int v : adj[t]){
            if(!visited[v]){
                visited[v] = true;
                minDist[v] = min(minDist[v], minDist[t] + 1);
                //cout << v << " has been updated to " << minDist[v] << endl;
                que.push(v);
            }
        }
    }
}


int main(){
    ericxiao;
    cin >> N >> M;
    adj.resize(N + 1);
    pos.resize(N + 1);
    minDist.resize(N + 1);
    dep.resize(N + 1);
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dep[1] = 0;
    dfs(1, 1);
    initSparse();
    for(int i = 2; i <= N; i++){
        minDist[i] = dist(i, 1);
    }
    /*
    cout << endl << endl;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dist(i, j) << " ";
        }
        cout << endl;
    }
    */
    while(M--){
        cin >> a >> b;
        if(a == 1){
            reds.push_back(b);
        } else {
            for(int u : reds){
                minDist[b] = min(minDist[b], dist(u, b));
                //cout << "dist(" << u << ", " << b << ") = " << dist(u, b) <<endl;
            }
            cout << minDist[b] << endl;
        }
        if(!(reds.size() % blockSize) || !M){
            update_reds();
            reds.clear();
        }
    }

}
