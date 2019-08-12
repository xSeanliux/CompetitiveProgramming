#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

int K, N, a, b;

struct Point{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y){}
    double dist(){
        return sqrt(x*x + y*y);
    }
};

struct Vec{
    int x, y;
    Vec(int x, int y):  x(x), y(y){}
    Vec(Point a, Point b): x(b.x - a.x), y(b.y - a.y){}
    int dot(Vec v){
        return v.x*x + v.y*y;
    }
    int cross(Vec v){
        return x * v.y - y * v.x;
    }
    double dist(){
        return sqrt(x*x + y*y);
    }
};

Point lowest, _p;
Vec iHat = Vec(1, 0);
vector<Point> points, ch;
stack<Point> stk;

bool sortCos(Point a, Point b){
    if(Vec(lowest, a).dist() < 1e-10) return true;
    if(Vec(lowest, b).dist() < 1e-10) return false;
    double ca = Vec(lowest, a).dot(iHat)/Vec(lowest, a).dist(), cb = Vec(lowest, b).dot(iHat)/Vec(lowest, b).dist();
    //cout << "Comparing (" << a.x << ", " << b.x << "), cos = " << ca <<" and (" << b.x << ", " << b.y << "), cos = " << cb << endl;
    if(fabs(ca - cb) <= 1e-10){
        //if(ca <= 1e-10) return Vec(lowest, a).dist() > Vec(lowest, b).dist();
        return Vec(lowest, a).dist() < Vec(lowest, b).dist();
    }
    return ca > cb;
}



int main(){
    cin >> K;
    cout << K << endl;
    while(K--){
        cin >> N;
        points.clear(); points.resize(N); ch.clear();
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            points[i] = Point(a, b);
            if(!i) lowest = points[i];
            if(lowest.y == b){
                lowest = (lowest.x < a) ? lowest : points[i];
            } else {
                lowest = (lowest.y < b) ? lowest : points[i];
            }
        }
        //cout << "LOWEST: " << lowest.x << ", " << lowest.y << endl;
        sort(points.begin(), points.end(), sortCos);
        //cout << "SORTED: " << endl;
        //for(Point p : points){
        //    cout << p.x << ", " << p.y << endl;
        //}
        //points.push_back(points[0]);
        stk = stack<Point>();
        stk.push(points[0]); stk.push(points[1]);
        for(int i = 2; i < N; i++){
            //cout << "Point: " << points[i].x << ", " << points[i].y << endl;
            _p = stk.top(); stk.pop();
            while(stk.size() >= 1 && Vec(stk.top(), _p).cross(Vec(_p, points[i])) <= 1e-10){
                _p = stk.top(); stk.pop();
                //cout << "POPPIN" << endl;
            }
            stk.push(_p);
            stk.push(points[i]);
        }
        //cout << endl;
        while(!stk.empty()){
            ch.push_back(stk.top());
            stk.pop();
        }

        sort(ch.begin(), ch.end(), sortCos);
        ch.push_back(lowest);
        cout << ch.size() << endl;
        for(Point p : ch){
            cout << p.x << " " << p.y << endl;
        }
        if(K){
            cin >> a;
            cout << -1 << endl;
        }
    }
}
