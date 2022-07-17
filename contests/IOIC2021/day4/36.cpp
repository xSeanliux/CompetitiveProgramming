#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
int N;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

signed main(){
	cin >> N;
	int ans = 0;
	int cnt = (N + MOD - 1) % MOD;
	for(int k = 2; k * k <= N; k++){
		//cout << "k = " << k << endl;
		cnt--;
		if(cnt == -1) cnt = MOD - 1;
		int cur = 1, nxt = k, lv = 0;	
		while(true){
			ans = add(ans, (min(nxt, N + 1) - cur) * lv % MOD);
			//cout << "for log_" << k << ", " << cur << " to " << min(nxt, N + 1) << " add\n";
			if(cur > N / k) break;
			cur *= k;
			lv++;
			nxt *= k;
		}
	}
	ans = add(ans, (cnt) * (cnt + 1) / 2 % MOD);
	cout << ans << endl;
}
