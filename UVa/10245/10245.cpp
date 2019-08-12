#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
//The annoying thing about this is that an O(N log N) solution is required
//but when spliting, don't use a vector, use the array tmp.
struct Point{ long double x, y; };
bool cmpX(const Point &a, const Point &b) { return a.x < b.x; }
bool cmpY(const Point &a, const Point &b) { return a.y < b.y; }
double distSquared(const Point& a, const Point& b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }


const int INF = 2147483647, MAXN = 10000;
int N;
long double a, b, x, y;
Point pts[MAXN], tmp[MAXN];

double minDistSquared(){
    double _d = INF;
    //cout << pts.size() << endl;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N && pts[j].x - pts[i].x <= _d; j++){
            //cout << "checking " << i << ", " << j << endl;
            //if(distSquared(pts[i], pts[j]) < _d)
            //printf("dist(%d, %d): %lf\n", i, j, distSquared(pts[i], pts[j]));
            _d = min(_d, distSquared(pts[i], pts[j]));
        }
    }
    //cout << "_d = " << _d << endl;
    return _d;
}

double minDistSquared(int L, int R){
    if(L >= R) return INF;
    int M = L + R >> 1;
    double _d = min(minDistSquared(L, M), minDistSquared(M + 1, R));
    int K = 0;
    for(int i = M; i >= L && pts[M].x - pts[i].x < _d; i--) tmp[K++] = pts[i];
    for(int i = M + 1; i <= R && pts[i].x - pts[M].x < _d; i++) tmp[K++] = pts[i];
    sort(tmp, tmp + K, cmpY);
    for(int i = 0; i < K - 1; i++){
        for(int j = 1; j <= 3 && j + i < K; j++){
            _d = min(_d, distSquared(tmp[i], tmp[i + j]));
        }
    }

    return _d;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    /*
    cin >> N;
    pts.clear();
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        pts.push_back({x, y});
    }
    //sort(pts.begin(), pts.end(), cmpX);
    */

    while(cin >> N){
        if(!N) return 0;
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            pts[i] = {x, y};
        }
        sort(pts, pts + N, cmpX);
        double d = minDistSquared();
        if(d >= 100000000 - 1e-9){
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << sqrt(minDistSquared(0, N-1)) << endl;
        }
    }

}
