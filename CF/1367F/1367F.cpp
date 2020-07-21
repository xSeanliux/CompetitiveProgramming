#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 10;

int t, N, arr[maxN], dp[maxN][2], lis[maxN], has[maxN], cnt[maxN];
//dp[0]: max
//dp[1]: use everything of i
void solve(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		lis[i] = arr[i];
		dp[i][0] = dp[i][1] = 0;
		cnt[i] = has[i] = 0;
	}
	sort(lis, lis + N);
	int sz = unique(lis, lis + N) - lis;
	for(int i = 0; i < N; i++){
		arr[i] = lower_bound(lis, lis + sz, arr[i]) - lis;
		cnt[arr[i]]++;
	}
	for(int i = 0; i < N; i++){
		has[arr[i]]++;
		if(has[arr[i]] == 1){
			if(arr[i]){
				dp[arr[i]][1] = max(dp[arr[i] - 1][1], dp[arr[i] - 1][0]);
			}
		}
	}
	//for(int i = 0; i < N; i++) cout << "dp[" << i << "] = " << dp[i] << endl;
	int mx = 0;
	for(int i = 0; i < N; i++) mx = max(mx, max(dp[i][1], dp[i][0]));
	cout << N - mx << endl;
}

int main(){
	cin >> t;
	while(t--){
		solve();
	}
}
