#include <iostream>
#define int long long int
using namespace std;

const int maxN = 326;
int C, T, M, P[maxN], N[maxN], ans;

void dfs(int now, int prd, int sum){
	if(now == M){
		if(prd == sum){
			ans = max(ans, sum);
		}
		return;
	}
	int rol = 1;
	for(int t = 0; t <= N[now]; t++){
		if((sum - t * P[now]) / rol < prd) return;
		dfs(now + 1, prd * rol, sum - t * P[now]);
		rol *= P[now];
	}
}

inline void solve(){
	cin >> M;
	int sum = 0;
	ans = 0;
	for(int i = 0; i < M; i++){
		cin >> P[i] >> N[i];
		sum += P[i] * N[i];
	}
	dfs(0, 1, sum);
	cout << "Case #" << ++C << ": " << ans << endl;
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
