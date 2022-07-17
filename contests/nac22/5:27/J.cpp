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
using ll = long long;
const int mxN = 200001;
const ll INF = 1e18;
int n;
int arr[mxN];
vector<int> adj[mxN];
int par[mxN][20];
int h[mxN];
void dfs(int u, int p = -1) {
  for (int v : adj[u]) {
    if (v^p) {
      h[v] = h[u]+1;
      par[v][0] = u;
      dfs(v, u);
    }
  }
}
int walk (int a, int dist) {
  for (int lg = 19; lg >= 0; lg--) {
    if (dist & (1<<lg)) a = par[a][lg];
  }
  return a;
}
int lca(int a, int b) {
  if (h[a] < h[b]) {
    b = walk(b, h[b] - h[a]);
  } else if (h[a] > h[b]) {
    a = walk(a, h[a] - h[b]);
  }
  if (a == b) return a;
  for (int lg = 19; lg >= 0; lg--) {
    if (par[a][lg] != par[b][lg]) {
      a = par[a][lg];
      b = par[b][lg];
    }
  }
  return par[a][0];
}
void solve() {
  cin >> n;
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0);
  for (int lg = 1; lg < 20; lg++) {
    for (int i = 0; i < n; i++) {
      par[i][lg] = par[par[i][lg-1]][lg-1];
    }
  }
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2*i; j <= n; j += i) {
      res += h[i-1] + h[j-1] - 2*h[lca(i-1, j-1)]+1;
    }
  }
  cout << res << "\n";
}
int main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}