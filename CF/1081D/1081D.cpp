#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10;
vector<pii> adj[maxN];
vector<int> spe;
vector<int> dsu, sz;

inline void Merge(int a, int b);
void Flat(int x);
inline void Init();

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int U, int V, int W): u(U), v(V), w(W){}
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

vector<Edge> edges;

int n, m, k, u, v, w;

int main(){
    cin >> n >> m >> k;

    spe.resize(k);
    for(int i = 0; i < k; i++) cin >> spe[i];
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    Init();
    sort(edges.begin(), edges.end());
    for(Edge e : edges){
        Merge(e.u, e.v);
        Flat(e.u);
        Flat(e.v);
        //cout << "Merging " << e.u << " and " << e.v << endl;
        //cout << "sz[" << e.u << "] = " << sz[e.u] << endl;
        if(sz[e.u] == k || sz[e.v] == k){
            for(int i = 0; i < k; i++){
                cout << e.w << " \n"[i == k - 1];
            }
            return 0;
        }
    }
}

inline void Init(){
    dsu.resize(n + 1);
    sz.resize(n + 1);
    iota(dsu.begin(), dsu.end(), 0);
    for(int i = 1; i <= n; i++) sz[i] = 0;
    for(int v : spe) sz[v] = 1;
}

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    sz[x] = sz[dsu[x]];
    dsu[x] = dsu[dsu[x]];
}

inline void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    sz[dsu[b]] += sz[dsu[a]];
    dsu[dsu[a]] = dsu[b];
}
