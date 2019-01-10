#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
} points[101];

int C, p;
vector <int> inds;

bool pCmp(const Point a, const Point b){
    return a.x > b.x;
}

double dist(int i, int j){
    return sqrt( (points[i].x - points[j].x)*(points[i].x - points[j].x) + (points[i].y - points[j].y)*(points[i].y - points[j].y) );
}

int main(){
    cin >> C;
    while(C--){
        inds.clear();
        cin >> p;
        for(int i = 0; i < p; i++){
            cin >> points[i].x >> points[i].y;
        }
        sort(points, points + p, pCmp);
        int M = 0;
        double ans = 0;
        for(int i = 0; i < p; i++){
            if(points[i].y > M){
                double res = dist(i, i-1) * (points[i].y - M) / (points[i].y - points[i-1].y);
                //cout << "ans += " << dist(i, i-1) << " * " << (points[i].y - M) << " / " << (points[i].y - points[i-1].y) <<" = " << res<< endl;
                ans += res;
                M = points[i].y;
            }
        }
        printf("%.2f\n", ans);
    }
}

