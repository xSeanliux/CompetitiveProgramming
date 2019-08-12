#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5;
int N, x, y;

struct Point{
    int x, y;
    Point(){}
    Point(int a, int b): x(a), y(b){}
};

vector<Point> points;
vector<int> vec, yvals, xvals;
set<int> xVals;

int bit[maxN + 10];

void modify(int p, int x){
    for(int i = p; i <= maxN; i += (i & -i)){
        bit[i] += x;
    }
}

int sum(int p){
    int res = 0;
    for(int i = p; i > 0; i -= (i & -i)){
        res += bit[i];
    }
    return res;
}

signed main(){
    ericxiao;
    cin >> N;
    xvals.clear();
    yvals.clear();
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        yvals.push_back(y);
        xvals.push_back(x);
        points.push_back(Point(x, y));
    }
    sort(xvals.begin(), xvals.end());
    sort(yvals.begin(), yvals.end());
    xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
    yvals.erase(unique(yvals.begin(), yvals.end()), yvals.end());
    int maxY = yvals.size(), maxX = xvals.size();
    for(Point &p : points){
        p.x = lower_bound(xvals.begin(), xvals.end(), p.x) - xvals.begin() + 1;
        p.y = lower_bound(yvals.begin(), yvals.end(), p.y) - yvals.begin() + 1;
    }
    for(Point p : points){
        //cout << p.x << ", " << p.y << endl;
    }
    sort(points.begin(), points.end(), [](Point a, Point b){
        return a.y < b.y;
    });

    int cp = points.size() - 1, ans = 0;
    for(int i = maxY; i >= 0; i--){
        //cout << "i = " << i << endl;
        vector<int> currentX;
        while(points[cp].y == i && cp >= 0){
            //cout << "ADDING " << points[cp].x << endl;
            currentX.push_back(points[cp].x);
            cp--;
        }
        sort(currentX.begin(), currentX.end());
        int sz;
        if(currentX.size() > 1){
            for(int i = 1; i < currentX.size(); i++){
                sz = sum(currentX[i] - 1) - sum(currentX[i - 1]);
                ans -= sz * (sz + 1) / 2;
            }
        }
        //cout << "G" << endl;
        if(currentX.size()){
            //cout << currentX[0] << endl;
            sz = sum(currentX[0] - 1);
            ans -= sz * (sz + 1) / 2;
            //cout << "takeaway = " << takeaway << endl;

            sz = sum(maxX + 1) - sum(currentX[currentX.size() - 1]);
            ans -= sz * (sz + 1) / 2;
            //cout << "takeaway = " << takeaway << endl;
            //cout << "takeaway = " << takeaway << endl;
            for(int i : currentX){
                if(!xVals.count(i)){
                    xVals.insert(i);
                    modify(i, 1);
                }
            }
            ans += (int)(xVals.size()) * (int)(xVals.size() + 1) / 2;
        }

    }
    cout << ans << endl;

}
