#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e6 + 226, MOD = 1e9 + 7;
int dp[maxN][2], T, N;

signed main(){
	ericxiao;
	for(int i = 3; i < maxN; i++){
		dp[i][0] = (2 * max(dp[i - 2][0], dp[i - 2][1]) + max(dp[i - 1][0], dp[i - 1][1])) % MOD;	
		dp[i][1] = (2 * dp[i - 2][0] + dp[i - 1][0] + 4) % MOD;
	}
	cin >> T;
	while(T--){
		cin >> N;
		cout << max(dp[N][0], dp[N][1]) << '\n';
	}
}
