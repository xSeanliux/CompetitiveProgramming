
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
  string s, t;
  cin >> s >> t;
  if(s == t) {
    cout << 0 << endl;
    return;
  }
  bool hasSwap = 0;
  if(s.length() > t.length()) {
    hasSwap = 1;
    swap(s, t);
  }
  int N = s.length(), M = t.length();
  int l = 0, r = -1;
  while(l < N && s[l] == t[l]) l++;
  while(r >= -N && s.end()[r] == t.end()[r]) r--;
  //cout << "l = " << l << ", r = " << r << endl;
  if(hasSwap) {
    if(l - (r + 1) >= N) {
      cout << 0 << endl;
    } else {
      cout <<  N - l + r + 1 << endl;
    }
  } else {
    if(l - (r + 1) >= N) {
      cout << M - N << endl;
    } else {
      cout <<  M - l + r + 1 << endl;
    }
  }
}
int main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}