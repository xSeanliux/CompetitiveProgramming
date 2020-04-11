#include <iostream>
#define int long long int
using namespace std;

const int maxLog = 40;
int Q, d, m, sz[maxLog];

inline void solve(){
	int l;
	for(l = 1; (1LL << (l - 1)) <= d; l++){
		sz[l] = (1LL << (l - 1));
		if(d < (1LL << (l))){
			sz[l] = d - (1 << (l - 1)) + 1;
			break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= l; i++){
		ans = (ans + ans * sz[i] % m + sz[i]) % m; 
	}
	cout << ans << endl;
}

signed main(){
	cin >> Q;
	while(Q--){
		cin >> d >> m;
		solve();
	}
}
