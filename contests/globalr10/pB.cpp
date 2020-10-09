#include <iostream>
#define int long long int
using namespace std;
const int maxN = 2e5 + 326;

int T, N, k, x[maxN];

inline void solve(){
	cin >> N >> k;
	int mx = -2e9, mn = 2e9;
	for(int i = 0; i < N; i++){
		cin >> x[i];
		mx = max(mx, x[i]);
		mn = min(mn, x[i]);
	}
	if(k % 2){
		for(int i = 0; i < N; i++){
			cout << mx - x[i] << " \n"[i == N - 1];
		}
	} else {
		for(int i = 0; i < N; i++){
			cout << x[i] - mn << " \n"[i == N - 1];
		}
	}
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
