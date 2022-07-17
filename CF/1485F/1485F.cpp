#include <iostream>
#include <map>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326, MOD = 1e9 + 7;

int arr[maxN], pre[maxN], dp[maxN][2];

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a >= b ? a - b : a - b + MOD);
}

inline void solve(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		dp[i][0] = dp[i][1] = 0;
		cin >> arr[i];
		pre[i] = arr[i] + pre[i - 1];
	}
	int all = 0;
	map<int, int> mp = map<int, int>();
	for(int i = 1; i <= N; i++){
		dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = all;
		if(mp.count(pre[i - 1]))
			dp[i][1] = sub(dp[i][1], mp[pre[i - 1]]);
		/*
		for(int j = 1; j < i; j++){
			if(pre[j - 1] != pre[i - 1]) dp[i][1] = add(dp[i][1], dp[j][1]);
		}
		*/
		if(pre[i - 1] != 0) dp[i][1] = add(dp[i][1], 1);
		all = add(all, dp[i][1]);
		if(mp.count(pre[i - 1])){
			mp[pre[i - 1]] = add(mp[pre[i - 1]], dp[i][1]);
		} else {
			mp[pre[i - 1]] = dp[i][1];
		}
	}
	cout << add(dp[N][0], dp[N][1]) << endl;
}

signed main(){
	dp[0][0] = 1;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}

