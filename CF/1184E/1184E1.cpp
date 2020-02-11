#include <iostream>
#include <queue>
#include <numeric>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;



int n, m, u, v, w;

struct Edge;

vector<int> dsu;
vector<pii> adj[(int)2e5 + 10];
vector<Edge> edges;

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int U, int V, int W): u(U), v(V), w(W){}

    bool operator<(const Edge &e) const {
        return (e.w == w) ? !(u == edges[0].u && v == edges[0].v) : w > e.w;
    }
};

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return false;
    dsu[dsu[a]] = dsu[b];
    return true;
}

bool check(int w){
    //cout << "Running check(" << w << ")" << endl;
    priority_queue<Edge> pq;
    iota(dsu.begin(), dsu.end(), 0);
    pq.push(Edge(edges[0].u, edges[0].v, w));
    for(int i = 1; i < m; i++){
        pq.push(edges[i]);
    }
    Edge e;
    while(pq.size()){
        e = pq.top();
        //cout << "e: " << e.u << ", " << e.v << ": " << e.w << endl;
        pq.pop();
        if(e.u == edges[0].u && e.v == edges[0].v){
            return Merge(e.u, e.v);
        } else {
            Merge(e.u, e.v);
        }
    }
}


int main(){
    ericxiao;
    cin >> n >> m;
    dsu.resize(n + 1);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    int l = 0, r = 1e9 + 1, m = (l + r) / 2;
    while(l + 1 < r){
        if(check(m)){
            l = m;
        } else {
            r = m;
        }
        m = (l + r) / 2;
    }

    cout << l << endl;
}

