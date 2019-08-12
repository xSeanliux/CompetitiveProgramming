#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

struct Point{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y){}
} p1, p2, q1, q2;


Point diff(Point a, Point b){
    return Point(b.x - a.x, b.y - a.y);
}

int cross(Point a, Point b){
    int t = (a.x) * (b.y) - (a.y) * (b.x);
    if(t > 0) return 1;
    else if(t < 0) return -1;
    else return 0;
}

int N, a, b;


signed main(){
    cin >> N;
    while(N--){
        cin >> a >> b;
        p1 = Point(a, b);
        cin >> a >> b;
        p2 = Point(a, b);
        cin >> a >> b;
        q1 = Point(a, b);
        cin >> a >> b;
        q2 = Point(a, b);
        if(cross(diff(p1, p2), diff(p1, q1)) * cross(diff(p1, p2), diff(p1, q2)) == -1 && cross(diff(q1, q2), diff(q1, p1)) * cross(diff(q1, q2), diff(q1, p2)) == -1){
            cout << "Yes" << endl;
        } else if((cross(diff(p1, p2), diff(p1, q1)) == 0 && (q1.x <= max(p1.x, p2.x) && (q1.x >= min(p1.x, p2.x)))) || (cross(diff(p1, p2), diff(p1, q2)) == 0 && (q2.x <= max(p1.x, p2.x) && (q2.x >= min(p1.x, p2.x)))) ){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }

    }
}
