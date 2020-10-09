#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MOD = 1e9 + 7;

vector<int> vec, lis, arr;

int N, l, k, x, ans;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

signed main(){
	ericxiao;
	cin >> N >> l >> k;
	//cout << "len = " << len << endl;
	vec.resize(N);
	for(int i = 0; i < N; i++){
		cin >> vec[i];
		lis.push_back(vec[i]);
	}
	sort(lis.begin(), lis.end());
	int sz = unique(lis.begin(), lis.end()) - lis.begin();
	for(int &x : vec){
		x = lower_bound(lis.begin(), lis.begin() + sz, x) - lis.begin();
	}
	int blocks = (l + N - 1) / N, maxLen = min(blocks, k);
	int dp[N], nxtdp[N], extra = (l % N ? l % N : N);
	fill(dp, dp + N, 0);
	fill(nxtdp, nxtdp + N, 0);

	int ans = l % MOD;
	
	for(int x : vec) dp[x]++;
	
	for(int len = 2; len <= maxLen; len++){
		for(int i = 1; i < N; i++) dp[i] = add(dp[i], dp[i - 1]);
		for(int x : vec){
			ans = add(ans, dp[x] * ((blocks - len) % MOD) % MOD);
		}
		for(int i = 0; i < extra; i++){
			ans = add(ans, dp[vec[i]]);
		}
		for(int x : vec){
			nxtdp[x] = add(nxtdp[x], dp[x]);
		}
		for(int i = 0; i < N; i++){
			dp[i] = nxtdp[i];
			nxtdp[i] = 0;
		}
	}
	cout << ans << endl;
}

/*
 *
 * 1 1000000000000000000 1
   508953607


   49
*/
