#include <iostream>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326, M = 998244353;
int T, N, K, arr[maxN], pos[maxN], ord[maxN];
int can[maxN];

inline void solve(){
	cin >> N >> K;
	int ans = 1;
	fill(can, can + N + 1, 1);
	can[0] = can[N + 1] = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	for(int i = 0; i < K; i++){
		cin >> ord[i];
		can[pos[ord[i]]] = 0;
	}
	for(int i = 0; i < K; i++){
		int p = pos[ord[i]];
		ans = ans * (can[p - 1] + can[p + 1]) % M;
		//for(int j = 1; j <= N; j++) cout << can[j] << " \n"[j == N];
		can[p] = 1;
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
