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
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;
  bool f = 1;
  for(int i = 0; i < s.length(); i++) {
    f &= (s[i] == t[i]) ^ (N & 1);
  }
  if(f) {
    cout << "Deletion succeeded" << endl;
  } else {
    cout << "Deletion failed" << endl;
  }
}
int main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}