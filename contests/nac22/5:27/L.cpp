
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
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> res;
  vector<int> arr(n+2, 0);
  vector<int> l(n+2);
  vector<int> r(n+2);
  vector<bool> done(n+2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    l[i] = i-1;
    r[i] = i+1;
  }
  vector<int> curr;
  vector<int> nxt;
  done[0] = done[n+1] = 1;
  for (int i = 1; i <= n; i++) {
    if (arr[i+1] > arr[i] || arr[i-1] > arr[i]) {
      nxt.push_back(i);
      done[i] = 1;
    }
  }
  while(!nxt.empty()) {
    res.push_back(nxt);
    for (int a : nxt) {
      curr.push_back(a);
      //cout << a << " ";
    }
    //cout << " sad" << endl;
    nxt.clear();
    for (int a : curr) {
      r[l[a]] = r[a];
      l[r[a]] = l[a];
      if (arr[r[l[a]]] > arr[l[a]] && !done[l[a]]) {
        nxt.push_back(l[a]);
        done[l[a]] = 1;
      }
      if (arr[l[r[a]]] > arr[r[a]] && !done[r[a]]) {
        nxt.push_back(r[a]);
        done[r[a]] = 1;
      }
    }
    curr.clear();
  }
  cout << res.size() << '\n';
  for (auto v : res) {
    for (auto a : v) {
      cout << arr[a] << " ";
    }
    cout << "\n";
  }
  for (int i = 1; i <= n; i++) {
    if (!done[i]) {
      cout << arr[i] << " ";
    }
  }
  cout << "\n";
}
int main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}