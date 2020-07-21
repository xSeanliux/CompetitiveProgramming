#include <iostream>
#define int long long int
using namespace std;

const int maxN = 151;
int dp[11][11][maxN], T, N, K;

int getMin(int d){
	int res = 0, k = 1;
	while(d){
		int tk = min(9LL, d);
		res += k * tk;
		d -= tk;
		k *= 10;
	}
	return res;
}

void fillTable(){	
	for(int i = 0; i < 11; i++) for(int j = 0; j < 11; j++) for(int k = 0; k < maxN; k++) dp[i][j][k] = 1e18;
	for(int i = 1; i < 11; i++){
		for(int j = 0; j < maxN; j += i){
			dp[i][0][j] = getMin(j / i);	
			dp[0][i][j] = getMin(j / i) - 1;
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			if(i + j > 10) continue;
			for(int k = 0; k < maxN; k++){
				if(k >= i * 9 && dp[i][j][k - i * 9] != 1e18){
					dp[i][j][k] = dp[i][j][k - i * 9] * 10 + 9;
				}
				for(int d = 0; d < 9; d++){
					//cout << "d = " << d << ", val = " << i * d + j * (d + 1) << endl;
					if(k >= i * d + j * (d + 1) && dp[i + j][0][k - i * d - j * (d + 1)] != 1e18){
						dp[i][j][k] = min(dp[i][j][k], dp[i + j][0][k - i * d - j * (d + 1)] * 10 + d);
					}
				}
				//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
			}
		}
	}
}

void solve(){
	cin >> N >> K;
	K++;
	int ans = 1e18;
	for(int d = 0; d < 10; d++){
		//cout << "d = " << d << endl;
		int csum = 0, a = 0, b = 0;
		for(int i = 0; i < K; i++){
			csum += (i + d) % 10;
			(i + d >= 10 ? b : a)++;
		}
		//cout << "a = " << a << ", b = " << b << endl;
		//cout << "csum = " << csum << endl;
		if(N >= csum && dp[a][b][N - csum] != 1e18) ans = min(ans, dp[a][b][N - csum] * 10 + d);
	}
	cout << (ans < 1e18 ? ans : -1) << endl;
}
signed main(){
	fillTable();
	cin >> T;
	while(T--){
		solve();
	}
}
