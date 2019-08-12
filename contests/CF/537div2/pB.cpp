#define MAXN 100000
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, m, t;
double ans, p;
double num[MAXN];

int main() {
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
  	cin >> num[i];
  }
  sort(num, num+n);
  for (int i = 0; i < n; i++) {
  	ans += num[i];
  	p += 1;
  }
  int t = min((double)m, k * p);
  ans += t;
  for (int i = 0; i < n; i++) {
  	if (p > 1 && (ans - num[i]) / (p-1) > (ans - 1) / p && m) {
  	  m--;
  	  ans -= num[i];
  	  p--;
  	  ans -= t;
  	  t = min((double)m, k * p);
  	  ans += t;
	}
  }
  ans = ans / p;
  printf("%.9lf\n", ans);
  return 0;
}
