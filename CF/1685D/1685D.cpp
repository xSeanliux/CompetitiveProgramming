#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MinCostMaxFlow{
  typedef int Tcost;
  static const int MAXV = 500;
  static const int INFf = 1000000;
  static const Tcost INFc = 1e9;
  struct Edge{
    int v, cap;
    Tcost w;
    int rev;
    Edge(){}
    Edge(int t2, int t3, Tcost t4, int t5)
    : v(t2), cap(t3), w(t4), rev(t5) {}
  };
  int V, s, t;
  vector<Edge> g[MAXV];
  void init(int n){
    V = n+2;
    s = n+1, t = n+2;
    for(int i = 0; i <= V; i++) g[i].clear();
  }
  void addEdge(int a, int b, int cap, Tcost w){
    g[a].push_back(Edge(b, cap, w, (int)g[b].size()));
    g[b].push_back(Edge(a, 0, -w, (int)g[a].size()-1));
  }
  Tcost d[MAXV];
  int id[MAXV], mom[MAXV];
  bool inqu[MAXV];
  queue<int> q;
  Tcost solve(){
    int mxf = 0; Tcost mnc = 0;
    while(1){
      fill(inqu, inqu+1+V, 0);
      fill(mom, mom+1+V, -1);
      fill(d, d+1+V, 1e9);
      mom[s] = s;
      d[s] = 0;
      q.push(s); inqu[s] = 1;
      while(q.size()){
        int u = q.front(); q.pop();
        inqu[u] = 0;
        for(int i = 0; i < (int) g[u].size(); i++){
          Edge &e = g[u][i];
          int v = e.v;
          if(e.cap > 0 && d[v] > d[u]+e.w){
            d[v] = d[u]+e.w;
            mom[v] = u;
            id[v] = i;
            if(!inqu[v]) q.push(v), inqu[v] = 1;
          }
        }
      }
      if(mom[t] == -1) break ;
      int df = INFf;
      for(int u = t; u != s; u = mom[u])
        df = min(df, g[mom[u]][id[u]].cap);
      for(int u = t; u != s; u = mom[u]){
        Edge &e = g[mom[u]][id[u]];
        e.cap             -= df;
        g[e.v][e.rev].cap += df;
      }
      mxf += df;
      mnc += df*d[t];
    }
    return mnc;
  }
} flow;


inline int Abs(int x) {
    return x < 0 ? -x : x;
}

inline void solve() {
    int N;
    cin >> N;
    vector<int> ans = vector<int>(N), p = vector<int>(N + 1);
    for(int i = 1; i <= N; i++) cin >> p[i];
    flow.init(2 * N);
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) if(i != j) {
        flow.addEdge(i, j + N, 1, Abs(i - p[j]));
    }
    for(int i = 1; i <= N; i++) {
        flow.addEdge(flow.s, i, 1, 0);
        flow.addEdge(i + N, flow.t, 1, 0);
    }
    int mc = flow.solve();
    cout << "mc = " << mc << endl;
    ans[0] = 1;
    auto disp = [&]() {
        for(int i = 1; i <= N; i++) {
            for(auto E : flow.g[i]) {
                if(E.cap == 0) { 
                    cout << i << " " << E.v - N << " " << E.w << endl;
                }
            }
        }
    };
    disp();
    auto check = [&](int id, int rl, int tgt) {
        flow.init(2 * N); 
        for(int i = 0; i < id - 1; i++) {
            flow.addEdge(ans[i], ans[i + 1] + N, 1, Abs(ans[i] - p[ans[i + 1]]));
        }
        for(int i = 1; i <= rl; i++) {
            flow.addEdge(ans[id - 1], i + N, 1, Abs(ans[id - 1] - p[i]));
        }
        for(int i = 1; i <= N; i++) if(flow.g[i].size() == 0) {
            for(int j = 1; j <= N; j++) {
                if(i != j) flow.addEdge(i, j + N, 1, Abs(i - p[j]));
            }
        }
        for(int i = 1; i <= N; i++) {
            flow.addEdge(flow.s, i, 1, 0);
            flow.addEdge(i + N, flow.t, 1, 0);
        }
        int F = flow.solve();
        disp();
        cout << "Flow of id = " << id << ", rl = " << rl << " = " << F << endl;
        return F == tgt;
    };
    for(int i = 1; i < N; i++) {
        int l = 0, r = N, m;
        while(r - l > 1) {
            m = (l + r) / 2;
            if(check(i, m, mc)) r = m;
            else l = m;
        }
        ans[i] = r;
    }
    for(int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
