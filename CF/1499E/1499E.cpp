#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int maxN = 1326, MOD = 998244353;
string A, B;
int dp[maxN][maxN][2], w[maxN][2];

inline int add(int a, int b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

signed main(){
	cin >> A >> B;
	int ans = 0;
	for(int i = 0; i < A.length(); i++){
		w[i][0] = 1;
		for(int j = i - 1; j >= 0; j--){
			if(A[j] != A[j + 1]) w[i][0]++;
			else break;
		}
	}
	for(int i = 0; i < B.length(); i++){
		w[i][1] = 1;
		for(int j = i - 1; j >= 0; j--){
			if(B[j] != B[j + 1]) w[i][1]++;
			else break;
		}
	}
	for(int i = 0; i < A.length(); i++){
		for(int j = 0; j < B.length(); j++){
			if(i && A[i - 1] != A[i])
				dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][0]);
			if(i && B[j] != A[i])
				dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][1]);
			if(A[i] != B[j])
				dp[i][j][0] = add(dp[i][j][0], w[j][1]);
			if(j && A[i] != B[j])
				dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][0]);
			if(j && B[j - 1] != B[j])
				dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][1]);
			if(A[i] != B[j])
				dp[i][j][1] = add(dp[i][j][1], w[i][0]);
			ans = add(ans, add(dp[i][j][0], dp[i][j][1]));
			//cout << "dp[" << i << "][" << j << "][0] = " << dp[i][j][0] << ",1 = " << dp[i][j][1] << endl;
		}
	}
	cout << ans << endl;
}
