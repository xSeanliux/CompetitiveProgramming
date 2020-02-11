#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define piii pair<int, pii>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e5 + 10;

unordered_map<int, vector<pii> > adj;
vector<pii> edges;
vector<piii> ans; //<a, b> ; <id, isReversed>
unordered_map<int, bool> visited;
int t, n, a, b, ccnt;

pii dfs(int p, int u){
    //cout << "Running dfs(" << p << ", " << u << ")" << endl;
    visited[u] = true;
    if(adj[u].size() == 1 && visited[p]){
        return {adj[u][0].S, (edges[adj[u][0].S].F == u)};
    }
    pii res;
    bool hasMet = false;
    for(pii e : adj[u]){
        if(e.F == p && !hasMet){
            hasMet = true;
            continue;
        }
        if(visited[e.F]){
            res = {e.S, 0};
            continue;
        }
        res = dfs(u, e.F);
    }
    return res;
}

int main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n;
        adj.clear();
        ans.clear();
        visited.clear();
        edges.resize(n);
        for(int i = 0; i < n; i++){
            cin >> edges[i].F >> edges[i].S;
            adj[edges[i].F].push_back({edges[i].S, i});
            adj[edges[i].S].push_back({edges[i].F, i});
            visited[edges[i].F] = false;
            visited[edges[i].S] = false;
        }
        ccnt = 0;
        pii edg;
        piii _ans;
        for(auto p : adj){
            if(!visited[p.F]){
                if(ccnt){
                    _ans.F = edg.F;
                    _ans.S.F = (edg.S ? edges[edg.F].F : edges[edg.F].S);
                    _ans.S.S = p.F;
                    ans.push_back(_ans);
                }
                ccnt++;
                edg = dfs(-1, p.F);
            }
        }
        cout << ans.size() << endl;
        for(auto p : ans){
            cout << p.F + 1 << " " << p.S.F << " " << p.S.S << endl;
        }
    }
}
