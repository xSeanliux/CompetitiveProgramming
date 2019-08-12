#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAXN = 2e5;
int N, K, D, a, b;

int deg[MAXN], parent[MAXN];
bool visited[MAXN];
vector<vector<int> >adj;
vector<pair<int, int> > ans;
queue<int> que;


void dfs(int p, int c){
    parent[c] = p;
    visited[c] = true;
    for(int i : adj[c]){
        if(!visited[i]){
            dfs(c, i);
        }
    }
}

int main(){
    cin >> N >> K >> D;
    int md = 0, mdat;
    //adj.resize(N + 1);
    adj.push_back(vector<int>());
    for(int i = 1; i <= N; i++) {
        deg[i] = 0;
        visited[i] = 0;
        adj.push_back(vector<int>());
    }
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
        if(deg[a] > md){
            md = deg[a];
            mdat = a;
        }
        if(deg[b] > md){
            md = deg[b];
            mdat = b;
        }
    }
    //bfs
    visited[1] = true;
    if(deg[1] < D){
        cout << "NO" << endl;
        return 0;
    }
    ans.clear();
    int currentDeg = 0;
    for(int i : adj[1]){
        if(!visited[i]){
            dfs(1, i);
            currentDeg++;
            if(currentDeg > D){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    //cout << "Currentdeg = " << currentDeg << endl;
    for(int i : adj[1]){
        if(currentDeg < D && parent[i] != 1){
            currentDeg++;
            parent[i] = 1;
        }
    }
    cout << "YES" << endl;
    for(int i = 2; i <= N; i++){
        cout << i << " " << parent[i] << endl;
    }
    int top;

}
