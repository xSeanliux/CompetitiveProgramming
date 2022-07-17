#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxN = 3e5;

int N, M, aSz = 0, bSz = 0;
vector<int> adj[maxN];
bool A[maxN], B[maxN], vis[maxN], found = false;
stack<int> stk;
void dfs(int u = 1) {
  if(found) return;
  aSz--;
  stk.push(u);
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
  bSz++;
  stk.pop();
  B[u] = 1;
  if(aSz == bSz) {
    found = true;
  }
}

int main() {
  cin >> N >> M;
  aSz = N;
  fill(A, A + N + 1, 1);
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  cout << stk.size() << " " << (N - stk.size()) / 2 << endl;
  while(stk.size()) {
    cout << stk.top() << " ";
    stk.pop();
  }
  cout << endl;
  for(int i = 1; i <= N; i++) if(A[i]) cout << i << " "; cout << endl;
  for(int i = 1; i <= N; i++) if(B[i]) cout << i << " "; cout << endl;
}