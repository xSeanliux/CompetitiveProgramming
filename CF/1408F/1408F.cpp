#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

vector<pii> ans;

int N;

void solve(int l, int r){
	if(r - l == 1) return;
	int m = (r + l) / 2;
	solve(l, m);
	solve(m, r);
	for(int i = l; i < m; i++) ans.emplace_back(i, i + (r - l) / 2);
}

int main(){
	cin >> N;
	for(int i = 0; i < 30; i++){
		if((N >> i) == 1){
			//cout << "i = " << i << endl;
			solve(1, (1 << i) + 1);
			solve(N - (1 << i) + 1, N + 1);
			break;
		}
	}
	cout << ans.size() << endl;
	for(auto [a, b] : ans) cout << a << " " << b << endl;
}
