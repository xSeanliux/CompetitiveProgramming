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
#define int long long int 
using namespace std;
using ll = long long;
mt19937 rng(0x5EED);
int n;
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}
void solve() {
  cin >> n;
  ll d;
  ll dnew;
  for (int i = 0; i < 250; i++) {
    if (n == 0)break;
    int x = randint(1, 1e6-1);
    int y = randint(1, 1e6-1);
    int ballx, bally;
    cout << x << " " << y << endl;
    cin >> d;
    if (d == 0) {
      n--;
      continue;
    }
    cout << x-1 << " " << y << endl;
    cin >> dnew;
    if (dnew == 0) {
      n--;
      continue;
    }
    ballx = (dnew - d - 1 + 2LL*x) / 2LL;
    cout << x << " " << y-1 << endl;
    cin >> dnew;
    if (dnew == 0) {
      n--; 
      continue;
    }
    bally = (dnew - d - 1 + 2LL*y) / 2LL;
    cout << ballx << " " << bally << endl;
    cin >> dnew;
    if (dnew == 0)n--;
  }
}
signed main() {
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}