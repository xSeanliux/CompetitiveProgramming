#include <iostream>
#include <vector>
using namespace std;

vector<int> colour;
int c = 0;
struct Edge{
    int u, v, id;
    bool isU;
    Edge(int u, int v, bool isU, int id): u(u), v(v), id(id), isU(isU){}
};

vector<vector<Edge> > adj;
bool canDo;
vector<bool> visited, ans;
int N, M, a, b;

void dfs(int cN, int col){
    if(!canDo) return;
    int tgt;
    for(auto e : adj[cN]){
        tgt = e.isU ? e.v : e.u;
        if(!visited[tgt]){
            colour[tgt] = (col == 1) ? 0 : 1;
            visited[tgt] = true;
            dfs(tgt, colour[tgt]);
        } else if(visited[tgt] && col == colour[tgt]){
            canDo = false;
            return;
        }
        if(colour[tgt] == 1){ //outgoing
            ans[e.id] = !e.isU;
        } else {
            ans[e.id] = e.isU;
        }
    }
}


int main(){
    cin >> N >> M;
    adj.resize(N + 1);
    colour.resize(N + 1);
    ans.resize(M + 1);
    visited.resize(N + 1);
    for(int i = 1; i <= N; i++){
        colour[i] = -1;
        visited[i] = false;
        ans[i] = -1;
    }
    canDo = true;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(Edge(a, b, true, c));
        adj[b].push_back(Edge(a, b, false, c));
        c++;
    }
    colour[1] = 0;
    visited[1] = 1;
    dfs(1, 0);
    if(canDo){
        cout << "YES" << endl;
        for(int i = 0; i < M; i++) cout << ans[i];
    } else {
        cout << "NO" << endl;
    }
}
