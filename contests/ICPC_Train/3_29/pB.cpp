#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <math.h>
#include <iomanip>
#define pii pair<int,int>
#define F firt
#define S second
#define second
#define int long long int
using namespace std;

struct Point {
  double x, y, z;
  Point(){}
  Point(double x, double y, double z): x(x), y(y), z(z){}
  double len() {
    return sqrt(x * x + y * y + z * z);
  }
};

Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point Cross(const Point &a, const Point &b) {
  return Point( 
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  );
}



struct Polygon {
  int N;
  vector<Point> vertices;
  Polygon(): N(0) {
    vector<Point>().swap(vertices);
  }
  void addPoint(double x, double y, double z) {
    N++;
    vertices.emplace_back(x, y, z);
  }
  
  double getTetra(double x, double y, double z) {
    double ans = 0;
    Point O = Point(x, y, z);
    for(int i = 1; i < N - 1; i++) {
      Point A = vertices[0] - O, B = vertices[i] - O, C = vertices[i + 1] - O;
      ans += abs(dot(Cross(A, B), C)) / 6;
    }
    return ans;
  }
};

inline double solve() {
  int F;
  cin >> F;
  vector<Polygon> faces = vector<Polygon>();
  double x, y, z;
  for(int i = 0; i < F; i++) {
    int V;
    cin >> V;
    Polygon poly = Polygon();
    for(int j = 0; j < V; j++) {
      cin >> x >> y >> z;
      poly.addPoint(x, y, z);
    }
    faces.push_back(poly);
    //cout << "face " << i << endl;
  }
  double ans = 0;
  for(auto face : faces) {
    ans += face.getTetra(x, y, z);
  }
  return ans;
}

signed main() {
  int T;
  cin >> T;
  double ans = 0;
  while(T--) {
    ans += solve();
  }
  cout << fixed << setprecision(2) << ans << endl;
}