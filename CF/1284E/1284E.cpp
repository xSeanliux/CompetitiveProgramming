#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>
#include <set>
#include <unordered_map>
#define int long long int
using namespace std;

const int maxN = 3e3 + 10, INF = 1e9;

struct Point {
    int x, y;
    Point(){}
    Point(int x_, int y_): x(x_), y(y_) {}
    inline bool district() const {
        if(y != 0) return y < 0;
        return x < 0; 
    }
};

inline int operator^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

inline int operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

inline Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

inline Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

int N, ans;
vector<Point> points;

int C(int n, int k) {
    if(n <= 0) return 0;
    int res = 1;
    for(int i = n - k + 1; i <= n; i++) res *= i;
    for(int i = 2; i <= k; i++) res /= i;
    return res;
}

signed main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    ans = C(N, 5) * 5;
    //cout << "ans = " << ans << endl;
    for(int i = 0; i < N; i++) {
        vector<Point> npoints = vector<Point>();
        for(int j = 0; j < N; j++) if(i != j) {
            npoints.push_back(points[j] - points[i]);
        }
        sort(npoints.begin(), npoints.end(), [](const Point a, const Point b) {
            return a.district() == b.district() ? ((a ^ b) > 0) : (a.district() < b.district());
        });
        int cursz = 0;
        for(int l = 0, r = 0; l < npoints.size(); l++) {
            //cout << "l = " << l << ", r = " << r << endl;
            if(!cursz) {
                cursz = 1;
                r = (l + 1) % npoints.size();
            }
            while(((r % npoints.size()) != l) && ((npoints[l] ^ npoints[r]) >= 0)) {
                //cout << "l = " << l << ", r=  " << r << endl;
                r = (r + 1) % npoints.size();
                cursz++;
            }
            ans -= C(cursz - 1, 3);
            cursz = max(0LL, cursz - 1);
        }
    }
    cout << ans << endl;
}


