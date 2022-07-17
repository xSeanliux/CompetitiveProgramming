#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;
int N, K, dist[maxN];

inline pii get(int p){
	pii dp[N + 10];
	pii cur = {0 - dist[0], 0};
	dp[0] = {0, 0};
	for(int i = 1; i < N; i++){
		dp[i] = dp[i - 1];	
		pii tmp = cur;
		tmp.F += dist[i] - p;
		tmp.S++;
		dp[i] = min(dp[i], tmp);
		cur = min(cur, {dp[i - 1].F - dist[i], dp[i - 1].S});
	}
	return dp[N - 1];
}

signed main(){
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> dist[i];
	int p = 0;
	for(int i = 30; i >= 0; i--){
		auto [fx, x] = get(p + (1LL << i));
		x = x;
		if(x <= K) p += (1LL << i);
	}
	auto [fx, x] = get(p); 
	cout << fx + K * p << endl;
}

