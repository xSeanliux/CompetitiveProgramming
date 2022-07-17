#include <iostream>
using namespace std;

const int maxN = 1e3 + 326;
int T, N, A, c, e, s, dp[maxN][20], nxtdp[maxN][20], pre[maxN][20];


int main(){
	cin >> T >> N >> A;
	int ans = 0;
	for(int j = 0; j < N; j++){
		cin >> c >> e >> s;
		for(int i = 0; i < T; i++){
			for(int k = 0; k <= A && k <= i; k++){
				if(i >= e && k + e >= c) nxtdp[i][k] = max(nxtdp[i][k], s + pre[i - e][k + e - c]);
				pre[i][k] = max(pre[i][k], nxtdp[i][k]);
				if(i) pre[i][k] = max(pre[i][k], pre[i - 1][k]);
				if(k) pre[i][k] = max(pre[i][k], pre[i][k - 1]);
				ans = max(ans, nxtdp[i][k]);
			}
		}
	}
	cout << ans << endl;
}


