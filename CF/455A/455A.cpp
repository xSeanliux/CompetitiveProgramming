#include <iostream>
#include <map>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;
map<int,int> mp;
int N, x, dp[maxN][2];
vector<int> num, amnt;

signed main(){
	cin >> N;
	while(N--){
		cin >> x;
		mp[x]++;
	}
	N = mp.size();
	for(auto p : mp){
		num.push_back(p.first);
		amnt.push_back(p.second);
	}
	dp[0][0] = 0;
	dp[0][1] = num[0] * amnt[0];
	int ans = dp[0][1];
	for(int i = 1; i < N; i++){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);	
		if(num[i - 1] + 1 == num[i]){
			dp[i][1] = max(dp[i][1], dp[i - 1][0] + num[i] * amnt[i]);
		} else {
			dp[i][1] = max(dp[i][1], max(dp[i - 1][0], dp[i - 1][1]) + num[i] * amnt[i]);
		}
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans << endl;
}
