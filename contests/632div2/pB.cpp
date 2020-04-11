#include <iostream>
#include <set>
using namespace std;

set<int> st;

const int maxN = 1e5 + 10;
int T, N, a[maxN], b[maxN], has[maxN][2];

inline void solve(){
	for(int i = 1; i < N; i++) has[i][0] = has[i][1] = false;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		has[i][0] = has[i - 1][0];
		has[i][1] = has[i - 1][1];
		if(a[i] == 1) has[i][1] = true;
		if(a[i] == -1) has[i][0] = true;
	}
	for(int i = 1; i <= N; i++) cin >> b[i];
	for(int i = 1; i <= N; i++){
		if(a[i] > b[i] && !has[i - 1][0]){
			cout << "NO\n";
			return;
		}
		if(a[i] < b[i] && !has[i - 1][1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		solve();
	}
}
