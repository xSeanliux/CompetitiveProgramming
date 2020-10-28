#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxN = 326;
int N, T, x;
vector<int> pos, neg;

inline void solve(){
	cin >> N;
	vector<int>().swap(pos);
	vector<int>().swap(neg);
	int p = 0, n = 0;
	for(int i = 0; i < N; i++){
		cin >> x;
		if(x >= 0){
			p += x;
			pos.push_back(x);
		} else {
			n -= x;
			neg.push_back(x);
		}
	}
	if(p == n){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if(p > n){
		sort(pos.begin(), pos.end());
		reverse(pos.begin(), pos.end());
		for(int x : pos) cout << x << " ";
		for(int x : neg) cout << x << " ";
		cout << endl;
	} else {
		sort(neg.begin(), neg.end());
		for(int x : neg) cout << x << " ";
		for(int x : pos) cout << x << " ";
		cout << endl;
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
