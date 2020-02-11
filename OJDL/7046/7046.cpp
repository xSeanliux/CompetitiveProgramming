#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10, maxLog = 18;

pii anc[maxN][maxLog];
int dep[maxN];

vector<pii> vec[maxN];

void dfs(int p, int u){
    dep[u] = dep[p] + 1;
    anc[u][0].F = p;
    for(int i = 1; i < maxLog; i++){
        anc[u][i].F = anc[anc[u][i - 1].F][i - 1].F;
        anc[u][i].S = anc[u][i - 1].S ^ anc[anc[u][i - 1].F][i - 1].S;
    }
    //cout << "For Node " << u << ": " << endl;
    //for(int i = 0; i< 3; i++){
    //    cout << anc[u][i].F << " " << anc[u][i].S << endl;
    //}
    //cout << endl;
    for(pii e : vec[u]){
        if(e.F == p) continue;
        anc[e.F][0].S = e.S;
        dfs(u, e.F);
    }
}

inline pii getKth(int x, int k){
    int xorval = 0;
    for(int i = maxLog; i >= 0; i--){
        if(k & (1 << i)){
            xorval ^= anc[x][i].S;
            x = anc[x][i].F;
        }
    }
    return {x, xorval};
}

inline int solve(int a, int b){
    if(dep[a] > dep[b]) swap(a, b); //dep[a] <= dep[b]
    //cout<< "Solving " << a << ", " << b << endl;
    int ap = 0, bp = 0;
    pii p = getKth(b, dep[b] - dep[a]);
    //cout << "Lifting p up by " << dep[b] - dep[a] << endl;
    b = p.F, bp = p.S;
    //cout << "res = newnode = " << p.F << ", xorpath = " << p.S << endl;
    if(a == b) return bp;
    for(int i = maxLog - 1; i >= 0; i--){
        if(anc[a][i].F != anc[b][i].F){
            //cout << "Lifting by "
            ap ^= anc[a][i].S;
            bp ^= anc[b][i].S;
            a = anc[a][i].F;
            b = anc[b][i].F;
        }
    }
    //cout << "a = " << a << ", b = " << b << endl;
    return ap ^ bp ^ anc[a][0].S ^ anc[b][0].S;
}

int N, Q, u, v, w;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    dep[1] = 0;
    dfs(1, 1);
    cin >> Q;
    while(Q--){
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}
