#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#define int long long int
using namespace std;

int dy, dx;

struct Seg{
	int a, b, c, d;
	double _a, _b;
	Seg(){}
	Seg(int a, int b, int c, int d): a(a), b(b), c(c), d(d){
		_a = dy * a - dx * b;
		_b = dx * a + dy * b;
	}
	bool operator<(const Seg &s) const {
		return _a == s._a ? _b < s._b : _a < s._a;
	}
};

int N, a, b, c, d;
vector<Seg> vec;

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b >> c >> d;
		if(a > c || (a == c && b > d)){
			swap(a, c);
			swap(b, d);
		}
		if(!i){
			dy = d - b;
			dx = c - a;
		}
		vec.emplace_back(a, b, c, d);
	}
	/*
	cout << "theta = " << theta << endl;
	for(int i = 0; i < N; i++){
		cout << "Point: " << vec[i]._a << " " << vec[i]._b << endl;
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < N; i++){
		cout << "Point: " << vec[i]._a << " " << vec[i]._b << endl;
	}
	*/
	sort(vec.begin(), vec.end());
	for(int i = 1; i < N; i++){
		cout << vec[i - 1].c << " " << vec[i - 1].d << " " << vec[i].a << " " << vec[i].b << endl;
	}
}
