#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> depth, low, belong;
vector<bool> visited, isCut;
int N, M, a, b, root = 1;

void dfs1(int current, int dep){
    depth[current] = dep;
    visited[current] = true;
    isCut[current] = false;
    low[current] = dep;
    int sons = 0;
    for(int i : adj[current]){
        if(visited[i]){
            low[current] = min(low[current], depth[i]);
        } else {
            dfs1(i, dep + 1);
            low[current] = min(low[current], low[i]);
            sons++;
            if(low[i] >= depth[current]){
                isCut[current] = true;
            }
        }
    }
    if(!dep) isCut[current] = sons > 1;
}

void dfs2(int current, int ori){
    visited[current] = true;
    cout << current << " ";
    belong[current] = ori;
    for(int i : adj[current]){
        if(!visited[i]){
            if(isCut[i]){
                cout << i << " ";
            } else
            dfs2(i, ori);
        }
    }
}


int main(){
    cin >> N >> M;
    adj.resize(N);
    depth.resize(N);
    low.resize(N);
    belong.resize(N);
    visited.resize(N);
    isCut.resize(N);
    for(int i = 0; i < N; i++){
        belong[i] = i;
        visited[i] = false;
    }
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    for(int i = 0; i < N; i++){
        visited[i] = false;
        if(isCut[i]) cout << i << " is a cut vertex!" << endl;
    }
    for(int i = 0; i < N; i++){
        if(!visited[i] && !isCut[i]){
            dfs2(i, i);
            cout << endl;
        }
    }
}

