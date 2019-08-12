#include <iostream>
#include <vector>
#define int long long int
using namespace std;

struct Point{
    int x, y;
    Point(){}
    Point(int a, int b): x(a), y(b){}
};

bool isCol(Point a, Point b, Point c){
    return ((a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x) == 0);
}

vector<Point> v, v1, v2, v3;

signed main(){
    int N, a ,b;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v[i] = Point(a, b);
    }
    for(int i = 0; i < N; i++){
        if(i == 0 || i == 1) continue;
        if(!isCol(v[0], v[1], v[i])){
            v1.push_back(v[i]);
        }
    }
    if(v1.size() <= 2){
        cout << "YES" << endl;
        return 0;
    } else {
        for(int i = 2; i < v1.size(); i++){
            if(!isCol(v1[0], v1[1], v1[i])) break;
            else if (i == v1.size() - 1){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(i == 0 || i == 2) continue;
        if(!isCol(v[0], v[2], v[i])) v2.push_back(v[i]);
    }
    if(v2.size() <= 2){
        cout << "YES" << endl;
        return 0;
    } else {
        for(int i = 2; i < v2.size(); i++){
            if(!isCol(v2[0], v2[1], v2[i])) break;
            else if (i == v2.size() - 1){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(i == 1 || i == 2) continue;
        if(!isCol(v[1], v[2], v[i])) v3.push_back(v[i]);
    }
    if(v3.size() <= 2){
        cout << "YES" << endl;
        return 0;
    } else {
        for(int i = 2; i < v3.size(); i++){
            if(!isCol(v3[0], v3[1], v3[i])) break;
            else if (i == v3.size() - 1){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
