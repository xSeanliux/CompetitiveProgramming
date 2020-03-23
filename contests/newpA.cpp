#include <iostream>
using namespace std;

const int maxN = 1e6 + 10;
int A[maxN], B[maxN], choose[maxN], N, cnt, dp[maxN][2][2], ans[maxN];
int main(){
	cin >> N;	
	N *= 2;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++) cin >> B[i];
	dp[1][0][0] = dp[1][0][1] = 1;
	dp[1][1][0] = dp[1][1][1] = 0;
	for(int i = 2; i <= N; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j][0] = maxN;
			dp[i][j][1] = -maxN;
		}
		if(A[i] >= A[i - 1]){
			//cout << "1:" << i << endl;
			//cout << "dp[" << i - 1 << "][" << 0 << "][" << 1 << "] + 1 = " << dp[i - 1][0][1] + 1 << endl;
			//cout << "dp[" << i << "][0][1] = " << dp[i][0][1] << endl; 
			dp[i][0][0] = min(dp[i - 1][0][0] + 1, dp[i][0][0]);
			dp[i][0][1] = max(dp[i - 1][0][1] + 1, dp[i][0][1]);
		}
		if(A[i] >= B[i - 1]){
			dp[i][0][0] = min(dp[i - 1][1][0] + 1, dp[i][0][0]);
			dp[i][0][1] = max(dp[i - 1][1][1] + 1, dp[i][0][1]);
		}
		if(B[i] >= A[i - 1]){
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i][1][0]);
			dp[i][1][1] = max(dp[i - 1][0][1], dp[i][1][1]);
		}
		if(B[i] >= B[i - 1]){
			dp[i][1][0] = min(dp[i - 1][1][0], dp[i][1][0]);
			dp[i][1][1] = max(dp[i - 1][1][1], dp[i][1][1]);
		}
		/*
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] <<endl;
			}
		}
		*/
	}
	int at;
	if(dp[N][0][0] <= N / 2 && N / 2 <= dp[N][0][1]) at = 0;
	else if(dp[N][1][0] <= N / 2 && N / 2 <= dp[N][1][1]) at = 1;
	else {
		cout << -1 << endl;
		return 0;
	}
	for(int cur = N, need = N / 2; cur; cur--){
		if(!at) need--;	
		ans[cur] = at;
		int nv = A[cur - 1], cv = (at ? B[cur] : A[cur]);
		if(dp[cur - 1][0][0] <= need && need <= dp[cur - 1][0][1] && nv <= cv) at = 0;
		else at = 1;
	}
	for(int i = 1; i <= N; i++) cout << (ans[i] ? 'B' : 'A');
}
