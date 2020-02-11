#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 10;

int n, m, u, v, w, q, dsu[maxN], sz[maxN], cc = 0;

struct Edge{
    int u, v, w;
    Edge(int uu, int vv, int ww): u(uu), v(vv), w(ww){}
    Edge(){}
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

vector<Edge> edges;
vector<pii> queries;
deque <pii> qs;
vector<int> ans;

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
    sz[x] = sz[dsu[x]];
}

void Merge(int a, int b){
    Flat(a), Flat(b);
    if(dsu[a] == dsu[b]) return;
    cc -= (sz[dsu[a]] * (sz[dsu[a]] - 1) / 2 + sz[dsu[b]] * (sz[dsu[b]] - 1) / 2);
    sz[dsu[a]] += sz[dsu[b]];
    dsu[dsu[b]] = dsu[a];
    cc += (sz[dsu[a]] * (sz[dsu[a]] - 1)) / 2;
}


signed main(){
    ericxiao;
    cin >> n >> m;
    edges.resize(n);
    queries.resize(m);
    ans.resize(m);
    edges[0] = Edge(0, 0, 0);
    for(int i = 1; i < n; i++){
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < m; i++){
        cin >> q;
        queries[i] = {q, i};
    }
    sort(queries.begin(), queries.end());
    for(pii p : queries){
        qs.push_back(p);
    }
    iota(dsu, dsu + n + 10, 0);
    fill(sz, sz + n + 10, 1);
    for(int i = 0; i <= n - 1; i++){
        //cout << i << endl;
        int cw = edges[i].w, nw;
        while(i <= n - 1 && edges[i].w == cw){
            Merge(edges[i].u, edges[i].v);
            i++;
        }
        if(i == n){
            nw = maxN;
        } else {
            nw = edges[i].w;
        }
        i--;
        while(qs.size() && qs.front().F < nw){
            ans[qs.front().S] = cc;
            qs.pop_front();
        }
    }
    while(qs.size()){
        ans[qs.front().S] = cc;
        qs.pop_front();
    }

    for(int i = 0; i < m; i++){
        cout << ans[i] << " \n"[i == m-1];
    }




}
