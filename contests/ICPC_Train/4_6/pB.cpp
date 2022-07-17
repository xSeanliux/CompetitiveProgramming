#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#define F first
#define S second
using namespace std;

const int maxN = 2e3 + 10;
vector<int> adj[maxN];
stack<pair<int*, int> > stk;
int color[maxN], N, M, can[maxN];
bool adm[maxN][maxN];

void undo() {
  while(stk.size()) {
    auto [a, b] = stk.top();
    stk.pop();
    *a = b;
  }
}

void reset() {
  stk = stack<pair<int*, int> >();
}

bool runCol(int x) {
  //cout << "coloring " << x << ": " << color[x] << endl;
  for(int v : adj[x]) {
    stk.emplace(&can[v], can[v]);
    can[v] &= 14 - (1 << color[x]);
  }
  for(int v : adj[x]) {
    if(color[v] == -1) {
      //cout << "can[" << v << "] = " << can[v] << endl;
      if(can[v] == 0) return false;
      for(int i = 1; i <= 3; i++) {
        if((can[v] >> i) & 1) {
          stk.emplace(&color[v], color[v]);
          color[v] = i;
          if(!runCol(v)) return false;
        }
      }
    } else if(color[v] == color[x]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adm[u][v] = adm[v][u] = 1;
  }
  for(int i = 1; i <= N; i++) for(int j = 1; j < i; j++) if(!adm[i][j]) {
    adj[i].push_back(j);
    adj[j].push_back(i);
    //cout << "adding: " << i << " " << j << endl;
  }
  fill(can, can + N + 1, 14);
  fill(color, color + N + 1, -1);
  color[1] = 1;
  color[2] = 2;
  for(int v : adj[1]) can[v] ^= (1 << 1);
  for(int v : adj[2]) can[v] ^= (1 << 2);
  //for(int i = 1; i <= N; i++) cout << can[i] << endl;
  for(int i = 3; i <= N; i++) if(can[i] == 8) {
    color[i] = 3;
    //cout << "color[" << i << "] = " << 3 << endl;
    if(!runCol(i)) {
      cout << "impossible\n";
      return 0;
    }
    reset();
  }
  for(int i = 3; i <= N; i++) if(color[i] == -1) {
    if(can[i] == 0) {
      cout << "impossible\n";
      return 0;
    }
    for(int j = 1; j <= 3; j++) {
      if((can[i] >> j) & 1) {
        stk.emplace(&color[i], color[i]);
        color[i] = j;
        if(!runCol(i)){
          undo();
        }
      }
    }
    if(color[i] == -1) {
      cout << "impossible\n";
      return 0;
    }
    reset();
  }
  //output answer
  for(int i = 1; i <= N; i++) if(color[i] == 1) cout << i << " ";
  cout << endl;
  for(int i = 1; i <= N; i++) if(color[i] == 2) cout << i << " ";
  cout << endl;
}