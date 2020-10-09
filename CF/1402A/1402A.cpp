#include <iostream>
#include <stack>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 2e5 + 326;
stack<pii> stk;

int N, W[maxN], H[maxN], ans, sum, inv2 = (1e9 + 8) / 2, cw, tw;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a > b ? a - b : a - b + MOD);
}

inline int C2(int x){
	return x * (x - 1) % MOD * inv2 % MOD;
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> H[i];
	for(int i = 0; i < N; i++) cin >> W[i];
	for(int i = 0; i < N; i++){
		int w = W[i], h = H[i];
		tw = add(tw, w);
		ans = add(ans, C2(w + 1) * C2(h + 1) % MOD);
		//cout << "ans += " << C2(w + 1) * C2(h + 1) % MOD << endl;
		while(stk.size() && stk.top().S >= h){
			stk.top().F %= MOD;
			stk.top().S %= MOD;
			sum = sub(sum, C2(stk.top().S + 1) * stk.top().F % MOD);
			cw = sub(cw, stk.top().F);
			ans = add(ans, (w * stk.top().F % MOD) * C2(h + 1) % MOD);
			stk.pop();
		}
		ans = add(ans, sum * w % MOD);
		w = sub(tw, cw);
		sum = add(sum, C2(h + 1) * w % MOD);
		//cout << "sum now " << sum << endl;
		stk.push({w, h});
		//cout << "Pushing " << w << ", " << h << endl;
		cw = tw;
	}
	cout << ans << endl;
}
