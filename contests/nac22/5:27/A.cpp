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
#define int long long int 
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int p10[15];

void solve() {
  double X;
  cin >> X;
  int p = round(X * 10000);
  int q = 10000;
  int g = gcd(p, q);
  if(10 * p <= q || p >= 10 * q) {
    cout << "No solution" << endl;
    return;
  }
  p /= g;
  q /= g;
  vector<int> ans = vector<int>();
  for(int x = 1; x < 10; x++) {
    if(p == q) ans.push_back(x);
  }
  for(int a = 1; a < 10; a++) {
    for(int d = 2; d <= 8; d++) {
      int P = a * p10[d - 1] * p - a * q;
      int Q = 10 * q - p;
      if(P % Q) continue;
      int B = P / Q;
      if(p10[d - 2] <= B && B < p10[d - 1]) {
        if(p * (a * p10[d - 1] + B) == q * (10 * B + a))
          ans.push_back(a * p10[d - 1] + B);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(int x : ans) cout << x << endl;
  if(!ans.size()) {
    cout << "No solution" << endl;
  }
}
signed main() {
  p10[0] = 1;
  for(int i = 1; i < 15; i++ ) p10[i] = 10 * p10[i - 1];
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}