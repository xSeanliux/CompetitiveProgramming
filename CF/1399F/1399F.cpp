#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int T, N, l, r;

vector<pii> segs; 
vector<int> ei[6000 + 26], lisan;

int dp[6026][6026];

inline void solve(){
	cin >> N;
	vector<pii>().swap(segs);
	vector<int>().swap(lisan);
	for(int i = 0; i < 2 * N; i++){
		vector<int>().swap(ei[i]);
	}
	for(int i = 0; i < N; i++){
		cin >> l >> r;
		segs.emplace_back(l, r);
		lisan.push_back(l);
		lisan.push_back(r);
	}
	sort(lisan.begin(), lisan.end());
	int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(auto &p : segs){
		p.F = lower_bound(lisan.begin(), lisan.begin() + sz, p.F) - lisan.begin() + 1;
		p.S = lower_bound(lisan.begin(), lisan.begin() + sz, p.S) - lisan.begin() + 1;
		ei[p.S].push_back(p.F);
	}
	for(int i = 1; i <= sz; i++){
		sort(ei[i].begin(), ei[i].end(), greater<int>());
		for(int j = 1; j <= sz; j++){
			dp[i][j] = 0;
		}
	}
	int ans = 0;
	for(int j = 1; j <= sz; j++){
		for(int i = j; i; i--){
			dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
		for(int s : ei[j]){
			dp[s][j]++;
			for(int i = 1; i < s; i++) dp[i][j] = max(dp[i][j], dp[i][s - 1] + dp[s][j]);
		}
	}
	for(int i = 1; i <= sz; i++) for(int j = i; j <= sz; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;
}

	
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
