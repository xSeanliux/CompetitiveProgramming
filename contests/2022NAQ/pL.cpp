#pragma GCC optimize("Ofast", "no-stack-protector", "no-math-errno", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2")
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int deg[maxN], N, M, u, v;
unordered_set<int> st[maxN];
vector<pii> edges;

inline int C3(int x) {
    return x * (x - 1) * (x - 2) / 6;
}

inline int C2(int x) {
    if(x < 1) return 0;
    return x * (x - 1) / 2;
}

signed main() {
    ericxiao
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        edges.emplace_back(u, v);
        st[u].insert(v);
        st[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    int ans = 0;
    for(auto [u, v] : edges) {
       ans += (deg[u] - 1) * C3(deg[v] - 1);
       ans += (deg[v] - 1) * C3(deg[u] - 1);
       int A = u, B = v, t = 0;
       if(deg[A] > deg[B]) swap(A, B);
       for(int w : st[A]) {
            t += st[B].count(w);
       }
       ans -= t * (C2(deg[u] - 2) + C2(deg[v] - 2));
    }
    cout << ans << endl;
}
