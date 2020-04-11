#include <iostream>
#define int long long int
using namespace std;

const int MOD = 998244353;

inline int mpow(int b, int e){
	e %= (MOD - 1);
	b %= MOD;
	if(!b) return 0;
	if(!e) return 1;
	int r = 1, c = b;  
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1){
			r = r * c % MOD;
		}
		c = c * c % MOD;
	}
	return r;
}

inline int inv(int x){
	return mpow(x, MOD - 2);
}

int f(int a, int b){ //(1 + a)^b
	return mpow((1 + a + MOD) % MOD, b);
}


int N, M, L, R, E, O, ans, ans2;

signed main(){
	cin >> N >> M >> L >> R;
	if(L == R){
		cout << 1 << endl;
		return 0;
	}
	E = (R - L + 1) / 2;	 
	O = (R - L + 2) / 2;
	if(((R - L + 1) & 1) && (L & 1) == 0) swap(E, O);
	int x = E * inv(O) % MOD;
	ans = (f(x, N * M) + f((MOD - x) % MOD, N * M)) % MOD;
	ans = ans * inv(2LL) % MOD;
	ans = ans * mpow(O, N * M) % MOD;
	if((N * M) & 1){
		x = O * inv(E) % MOD;
		ans2 = (f(x, N * M) + f((MOD - x) % MOD, N * M)) % MOD;
		ans2 = ans2 * inv(2LL) % MOD;
		ans2 = ans2 * mpow(E, N * M) % MOD;
	}
	cout << (ans + ans2) % MOD << endl;
}
