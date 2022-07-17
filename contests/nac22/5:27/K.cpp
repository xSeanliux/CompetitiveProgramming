#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
const int maxN = 20001;

struct Scc {
  int n, nScc, vst[maxN], bln[maxN];
  vector<int> E[maxN], rE[maxN], vec;
  void init(int _n) {
    n = _n;
    for(int i = 0; i < maxN; i++) {
      E[i].clear(); rE[i].clear();
      bln[i] = -1;
    }
  }
  void addEdge(int u, int v) {
    E[u].push_back(v);
    rE[v].push_back(u);
  }
  void dfs(int u) {
    vst[u] = 1;
    for(auto v : E[u]) if(!vst[v]) dfs(v);
    vec.push_back(u);
  }
  void rDfs(int u, int root) {
    vst[u] = 1; bln[u] = root;
    for(auto v : rE[u]) if(!vst[v]) rDfs(v, root);
  }
  void solve() {
    nScc = 0;
    vec.clear();
    fill(vst, vst + n + 1, 0);
    for(int i = 0; i < n; i++) if(!vst[i]) dfs(i);
    reverse(vec.begin(), vec.end());
    fill(vst, vst + n + 1, 0);
    for(auto v : vec) if(!vst[v]) {
      rDfs(v, v);
      nScc++;
    }
  }
} scc;
int n, m;
int in[maxN], out[maxN];
int dsu[maxN];
int cntin[maxN], cntout[maxN];
int find(int a) {
  return a == dsu[a] ? a : dsu[a] = find(dsu[a]);
}
bool merge (int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return 0;
  dsu[b] = a;
  return 1;
}
void solve() {
  cin >> n >> m;
  scc.init(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    cntin[i] = 0;
    cntout[i] = 0;
    in[i] = 0;
    out[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    scc.addEdge(a, b);
  }
  scc.solve();
  for (int i = 0; i < n; i++) {
    for (int v : scc.E[i]) {
      if (scc.bln[i]^scc.bln[v]) {
        out[scc.bln[i]]++;
        in[scc.bln[v]]++;
        merge(scc.bln[i], scc.bln[v]);
      }
    }
  }
  int res = 0;
  int comps = 0;
  for (int i = 0; i < n; i++) {
    if (i == scc.bln[i]) {
      if (out[i] == 0) {
        cntout[find(i)]++;
      }
      if (in[i] == 0) {
        cntin[find(i)]++;
      }
    }
  }
  int totin = 0;
  int totout = 0;
  for (int i = 0; i < n; i++) {
    if (i == find(i) &&  i == scc.bln[i]) {
      totin += cntin[i];
      totout += cntout[i];
      comps++;
    }
  }
  //cout << res << " " << comps << " what\n";
  if (comps == 1 && scc.nScc == 1) {
    cout << 0 << "\n";
  } else {
    cout << max(totin, totout) << "\n";
  }
}

int main() {
  int T = 1;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}