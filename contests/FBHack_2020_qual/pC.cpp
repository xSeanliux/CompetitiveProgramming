#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int T, N, p, h, c;
vector<int> le, re;
map<int, vector<int> > lstarts, rstarts;
map<int, int> ldp, rdp;

inline void solve(){
	cin >> N;
	vector<int>().swap(le);
	vector<int>().swap(re);
	lstarts = map<int, vector<int> >();
	rstarts = map<int, vector<int> >();
	ldp = map<int, int>();
	rdp = map<int, int>();
	for(int i = 0; i < N; i++){
		cin >> p >> h;
		le.push_back(p - h);
		re.push_back(p + h);
		lstarts[p - h].push_back(p);
		rstarts[p + h].push_back(p);
	}
	sort(le.begin(), le.end(), greater<int>() );
	sort(re.begin(), re.end());
	for(int e : re){
		rdp[e] = 0;
		for(int s : rstarts[e]){
			rdp[e] = max(rdp[e], (e - s) + (rdp.count(s) ? rdp[s] : 0));
		}
	}
	for(int e : le){
		ldp[e] = 0;
		for(int s : lstarts[e]){
			ldp[e] = max(ldp[e], (s - e) + (ldp.count(s) ? ldp[s] : 0));
		}
	}
	int ans = 0;
	for(auto [i, dp] : ldp){
		ans = max(ans, dp + (rdp.count(i) ? rdp[i] : 0));
	}
	for(auto [i, dp] : rdp){
		ans = max(ans, dp + (ldp.count(i) ? ldp[i] : 0));
	}
	cout << "Case #" << ++c << ": " << ans << endl;
}

int main(){
	ericxiao;
	cin >> T;
	while(T--){
		solve();
	}
}
