#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 10;

vector<int> dsu, adj[maxN], sz;
vector<bool> visited;

int n, m, q, c, a, b;

inline int div2(int a){ return (a + 1) / 2; }
void Merge(int a, int b);
void Flat(int x);

pii getFar(int p, int c){
    visited[c] = true;
    pii pp = {0, c}, pr;
    for(int u : adj[c]){
        if(u == p) continue;
        pr = getFar(c, u);
        pr.F++;
        pp = max(pp, pr);
    }
    return pp;
}


int main(){
    ericxiao;
    cin >> n >> m >> q;
    dsu.resize(n + 1);
    iota(dsu.begin(), dsu.end(), 0);
    sz.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        Merge(a, b);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            pii res = getFar(i, i);
            res = getFar(res.S, res.S);
            Flat(i);
            sz[dsu[i]] = res.F;
        }
    }
    while(q--){
        cin >> c;
        if(c == 1){ //query
            cin >> a;
            Flat(a);
            cout << sz[a] << endl;
        } else if(c == 2){ // merge
            cin >> a >> b;
            Merge(a, b);
        }
    }
}

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    sz[x] = sz[dsu[x]];
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a); Flat(b);
    if(dsu[a] == dsu[b]) return;
    sz[dsu[b]] = max(max(sz[a], sz[b]), (div2(sz[a]) + div2(sz[b]) + 1));
    dsu[dsu[a]] = dsu[b];
}
