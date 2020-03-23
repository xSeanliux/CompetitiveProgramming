#include <iostream>
using namespace std;

const int maxN = 4e3 + 10, INF = 2e9;
int N, A[maxN], B[maxN], dp[maxN][maxN], from[maxN][maxN], ans[maxN];

int main(){
	cin >> N;
	N *= 2;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int j = 1; j <= N; j++) cin >> B[j];
	dp[0][0] = 0;
	for(int i = 0; i <= N / 2; i++){
		for(int j = 0; j <= N / 2; j++){
			if(!i && !j) continue;
			dp[i][j] = INF;
			if(i > 0 && A[i + j] >= dp[i - 1][j]){
				dp[i][j] = A[i + j];
				from[i][j] = 1;
			} 
			if(j > 0 && B[i + j] >= dp[i][j - 1] && B[i + j] < dp[i][j]){
				dp[i][j] = B[i + j];
				from[i][j] = 2;
			}
			//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}
	int I = N / 2, J = N / 2;
	if(dp[N / 2][N / 2] == INF || !from[N / 2][N / 2]){
		cout << -1 << endl;
		return 0;
	}
	while(I || J){
		//cout << "dp[" << I << "][" << J << "] = " << dp[I][J] << endl;
		if(!J || from[I][J] == 1){
			ans[I + J] = 0;
			I--;
		} else {
			ans[I + J] = 1;
			J--;
		}
	}
	for(int i = 1; i <= N; i++) cout << (ans[i] ? 'B' : 'A');
}
