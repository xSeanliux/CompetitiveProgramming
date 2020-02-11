#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define pp pair<int, pair<int, int> >
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 3e5 + 10, INF = 1e15;

int n, m, u, v, w, a[maxN], minA = INF, minAt = -1, dsu[maxN];
vector<pp> edges;

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    dsu[dsu[a]] = dsu[b];
}

signed main(){
    ericxiao;
    cin >> n >> m;
    iota(dsu, dsu + n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(minA > a[i]){
            minA = a[i];
            minAt = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == minAt) continue;
        edges.push_back({a[i] + minA, {minAt, i}});
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(pp e : edges){
        //cout << "Looking at an edge between " << e.S.F << " and " << e.S.S << " with weight " << e.F << endl;
        Flat(e.S.F);
        Flat(e.S.S);
        if(dsu[e.S.S] == dsu[e.S.F]) continue;
        Merge(e.S.S, e.S.F);
        ans += e.F;
    }
    cout << ans << endl;
}


