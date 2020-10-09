#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 2e3 + 226;

int dp[maxN][maxN][4], N, M, d[4][4] = {
	{-1, 0, 0, -1},
	{-1, 0, 0,  1},
	{ 1, 0, 0, -1},
	{ 1, 0, 0,  1}
};

char val[maxN][maxN];
string s;

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 1; j <= M; j++){
			val[i][j] = s[j - 1];
		}
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++){
			if(val[i][j] == val[i - 1][j] && val[i][j] == val[i][j - 1]){
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
			} else dp[i][j][0] = 1;
		}
	
	for(int i = 1; i <= N; i++)
		for(int j = M; j >= 1; j--){
			if(val[i][j] == val[i - 1][j] && val[i][j] == val[i][j + 1]){
				dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j + 1][1]) + 1;
			} else dp[i][j][1] = 1;
		}

	for(int i = N; i >= 1; i--)
		for(int j = 1; j <= M; j++){
			if(val[i][j] == val[i + 1][j] && val[i][j] == val[i][j - 1]){
				dp[i][j][2] = min(dp[i + 1][j][2], dp[i][j - 1][2]) + 1;
			} else dp[i][j][2] = 1;
		}

	for(int i = N; i >= 1; i--)
		for(int j = M; j >= 1; j--){
			if(val[i][j] == val[i + 1][j] && val[i][j] == val[i][j + 1]){
				dp[i][j][3] = min(dp[i + 1][j][3], dp[i][j + 1][3]) + 1;
			} else dp[i][j][3] = 1;
		}
	
	long long int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			ans += min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3]));
		}
	}
	cout << ans << endl;

}
