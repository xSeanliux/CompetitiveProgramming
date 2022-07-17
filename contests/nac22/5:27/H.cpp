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
const int mxN = 5001;
const ll INF = 1e18;
int n;
ll K;
ll dp[mxN][mxN]; // num subtrees with root i
vector<int> adj[mxN];
ll tot[mxN];
int sz[mxN];
void dfs(int u, int p = -1) {
  //cout << u << " " << p << endl;
  sz[u] = 1;
  //dp[u][0] = 1;
  dp[u][1] = 1;
  for (int v : adj[u]) {
    if (v^p) {
      //cout << "from " << u << " to " << v << endl;
      dfs(v, u);
      vector<ll> sv(sz[u]+sz[v]+1);
      for (int i = 1; i <= sz[u]; i++) {
        for(int j = 1; j <= sz[v]; j++) {
          if (dp[v][j] > 0 && dp[u][i] > INF / dp[v][j]) sv[i+j] = INF;
          else sv[i+j] += dp[u][i]*dp[v][j];
        }
      }
      sz[u] += sz[v];
      for (int i = 0; i <= sz[u]; i++) {
        dp[u][i] += sv[i];
        //cout << u << " " << i << " " << dp[i][i] << " dp\n";
        if (dp[u][i] > INF)dp[u][i] = INF;
      }
    }
  }
}
void solve() {
  cin >> n >> K;
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      //cout << i << " " << j << " " << dp[j][i] << " hello\n";
      K -= dp[j][i];
    }
    if (K <= 0) {
      cout << i << "\n";
      return;
    }
  }
  cout << -1 << "\n";

}
int main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}