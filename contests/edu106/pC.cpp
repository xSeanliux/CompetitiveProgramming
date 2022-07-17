#include <iostream>
#include <set>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int T, vars[maxN];

inline void solve(){
	int N, sa = 0, sb = 0, sza = 0, szb = 0;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> vars[i];
	int minnum[2];
	sa = vars[0];
	sb = vars[1];
	minnum[0] = vars[0];
	minnum[1] = vars[1];
	sza = szb = 1;
	int ans = N * (vars[0] + vars[1]);
	for(int i = 2; i < N; i++){
		minnum[i & 1] = min(minnum[i & 1], vars[i]);
		(i & 1 ? sb : sa) += (vars[i]);
		(i & 1 ? szb : sza) += 1;
		ans = min(ans, sa + sb + (N - sza) * (minnum[0]) + (N - szb) * (minnum[1]));
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
