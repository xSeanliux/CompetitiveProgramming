#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e3;
int N, vis[maxN + 10], deg[maxN + 10], val = 0, u, v, w;

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int s, int e, int we): u(s), v(e), w(we){}
} edges[maxN + 10];

vector<int> adj[maxN + 10];
vector<Edge> ans;
bool f = false;

int findLeaf(int p, int u){
    if(deg[u] == 1)
        return u;

    for(int v : adj[u]){
        if(v != p) return findLeaf(u, v);
    }

}

int main(){
    ericxiao;
    cin >> N;
    if(N == 2){
        cin >> u >> v >> w;
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << u << " " << v << " " << w << endl;
        return 0;
    }
    fill(deg, deg + N + 1, 0);
    for(int i = 1; i < N; i++){
        cin >> u >> v >> w;
        edges[i - 1] = Edge(u, v, w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= N; i++){
        if(deg[i] == 2){
            cout << "NO" << endl;
            return 0;
        }
    }
    Edge e;
    vector<int> leaves;
    cout << "YES" << endl;
    ans.clear();
    for(int i = 0; i < N - 1; i++){
        e = edges[i];
        leaves.clear();
        if(deg[e.u] == 1){
            for(int v : adj[e.v]){
                if(leaves.size() >= 2) break;
                if(v == e.u) continue;
                leaves.push_back(findLeaf(e.v, v));
            }
            ans.push_back(Edge(leaves[0], e.u, e.w/2));
            ans.push_back(Edge(leaves[1], e.u, e.w/2));
            ans.push_back(Edge(leaves[0], leaves[1], -e.w/2));
        } else if(deg[e.v] == 1){
            for(int v : adj[e.u]){
                if(leaves.size() >= 2) break;
                if(v == e.v) continue;
                leaves.push_back(findLeaf(e.u, v));
            }
            ans.push_back(Edge(leaves[0], e.v, e.w/2));
            ans.push_back(Edge(leaves[1], e.v, e.w/2));
            ans.push_back(Edge(leaves[0], leaves[1], -e.w/2));
        } else {
            for(int v : adj[e.v]){
                if(leaves.size() >= 2) break;
                if(v == e.u) continue;
                leaves.push_back(findLeaf(e.v, v));
            }
            for(int v : adj[e.u]){
                if(leaves.size() >= 4) break;
                if(v == e.v) continue;
                leaves.push_back(findLeaf(e.u, v));
            }
            ans.push_back(Edge(leaves[0], leaves[2], e.w/2));
            ans.push_back(Edge(leaves[1], leaves[3], e.w/2));
            ans.push_back(Edge(leaves[0], leaves[1], -e.w/2));
            ans.push_back(Edge(leaves[2], leaves[3], -e.w/2));
        }
    }
    cout << ans.size() << endl;
    for(Edge e : ans){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
}
