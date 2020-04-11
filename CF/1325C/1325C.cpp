#include <iostream>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10;

int N, u, v, ans[maxN], indeg[maxN], cnt;
bool visited[maxN];
vector<pii> _adj[maxN];
pii fat[maxN];
queue<int> que;

void dfs(int p = 1, int u = 1){
    for(auto [v, id] : _adj[u]){
        if(v == p) continue;
        indeg[u]++;
        fat[v] = {u, id};
        dfs(u, v);
    }
}

int main(){
    cin >> N;
    if(N == 2){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        _adj[u].emplace_back(v, i);
        _adj[v].emplace_back(u, i);
    }
    for(int i = 1; i <= N; i++) if(_adj[i].size() > 1){
        //cout << i << " is root" << endl;
        fat[i].F = -1;
        dfs(i, i);
        break;
    }
    for(int i = 1; i <= N; i++){
        if(_adj[i].size() == 1){
            que.push(i);
        }
    }
    while(que.size()){
        int t = que.front();
        if(fat[t].F == -1) break;
        //cout << "Looking at " << t << endl;
        //cout << "father : " << fat[t].F << ", edge: " << fat[t].S << endl;
        que.pop();
        ans[fat[t].S] = cnt++;
        indeg[fat[t].F]--;
        if(!indeg[fat[t].F]) que.push(fat[t].F);
    }
    for(int i = 0; i < N - 1; i++) cout << ans[i] << endl;
}
