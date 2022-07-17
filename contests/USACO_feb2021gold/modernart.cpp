#include <iostream>
using namespace std;

const int maxN = 326;

int dp[maxN][maxN][2], N, arr[maxN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	for(int i = N - 1; i >= 0; i--){
		for(int j = i; j < N; j++){
			dp[i][j][0] = max(dp[i + 1][j][0], dp[i + 1][j][1]);
			for(int k = i + 1; k <= j; k++){
				if(arr[i] == arr[k]){
					int ndp = 1 + max(dp[i + 1][k - 1][0], dp[i + 1][k - 1][1]) + max(dp[k][j][1], max(dp[k + 1][j][0], dp[k + 1][j][1])); 
					dp[i][j][1] = max(dp[i][j][1], ndp);
				}
			}
		}
	}
	cout << N - max(dp[0][N - 1][0], dp[0][N - 1][1]) << endl;
}
