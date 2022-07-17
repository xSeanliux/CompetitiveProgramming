#include <iostream>
#define int long long int
using namespace std;

const int maxN = 226;
int k, s, m, q, dp[maxN][maxN][maxN], ans[maxN], bp[maxN];
//len, mod, sumdig

inline void run(){
	dp[0][0][0] = 1;
	for(int i = 0; i < 10; i++){
		dp[1][i % m][i]++;
	}
	bp[0] = 1;
	int r = 10;
	for(int i = 1; i < maxN - 1; i++){
		bp[i] = bp[i - 1] * 10 % m;
		for(int j = 0; j < m; j++){
			for(int k = 0; k <= s; k++){
				//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
				for(int d = 0; d < 10; d++){
					dp[i + 1][(j * 10 + d) % m][k + d] += dp[i][j][k];
					dp[i + 1][(j * 10 + d) % m][k + d] = min(dp[i + 1][(j * 10 + d) % m][k + d], (int)(1e18 + 326));
				}
			}	
		}
	}
}

inline void solve(){
	int k;
	cin >> k;
	//cout << dp[200][0][s] << endl;
	if(dp[200][0][s] < k){
		cout << "NIE" << endl;
		return;
	}
	int cursum = 0, digsum = 0;
	for(int i = 0; i < 200; i++){
		bool f = false;
		for(int d = 0; d < 10; d++){
			//new num = cursum + d * bp[199 - i], new digsum = digsum + d
			int _cursum = (cursum + d * bp[199 - i]) % m, _digsum = digsum + d;
			if(s - _digsum < 0) break;
			//cout << "i = " << i << ", d = " << d << ", cursum = " << _cursum << ", digsum = " << _digsum << endl;
			//cout << "new dp val = " << dp[199 - i][(m - _cursum) % m][s - _digsum] << endl;
			//cout << "k = " << k << endl;
			if(dp[199 - i][(m - _cursum) % m][s - _digsum] >= k){
				f = true;
				cursum = _cursum;
				digsum = _digsum;
				ans[i] = d;
				f = true;
				break;
			} else {
				k -= dp[199 - i][(m - _cursum) % m][s - _digsum];
			}
		}
		if(!f){
			cout << "NIE" << endl;
			return;
		}
		//cout << "i = " << i << ", cursum = " << cursum << ", digsum = " << digsum << endl;
		//cout << "ans[" << i << "] = " << ans[i] << endl;
	}
	for(int i = 0; i < 200; i++){
		if(!ans[i]) continue;
		else {
			for(int j = i; j < 200; j++) cout << ans[j];
			break;
		}
	}
	cout << endl;
}
signed main(){
	cin >> s >> m >> q;
	run();
	while(q--){
		solve();
	}
}
