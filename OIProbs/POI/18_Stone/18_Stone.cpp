#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int 
using namespace std;

const double PI = acos(-1), eps = 1e-7;
const int maxN = 2e5 + 10;

int N, x, y, X, Y, ans;

struct Point{
	int y, x;
	double t;
	Point(){}
	Point(int x, int y): y(y), x(x){
		t = atan2(y, x);
	}
	Point(double t): t(t), x(0), y(0){}
	const bool operator<(const Point &p) const{
		return t < p.t;
	}
};

vector<Point> points;

inline int dist(int x, int y){
	return x * x + y * y;
}

inline int inc(int x){
	x++;
	if(x == N) x = 0;
	return x;
}

double arcdist(double a, double b){
	return b + eps >= a ? b - a : b - a + 2 * PI;
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		if(!x && !y) continue;
		points.emplace_back(x, y);
	}
	sort(points.begin(), points.end());
	N = points.size();
	for(int i = 0; i < N; i++){
		points.emplace_back((points[i].t + points[inc(i)].t) / 2);
	}
	sort(points.begin(), points.end());
	N = points.size();
	for(int i = 0; i < N; i++){
		if(points[i].t < eps) points.emplace_back(points[i].t + PI);
		else points.emplace_back(points[i].t - PI);
	}
	sort(points.begin(), points.end());
	N = points.size();

	int curX = 0, curY = 0, r = 0, sz = 0;
	curX = 0, curY = 0, r = 0, sz = 0;
	for(int l = 0; l < N; l++){
		//cout << "l = " << l << endl;
		//cout << "r =  " << r << ", dist = " << arcdist(points[l].t, points[r].t) << " rad" << endl;
		while(sz < N && arcdist(points[l].t, points[r].t) <= PI + eps){
			curX += points[r].x;
			curY += points[r].y;
			r = inc(r);
			sz++;
		}
		//cout << "r = " << r << ", X = " <<curX << ", Y = " << curY << endl;
		ans = max(ans, dist(curX, curY));
		if(sz){
			curX -= points[l].x;
			curY -= points[l].y;
			sz--;
		}
	}
	reverse(points.begin(), points.end());
	curX = 0, curY = 0, r = 0, sz = 0;
	for(int l = 0; l < N; l++){
		//cout << "l = " << l << endl;
		//cout << "r =  " << r << ", dist = " << arcdist(points[l].t, points[r].t) << " rad" << endl;
		while(sz < N && arcdist(points[l].t, points[r].t) <= PI + eps){
			curX += points[r].x;
			curY += points[r].y;
			r = inc(r);
			sz++;
		}
		//cout << "r = " << r << ", X = " <<curX << ", Y = " << curY << endl;
		ans = max(ans, dist(curX, curY));
		if(sz){
			curX -= points[l].x;
			curY -= points[l].y;
			sz--;
		}
	}

	cout << ans << endl;
}


