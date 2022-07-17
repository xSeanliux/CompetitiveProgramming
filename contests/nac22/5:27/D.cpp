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

const int maxN = 1e5 + 100;

struct Point {
  int x, y;
  Point(){}
  Point(int x, int y) : x(x), y(y) {}
};

int N, m;
Point points[maxN], ch[maxN];

inline int cross(Point o, Point a, Point b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool cmp(Point a, Point b) {
  return (a.x == b.x ? a.y < b.y : a.x < b.x);
}


void getCH() {
  sort(points, points + N, cmp);
  m = 0;
  for(int i = 0; i < N; i++) {
    while(m >= 2 && cross(ch[m - 2], ch[m - 1], points[i]) <= 0) m--;
    ch[m++] = points[i];
  }
  for(int i = N - 2, lowlim = m + 1; i >= 0; i--) {
    while(m >= lowlim && cross(ch[m - 2], ch[m -1], points[i]) <= 0) m--;
    ch[m++] = points[i];
  }
  m--;
}


Point operator+(Point a, Point b) {
  return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
  return Point(a.x - b.x, a.y - b.y);
}
int operator*(Point a, Point b ){
  return (a.x * b.x) + (a.y * b.y); 
}

int dist(Point a, Point b) {
  return (a - b) * (a - b);
}

void solve() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    points[i] = Point(x, y);
  }  
  
  getCH();
  int ans = 0;
  if(m < 10) {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) {
        ans = max(dist(ch[i], ch[j]), ans);
      }
    }
  } else {
    for(int i = 0, oth = 0; i < m; i++) {
      while(dist(ch[i], ch[oth]) <= dist(ch[i], ch[(oth + 1) % m])) oth = (oth + 1) % m;
      ans = max(ans, dist(ch[i], ch[oth]));
      ans = max(ans, dist(ch[i], ch[(oth + 1) % m]));
      ans = max(ans, dist(ch[i], ch[(oth - 1 + m) % m]));
    }
  }
  cout << sqrt(ans) << endl;
}
signed main() {
  cout << fixed << setprecision(10);
  int T = 1;
  //cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}