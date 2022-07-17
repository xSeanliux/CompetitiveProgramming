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
#include <random>
#include<array>
#define int long long int 
using namespace std;
using ll = long long;
mt19937 rng(0x5EED);
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}
struct Dag{
  int n;
  vector<vector<int> > g;
  Dag(int n) : n(n), g(n){}
  void add_edge(int u,int v){
    //cout<<u<<" "<<v<<" edge\n";
    g[u].push_back(v);
  }
  vector<bool> vis;
  vector<int> top_sort;
  void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(auto &v : g[u]){
      dfs(v);
    }
    top_sort.push_back(u);
  }
  vector<int> topo_sort(){
    vis.assign(n, 0);
    top_sort.clear();
    for(int i=0;i<n;i++){
      if(!vis[i]) dfs(i);
    }
    reverse(top_sort.begin(), top_sort.end());
    return top_sort;
  }
};
void solve() {
  int n;
  cin>>n;
  map<int, vector<int> > to_add;
  vector<array<int, 4> > segs(n);
  for(auto &[x1, y1, x2, y2] : segs){
    cin>>x1>>y1>>x2>>y2;
    if(x1 > x2){
      swap(x1, x2);
      swap(y1, y2);
    }
  }
  for(int i=0;i<n;i++){
    auto [x1, y1, x2, y2] = segs[i];
    to_add[x1].push_back(i+1);
    to_add[x2].push_back(-i-1);
  }
  auto y_value_at_x = [&](int seg_id, int x){
    auto [x1, y1, x2, y2] = segs[seg_id];
    return y1 + (y2 - y1) * 1.0L / (x2 - x1) * (x - x1);
  };
  int curr_x = -1e7;
  auto cmp = [&](int i,int j){
    return y_value_at_x(i, curr_x) > y_value_at_x(j, curr_x);
  };
  Dag dag(n);
  set<int, decltype(cmp)> seg_set(cmp);
  for(auto &[x, v] : to_add){
    curr_x = x;
    sort(v.begin(), v.end(), greater<int>());
    for(auto &i : v){
      if(i < 0){
        seg_set.erase(-i-1);
      }
      else{
        seg_set.insert(i-1);
        //cout<<i-1<<" added\n";
        //for(auto &x : seg_set) cout<<x<<" ";
        //cout<<"in set\n";
        auto it = seg_set.find(i-1);
        if((next(it)) != seg_set.end()){
          dag.add_edge(i-1, *next(it));
        }
        if(it != seg_set.begin()){
          dag.add_edge(*prev(it), i-1);
        }
      }
    }
  }
  vector<int> ord = dag.topo_sort();
  int x0;
  cin>>x0;
  //for(auto &x : ord) cout<<x<<" ";
  //cout<<"\n";
  for(auto &i : ord){
    auto [x1, y1, x2, y2] = segs[i];
    if(x0 < x1 || x0 > x2) continue;
    if(y1 < y2){
      x0 = x1;
    }
    else{
      x0 = x2;
    }
  }
  cout<<x0<<"\n";
}
signed main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}