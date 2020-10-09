#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e3 + 10, maxC = 1e4 + 226;
int N, W, B, X, num[maxN], dp[maxN][maxC], cost[maxN];

signed main(){
	cin >> N >> W >> B >> X; 
	for(int i = 0; i < N; i++) cin >> num[i];
	for(int i = 0; i < N; i++) cin >> cost[i];
	int ans = 0;
	for(int i = 0; i < maxC; i++){
		dp[0][i] = -1;
		if(num[0] >= i && W >= cost[0] * i) dp[0][i] = W - cost[0] * i;
		if(~dp[0][i]) ans = i;
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j < maxC; j++){
			dp[i][j] = -1;
			for(int t = 0; t <= num[i] && t <= j; t++){
				//if(i == 3 && j == 5) cout << "t = " << t << endl;
				if(dp[i - 1][j - t] < 0) continue;
				int lastHas = min(dp[i - 1][j - t] + X, W + (j - t) * B);
				if(lastHas < cost[i] * t) continue;
				//if(i == 3 && j == 5) cout << "t = " << t << endl;
				dp[i][j] = max(dp[i][j], lastHas - cost[i] * t);
			}
			if(dp[i][j] >= 0){ 
				ans = max(ans, j);
				//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			}
		}
	}
	cout << ans << endl;
}
