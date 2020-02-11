#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5 + 10;

struct DSU{
    int dsu[maxN], sz[maxN], N;
    DSU(){}
    DSU(int n): N(n + 10){
        iota(dsu, dsu + N, 0);
        fill(sz, sz + N, 1);
    }
    void Flat(int x){
        if(dsu[x] == x) return;
        Flat(dsu[x]);
        sz[x] = sz[dsu[x]];
        dsu[x] = dsu[dsu[x]];
    }
    void Merge(int a, int b){
        Flat(a);
        Flat(b);
        if(dsu[a] == dsu[b]) return;
        sz[dsu[b]] += sz[dsu[a]];
        dsu[dsu[a]] = dsu[b];
    }
} zd, od;

vector<pii> ze, oe;
vector<int> adj[maxN];
int N, u, v, c, ans;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(c) oe.push_back({u, v});
        else ze.push_back({u, v});
    }
    zd = DSU(N);
    od = DSU(N);

    for(pii p : ze) zd.Merge(p.F, p.S);
    for(pii p : oe) od.Merge(p.F, p.S);

    for(int i = 1; i <= N; i++){
        zd.Flat(i);
        od.Flat(i);
        //cout << "i = " << i << endl;
        if(zd.dsu[i] == i){
            ans += (zd.sz[i]) * (zd.sz[i] - 1);
            //cout << "1: ans += " << (zd.sz[i]) * (zd.sz[i] - 1) << endl;
        }
        if(od.dsu[i] == i){
            ans += (od.sz[i]) * (od.sz[i] - 1);
            //cout << "2: ans += " << (od.sz[i]) * (od.sz[i] - 1) << endl;
        }
        ans += (zd.sz[i] - 1) * (od.sz[i] - 1);
        //cout << "3: ans += " << (zd.sz[i] - 1) * (od.sz[i] - 1) << endl;
    }
    cout << ans << endl;
}
