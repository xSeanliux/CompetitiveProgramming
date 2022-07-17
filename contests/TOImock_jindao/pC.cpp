#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;

struct Point{
	int x, y, id;
	Point(int x = 0, int y = 0, int id = 0): x(x), y(y), id(id){}
} points[maxN], ch[maxN];

inline int cross(Point a, Point b, Point c){
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

inline int Abs(int x){
	return x < 0 ? -x : x;
}

int Q, l[maxN], r[maxN], ans[maxN];

inline int del(int id){
	int nxt = r[id], prv = l[id];
	r[prv] = nxt;
	l[nxt] = prv;
	return Abs((points[nxt].x - points[id].x) * (points[prv].y - points[id].y) - (points[prv].x - points[id].x) * (points[nxt].y - points[id].y)) / 2;
}

signed main(){
	cin >> Q;	
	for(int i = 0; i < Q + 3; i++){
		int x, y;
		cin >> x >> y;
		points[i] = Point(x, y, i);
	}
	sort(points, points + Q + 3, [](Point &a, Point &b){
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
	});
	int m = 2;
	ch[0] = points[0];
	ch[1] = points[1];
	for(int i = 2; i < Q + 3; i++){
		while(m >= 2 && cross(ch[m - 2], ch[m - 1], points[i]) > 0){
			m--;
		}
		ch[m++] = points[i];
	}
	int k = m;	
	for(int i = Q + 1; i >= 0; i--){
		while(m >= 2 && cross(ch[m - 2], ch[m - 1], points[i]) > 0){
			m--;
		}
		ch[m++] = points[i];
	}
	while(ch[m - 1].id == ch[0].id) m--;
	int A = 0;
	for(int i = 2; i < m; i++){
		A += Abs((ch[i].x - ch[0].x) * (ch[i - 1].y - ch[0].y) - (ch[i - 1].x - ch[0].x) * (ch[i].y - ch[0].y)) / 2;
	}
	sort(points, points + Q + 3, [](Point &a, Point &b){
		return a.id < b.id;
	});
	for(int i = 0; i < m; i++){
		l[ch[i].id] = ch[(i - 1 + m) % m].id;
		r[ch[i].id] = ch[(i + 1) % m].id;
	}
	for(int i = Q + 2; i > 2; i--){
		ans[i] = A;
		int d = del(i);
		A -= d;
	}
	ans[2] = A;
	for(int i = 2; i <= Q + 2; i++) cout << ans[i] << endl;
}
