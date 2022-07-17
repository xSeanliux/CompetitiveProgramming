#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
signed main(){
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		int ans = 1;
		for(int i = 0; i < K; i++){
			ans = (ans * N) % MOD;
		}
		cout << ans << endl;
	}
}
