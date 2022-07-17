#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(x) x.begin(),x.end()
using namespace std;

const int maxN = 1e5 + 326;

struct Point{
	int x, y;	
	Point(){}
	Point(int x, int y): x(x), y(y){}
	Point(Point &a, Point &b): x(a.x - b.x), y(a.y - b.y){}
};


const Point operator-(Point a, Point b){ return Point(a, b); }
const int cross(Point a, Point b){ return a.x * b.y - a.y * b.x; }

vector<Point> ch1, ch2, allp;

int N, x, y, head;

Point stk[maxN];

inline void push(Point p){
	stk[head++] = p;
}

inline Point pop(){
	return stk[--head];
}

inline double slope(Point a, Point b){
	cout << "Calculating slope of " << a.x << ", " << a.y << " and " << b.x << ", " << b.y << endl;
	return (b.y - a.y) * 1.0 / (b.x - a.x);
}

struct Line{
	double m, k; //y = mx + k
	Line(){}
	Line(Point a, Point b){
		//(y - a.y) = slope(a, b) * (x - a.x)
		m = slope(a, b);
		k = a.y - slope(a, b) * a.x;
	}
	const void eval(Line l, double &X, double &Y){
		//l.mx - y = -l.k
		//mx - y = -k
		double D = m - l.m, Dx = k - l.k, Dy = l.k * m - l.m * k;
		X = Dx / D, Y = Dy / D;
	}
} mL, ML;
inline int inc(int a, int m){
	return (a == m - 1 ? 0 : a + 1);
}

inline int dec(int a, int m){
	return (!a ? m - 1 : a - 1);
}

inline void buildCH(vector<Point> &ps){
	head = 0;
	Point p;
	for(int i = 0; i < ps.size(); i++){
		p = ps[i];
		while(head >= 2 && cross(stk[head - 1] - stk[head - 2], p - stk[head - 1]) >= 0){
			pop();
		}
		push(p);
	}
	int k = head;
	reverse(ALL(ps));
	for(int i = 1; i < ps.size(); i++){
		p = ps[i];
		while(head >= 2 && head > k && cross(stk[head - 1] - stk[head - 2], p - stk[head - 1]) >= 0) pop();
		push(p);
	}
	vector<Point>().swap(ps);
	for(int i = 0; i < head; i++) ps.push_back(stk[i]);
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		allp.emplace_back(x, y);
	}
	sort(ALL(allp), [](Point a, Point b){
		return a.x < b.x;
	});
	for(int i = 0; i < N; i++) (i < N / 2 ? ch1 : ch2).push_back(allp[i]);
	buildCH(ch1);
	buildCH(ch2);
	cout << "ch1: "; for(Point p : ch1) cout << "(" << p.x << ", " << p.y << ")\n";
	cout << "ch2: "; for(Point p : ch2) cout << "(" << p.x << ", " << p.y << ")\n";
	int ind = 0;
	for(int i = 0; i < ch2.size(); i++) if(ch2[i].x > ch2[ind].x) ind = i;
	int rgt = ind;
	double minSlope = 3e9, maxSlope = -3e9;
	for(int lft = 0; lft < ch1.size(); lft++){
		while(slope(ch1[lft], ch2[inc(rgt, ch2.size())]) > slope(ch1[lft], ch2[rgt])) rgt = inc(rgt, ch2.size());
		if(slope(ch1[lft], ch2[rgt]) < minSlope){
			minSlope = slope(ch1[lft], ch2[rgt]);
			mL = Line(ch1[lft], ch2[rgt]);
		}
	}
	rgt = ind;
	for(int lft = ch1.size() - 1; lft >= 0; lft--){
		while(slope(ch1[lft], ch2[dec(rgt, ch2.size())]) < slope(ch1[lft], ch2[rgt])) rgt = dec(rgt, ch2.size());
		maxSlope = max(maxSlope, slope(ch1[lft], ch2[rgt]));
		if(slope(ch1[lft], ch2[rgt]) > maxSlope){
			maxSlope = slope(ch1[lft], ch2[rgt]);
			ML = Line(ch1[lft], ch2[rgt]);
		}
	}
	double X, Y;
	mL.eval(ML, X, Y);
	cout << X << " " << Y << endl;

}

