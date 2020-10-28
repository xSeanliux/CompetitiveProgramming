#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;


int R, C, N, x, y, a, b;

bool onEdge(int x, int y){
	return !x || x == R || !y || y == C;
}

inline int id(int x, int y){
	if(!y) return x;
	if(x == R) return y + 2e10;
	if(y == C) return 3e10 - x;
	if(!x) return 4e10 - y;
}

vector<pii> jizz;
stack<int> stk;

signed main(){
	cin >> R >> C >> N;	
	for(int i = 0; i < N; i++){
		cin >> x >> y >> a >> b;
		if(!onEdge(x, y) || !onEdge(a, b)) continue;
		jizz.push_back({id(x, y), i});
		jizz.push_back({id(a, b), i});
	}
	sort(jizz.begin(), jizz.end());
	for(auto [a, b] : jizz){
		//cout << b << " ";
		if(stk.size() && stk.top() == b) stk.pop();
		else stk.push(b);
	}
	if(stk.empty()){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
