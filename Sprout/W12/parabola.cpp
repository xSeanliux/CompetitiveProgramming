#include <iostream>
#include <utility>
#include <vector>
#include <map>
#define F first
#define S second
#define int long long int
#define pii pair<int,int>
using namespace std;


int T, N, x, y;
vector<pii> points;
vector<vector<vector<int> > > onPoint;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        points.resize(N);
        onPoint.resize(N);
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            points[i] = {x, y};
        }
        for(int i = 0; i < N; i++){
            onPoint[i].resize(N);
            for(int j = i + 1; j < N; j++){
                //get parabola
                if(points[i].S == points[j].S) continue;
                int delta = points[i].F*points[i].F*points[j].F - points[j].F*points[j].F*points[i].F;
                double b = points[i].F * points[i].F * points[j].S - points[j].F * points[j].F * points[i].S * 1.0 / delta;
                double a = points[i].S * points[j].F - points[j].S * points[i].F;
                for(int k = 0; k < N; k++){
                    if(fabs(a*points[k].F*points[k].F + a*points[k].F - points[k].S) < eps){
                        onPoint[i][k].push_back(k);
                    }
                }
            }
        }
    }
}
