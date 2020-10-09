#include <iostream>
#include <deque>
#define int long long int
using namespace std;

const int maxN = 1e6 + 226;
int T, N, M, c[maxN], dp[maxN], cs;

inline void solve(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> c[i];
		if(!c[i]) c[i] = -1;
	}
	dp[1] = 0;
	c[1] = 0;
	deque<int> dq;
	dq.push_back(0);
	for(int i = 1; i <= N; i++){
		while(dq.size() && i - dq.front() > M){
			dq.pop_front();
		}
		if(!dq.size()){
			cout << "Case #" << ++cs << ": -1\n";
			return;
		}
		dp[i] = dp[dq.front()] + c[dq.front()];
		if(c[i] != -1){
			while(dq.size() && dp[dq.back()] + c[dq.back()] >= dp[i] + c[i]){
				dq.pop_back();
			}
			dq.push_back(i);
		}	
	}
	cout << "Case #" << ++cs << ": " << dp[N] << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
