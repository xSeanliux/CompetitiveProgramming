#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxN = 2e5;

int N, M, aSz = 0, bSz = 0, pSz = 0;
vector<int> adj[maxN];
bool A[maxN], B[maxN], P[maxN], vis[maxN], found = false;

void dfs(int u) {
  if(found) return;
  aSz--;
  pSz++;
  P[u] = 1;
  A[u] = 0;
  if(aSz == bSz) {
    found = true;
    return;
  }
  vis[u] = true;
  for(int v : adj[u]) if(!vis[v]) {
    dfs(v);
    if(found) return;
  }
  pSz--;
  bSz++;
  P[u] = 0;
  B[u] = 1;
  if(aSz == bSz) {
    found = true;
  }
}

int main() {
  cout << "A" << endl;
  cin >> N >> M;
  aSz = N;
  fill(A, A + N + 1, 1);
  for(int i = 0; i < M; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  vector<int> ps = vector<int>();
  for(int i = 1; i <= N; i++) if(P[i]) ps.push_back(i);
  cout << ps.size() << " " << (N - ps.size()) / 2 << endl;
  for(int x : ps) cout << x << " "; cout << endl;
}