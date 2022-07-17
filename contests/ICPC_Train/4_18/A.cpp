#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ll long long int
using namespace std;

const int maxN = 2e5 + 10;

struct Point{
  ll x, y, t;
  Point(){}
  Point(ll _x, ll _y, ll _t): x(_x), y(_y), t(_t) {}
} ch[maxN];

vector<Point> points, maxes;

Point operator-(Point &a, Point &b) {
  return Point(a.x - b.x, a.y - b.y, 0);
}

Point operator+(Point &a, Point &b) {
  return Point(a.x + b.x, a.y + b.y, 0);
}

ll operator^(Point a, Point b) {
  return a.y * b.x - a.x * b.y;
}

int main() {
  ll N, M, x, y, a, b;
  cin >> N >> M >> a >> b;
  ll mxx = 0, mxy = 0;
  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    //mxx = max(mxx, x);
    //mxy = max(mxy, y);
    //points.emplace_back(x, y, 1);
    maxes.emplace_back(x, y, 1);
  } 
  for(int i = 0; i < M; i++) {
    cin >> x >> y;
    mxx = max(mxx, x);
    mxy = max(mxy, y);
    points.emplace_back(x, y, 2);
  } 
  //points.emplace_back(mxx, 0, 0);
  points.emplace_back(0, mxy, 0);
  sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
    return (a.x == b.x) ? a.y > b.y : a.x < b.x;
  });
  sort(maxes.begin(), maxes.end(), [](const Point &a, const Point &b) {
    return a.x < b.x;
  });
  int m = 0;
  for(auto p : points) {
    
    while(m >= 2 && ((ch[m - 1] - ch[m - 2]) ^ (p - ch[m - 1])) <= 0) m--;
    ch[m++] = p; 
  }
  ch[m++] = Point(mxx, 0, 0);
  int i = 0;
  //for(int i = 0; i < m; i++) cout << ch[i].x << " " << ch[i].y << endl;
  for(auto p : maxes) {
    if(p.x >= mxx || p.y >= mxy) {
      cout << "Max\n";
      return 0;
    }
    while(i < m - 1 && ch[i + 1].x < p.x) i++;
    if(p.y >= max(ch[i].y, ch[i + 1].y)){
      cout << "Max\n";
      return 0;
    }
    if(((p - ch[i]) ^ (ch[i + 1] - p)) >= 0){
      cout << "Max\n";
      return 0;
    }
  }
  //for(int i = 0; i < m; i++) cout << ch[i].x << " " << ch[i].y << endl;
  cout << "Min\n";
}

