#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int blockSize = 1000;


struct Point{
    int x, y, ind;
    Point(){}
    Point(int X, int Y, int i): x(X), y(Y), ind(i){}
};

const int INF = 1e15, LIM = 25 * 1e8;

int N, x, y;

vector<Point> pts;

int Abs(int x){
    return (x > 0 ? x : -x);
}

int dist(Point a, Point b){
    return Abs(a.x - b.x) + Abs(a.y - b.y);
}

signed main(){
    ericxiao;
    cin >> N;
    pts.resize(N);
    int ans = INF;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        pts[i] = Point(x, y, i);
    }
    sort(pts.begin(), pts.end(), [](Point a, Point b){
        return (a.x / blockSize == b.x / blockSize ? a.y < b.y : a.x / blockSize < b.x / blockSize);
    });
    for(Point p : pts){
        cout << p.ind + 1 << " ";
    }
}
