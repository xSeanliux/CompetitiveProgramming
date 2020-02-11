#include <iostream>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


const int maxN = 4e5 + 10;
int n, m, a, b, largest = 0, largestAt;

vector<pii> adj[maxN];
vector<pii> edges, ansedges;
vector<bool> visited;
vector<int> low, dep, edgeStatus; //0: tree edge, 1: bridge, 2: backedge

void getBridge(int p, int c){
    dep[c] = dep[p] + 1;
    low[c] = dep[c];
    visited[c] = true;
    for(pii e : adj[c]){
        if(e.F == p) continue;
        if(!visited[e.F]){
            getBridge(c, e.F);
        } else {
            edgeStatus[e.S] = 2;
        }
        low[c] = min(low[c], low[e.F]);
        if(low[e.F] > dep[c]) edgeStatus[e.S] = 1;
        if(edgeStatus[e.S] != 1 && ansedges[e.S].F == -1){
            ansedges[e.S] = {c, e.F};
            //cout << "Orienting: " << c << " to " << e.F << endl;
        }


    }
}

int getBiggestBCC(int c){
    int res = 1;
    visited[c] = true;
    for(pii e : adj[c]){
        if(visited[e.F] || edgeStatus[e.S] == 1) continue;
        res += getBiggestBCC(e.F);
    }
    return res;
}

void orientBridges(int c){
    visited[c] = true;
    for(pii e : adj[c]){
        if(visited[e.F]) continue;
        if(edgeStatus[e.S] == 1){
            ansedges[e.S] = {e.F, c};
        }
        orientBridges(e.F);
    }
}

int main(){
    ericxiao;
    cin >> n >> m;
    edgeStatus.resize(m);
    edges.resize(m);
    ansedges.resize(m);
    low.resize(n);
    dep.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    fill(edgeStatus.begin(), edgeStatus.end(), 0);
    for(auto &p : ansedges){
        p = {-1, -1};
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    getBridge(0, 0);
    //for(int i : edgeStatus){
    //    cout << i;
    //}
    cout << endl;
    fill(visited.begin(), visited.end(), false);
    int _s;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            _s = getBiggestBCC(i);
            if(_s > largest){
                largest = _s;
                largestAt = i;
            }
        }
    }
    cout << largest << endl;
    fill(visited.begin(), visited.end(), false);
    orientBridges(largestAt);
    for(pii e : ansedges){
        cout << e.F + 1 << " " << e.S + 1 << endl;
    }
}
