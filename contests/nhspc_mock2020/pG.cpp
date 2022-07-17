#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <math.h>
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define double long double
using namespace std;

const double PI = acos(-1), eps = 1e-10;
int mx = 0, N, x, y;
vector<pdd> points;

double eval(double theta){
	double m = tan(theta), md = 0;
	for(auto [a, b] : points){
		md = max(md, (b - m * a) * (b - m * a) / (1 + m * m));
	}
	return sqrt(md);
	return 0;
}

double getAns(double l, double r){
	double m1, m2;
	while(r - l > eps){
		m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
		if(eval(m1) + eps < eval(m2)){
			r = m2;
		} else {
			l = m1;	
		}
	}
	return eval((l + r) / 2) * 4;
}

inline bool can(double r){
	double l = 0, R = PI;
	for(auto [x, y] : points){
		double theta1 = asin((2 * r * y + sqrt(2 * r * y * 2 * r * y - 4 * (x * x + y * y) * (r * r - x * x))) / (2 * (x * x + y * y))) - PI / 2;
		double theta2 = asin((2 * r * y - sqrt(2 * r * y * 2 * r * y - 4 * (x * x + y * y) * (r * r - x * x))) / (2 * (x * x + y * y)) + PI / 2
	}
}

int main(){
	cout << asin() << endl;
	cin >> N;
	points.resize(N);
	double L = 0, R = PI, ans = 0, mx = 0;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		points[i] = {x, y};
	}
	double L = 0, R = 1e9, M; 
	while(R - L > eps){
		if(can(M)) L = M;
		else R = M;
	}
	cout << M * 4 << endl;
}
