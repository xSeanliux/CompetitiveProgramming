#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int 
using namespace std;

const int maxN = 2e5 + 10;

int N, x, y, X, Y, mX, mY, ans;
vector<pii> vu, vd, pos, neg, points;

const bool operator<(pii a, pii b){
	return a.S * b.F < a.F * b.S;
}

inline int hyp(int a, int b){
	return a * a + b * b;
}

inline int add(int a, int b){
	return (a + b >= N ? a + b - N : a + b);
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		if(!x && !y) continue;
		if(!x){
			(y > 0 ? vu : vd).emplace_back(x, y);
			continue;
		}
		(x > 0 ? pos : neg).emplace_back(x, y); 
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	for(auto p : pos) points.push_back(p);
	for(auto p : vu)  points.push_back(p);
	for(auto p : neg) points.push_back(p);
	for(auto p : vd)  points.push_back(p);
	N = points.size();
	for(int i = 0; i < N; i++){
		if(points[i].F * points[add(i, 1)].S - points[add(i, 1)].F * points[i].S > 0){
			cout << 1 / ( 1  - 1 ) << endl;
			return 0;
		}
	}
	for(int i = 0; i < N; i++){
		X = Y = 0;
		//cout << "For i = " << i << endl;
		for(int j = i;; j = add(j, 1)){
			//cout << "Adding " << j << endl;
			X += points[j].F;
			Y += points[j].S;
			ans = max(ans, hyp(X, Y));
			if(add(j, 1) == i) break;
		}
	}
	cout << ans << endl;
}
