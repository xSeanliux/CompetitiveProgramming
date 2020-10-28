#include <iostream>
using namespace std;

const int maxN = 1e5 + 326;
int x[maxN], y[maxN], t[maxN], dp[maxN], r, N, ans;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

int main(){
	cin >> r >> N;
	x[0] = y[0] = 1;
	for(int i = 1; i <= N; i++) cin >> t[i] >> x[i] >> y[i];
	int curmax = -maxN;
	for(int i = 1; i <= N; i++){
		dp[i] = -maxN;
		for(int j = i - 1; j >= 0 && i - j <= 2 * r; j--){
			if(Abs(x[i] - x[j]) + Abs(y[i] - y[j]) <= t[i] - t[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if(i >= 2 * r){
			dp[i] = max(dp[i], curmax + 1);
			curmax = max(curmax, dp[i - 2 * r]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

