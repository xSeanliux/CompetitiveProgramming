#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int maxN = 2e5 + 326;
int N, M, Q;

vector<int> bccadj[maxN];
int bccpar[maxN], ori[maxN], bccdep[maxN];

struct BccDSU{
    int dsu[maxN], sz[maxN], top[maxN];
    upMerge(){
        iota(dsu, dsu + maxN, 0);
        fill(sz, sz + maxN, 0);
        for(int i = 1; i <= N; i++) top[i] = i;;
    }
    void Flat(int x){
        if(x == dsu[x]) return;
        Flat(dsu[x]);
        sz[x] = sz[dsu[x]];
        top[x] = top[dsu[x]];
        dsu[x] = dsu[dsu[x]];
    }
    void Merge(int a, int b){
        Flat(a);
        Flat(b);
        a = dsu[a];
        b = dsu[b];
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        dsu[a] = dsu[b];
        top[b] = (bccdep[top[a]] < bccdep[top[b]] ? top[a] : top[b]);
        if(sz[a] == sz[b]) sz[b]++;
        Flat(a);
        Flat(b);
    } 
} bdsu;

struct BCC{
    struct DSU{
        int dsu[maxN], sz[maxN];
        DSU(){
            iota(dsu, dsu + maxN, 0);
            fill(sz, sz + maxN, 0);
        }
        void Flat(int x){
            if(x == dsu[x]) return;
            Flat(dsu[x]);
            sz[x] = sz[dsu[x]];
            dsu[x] = dsu[dsu[x]];
        }
        void Merge(int a, int b){
            Flat(a);
            Flat(b);
            a = dsu[a];
            b = dsu[b];
            if(a == b) return;
            if(sz[a] > sz[b]) swap(a, b);
            dsu[a] = dsu[b];
            if(sz[a] == sz[b]) sz[b]++;
        }
    } dsu;
    vector<int> adj[maxN];
    int belong[maxN], low[maxN], dep[maxN];
    bool vis[maxN];
    stack<int> stk;
    BCC(){
        dsu = DSU();
        vector<int>().swap(adj);
    }
    inline void addEdge(int u, int v){
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    void dfs(int p = 1, int u = 1){
        dep[u] = dep[p] + 1; 
        low[u] = dep[u];
        vis[u] = true;
        stk.push(u);
        for(int v : adj[u]) if(v != p){
            if(!vis[v]){
                dfs(u, v);
                low[u] = min(low[u], low[v]);
            } else { //found back edge
               while(stk.size()){
                  int t = stk.top(); stk.pop();
                  dsu.Merge(u, t);  
                  if(dep[t] <= dep[v]){
                      stk.push(t);
                      break;
                  }
               }
            }
        }
    }
    void getPar(int u = dsu.dsu[1]){
        bccdep[u] = bccdep[bccpar[u]] + 1;
        for(int v : bccadj[u]) if(v != bccpar[u]) {
            bccpar[v] = u;
            getPar(v);
        }
    }
    inline void run(){
        stk = stack<int>();
        fill(vis, vis + maxN, 0);
        iota(belong, belong + maxN, 0);
        dfs();
        for(int i = 1; i <= N; i++) dsu.Flat(i);
        for(int u = 1; u <= N; u++){
            for(int v : adj[u]){
                if(dsu.dsu[u] != dsu.dsu[v]){
                    bccadj[dsu.dsu[u]].push_back(dsu.dsu[v]);
                    bccadj[dsu.dsu[v]].push_back(dsu.dsu[u]);
                }
            }
        }
        getPar();
    }
} bcc;

inline bool can(int s, int t){
    s = bcc.dsu.dsu[s];
    t = bcc.dsu.dsu[t];
    if(s == t) return true;
    bdsu.Flat(s);
    bdsu.Flat(t);
    if(bdsu.dsu[s] == bdsu.dsu[t]){
        if(bccdep[s] < bccdep[t]){
            return ori[t] == 1;
        } else {
            return ori[s] == -1;
        }
    }
    t = bdsu.top[t];
    s = bdsu.top[s];
    while(s != t){
        if(bccdep[s] < bccdep[t]){
            if(ori[t] == 1) return false;
            ori[t] = -1;
            bdsu.Merge(t, bccpar[t]);
            t = bdsu.top[bccpar[t]];
        } else {
            if(ori[s] == -1) return false;
            ori[s] = 1;
            bdsu.Merge(s, bccpar[s]);
            t = bdsu.top[bccpar[s]];
        }
    }
    return true;
}

int main(){
    cin >> N >> M >> Q; 
    int u, v, s, t;
    bcc = BCC();
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        bcc.addEdge(u, v);
    }
    bcc.run();
    bdsu = BccDSU();
    bool ans = true;
    for(int i = 0; i < Q; i++){
        cin >> s >> t;
        ans &= can(s, t);
    }
    cout << (ans ? "Yes" : "No") << endl;
}
