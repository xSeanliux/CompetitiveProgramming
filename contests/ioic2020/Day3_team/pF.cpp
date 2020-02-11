#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int kN = 2e5 + 10, maxE = 5e5 + 10;

vector<int> g[kN], adj[kN];
vector<pii> edges, oriadj[kN];
stack<int> stk;

int dep[kN], low[kN], bcc[kN], nbcc, bccdep[kN], bccroot, leaves;
bool visited[kN], isDone[kN], doneEdge[maxE];

void TarjanDfs(int v, int p){
    stk.push(v);
    visited[v] = true;
    low[v] = dep[v] = ~p ? dep[p] + 1 : 0;
    for(int u : g[v]){
        if(u == p) continue;
        if(visited[u]){
            low[v] = min(low[v], dep[u]);
        } else {
            TarjanDfs(u, v);
            low[v] = min(low[v], low[u]);
        }
    }
    if(low[v] == dep[v]){
        while(!stk.empty()){
            int x = stk.top();
            stk.pop();
            bcc[x] = nbcc;
            if(x == v) break;
        }
        nbcc++;
    }
}

void getbccdep(int p, int u){
    bccdep[u] = bccdep[p] + 1;
    for(int v : adj[u]){
        if(v == p) continue;
        getbccdep(u, v);
    }
}

void orient(int p, int u){
    //cout << "am now at" << u << endl;
    visited[u] = true;
    for(pii e : oriadj[u]){
        //cout << u << " looking at " << e.F << endl;
        if(bcc[u] != bcc[e.F]) continue;
        if(!visited[e.F]){
            if(!doneEdge[e.S]){
                edges[e.S] = {u, e.F};
                //cout << u << " " << e.F << endl;
                doneEdge[e.S] = true;
            }
            orient(u, e.F);
        } else {
            if(!doneEdge[e.S]){
                //cout << u << " " << e.F << endl;
                edges[e.S] = {u, e.F};
                doneEdge[e.S] = true;
            }
        }
    }
}

int N, M, u, v;

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        oriadj[u].emplace_back(v, i);
        oriadj[v].emplace_back(u, i);
        edges.emplace_back(u, v);
    }
    TarjanDfs(1, 1);
    /*
    for(int i = 1; i <= N; i++){
        cout << bcc[i] << " ";
    }
    cout << endl;
    */
    for(pii e : edges){
        if(bcc[e.F] != bcc[e.S]){
            adj[bcc[e.F]].push_back(bcc[e.S]);
            adj[bcc[e.S]].push_back(bcc[e.F]);
        }
    }
    for(int i = 0; i < nbcc; i++){
        if(adj[i].size() == 1){
            bccroot = i;
            leaves++;
        }
    }
    bccdep[bccroot] = 0;
    getbccdep(bccroot, bccroot);
    for(auto &p : edges){ //orient tree edges
        if(bccdep[p.F] > bccdep[p.S]) swap(p.F, p.S);
    }
    fill(visited, visited + N + 1, 0);
    fill(doneEdge, doneEdge + M, 0);
    for(int i = 1; i <= N; i++){
        if(!isDone[bcc[i]]){ //orient the bcc
            //cout << "Orienting " << bcc[i] << " at " << i << endl;
            orient(i, i);
            isDone[bcc[i]] = true;
        }
    }
    //cout << "Done" << endl;
    if(nbcc == 1) cout << 0 << endl;
    else cout << leaves - 1 << endl;
    for(pii p : edges){
        cout << p.F << " " << p.S << "\n";
    }
    fill(isDone, isDone + nbcc, 0);
    int rootat;
    for(int i = 1; i <= N; i++){
        rootat = i;
        if(bcc[rootat] == bccroot) break;
    }
    //cout << "bccroot = " << bccroot << endl;
    if(nbcc > 1){
        for(int i = 1; i <= N; i++){
            if(adj[bcc[i]].size() == 1 && !isDone[bcc[i]] && bcc[i] != bccroot){
                cout << i << " " << rootat << '\n';
                isDone[bcc[i]] = true;
            }
        }
    }

}
