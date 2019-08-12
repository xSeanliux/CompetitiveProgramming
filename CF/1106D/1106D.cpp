#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 1e5 + 10;
int V, E, a, b;
vector<set<int> >adj;
vector<int> ans;
int visited[MAX_N], indexes[MAX_N];

void dfs(int currentNode){
    cout << "Running dfs(" << currentNode << "), " << ans.size() << endl;
    if(indexes[currentNode] == -1){
        ans.push_back(currentNode);
        indexes[currentNode] = ans.size();
    }
    if(adj.size() == V) return;
    for(int i : adj[currentNode]){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            visited[i] = false;
        }
    }
    return;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    adj.reserve(V + 1);
    ans.reserve(V + 1);
    cout <<"D" << endl;
    for(int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
            indexes[i] = -1;
    }
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        if(a == b || adj[a].count(b) || adj[b].count(a)) continue;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs(1);
    cout << "FIN" << endl;
    for(int i : ans){
        cout << i << endl;
    }
}
