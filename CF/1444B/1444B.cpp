#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 3e5 + 326, MOD = 998244353;
int N, arr[maxN], r, fact[maxN];

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a >= b ? a - b : a - b + MOD);
}

inline int modpow(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1){
			r = r * b % MOD;
		}
		b = b * b % MOD;
	}
	return r;
}

inline int inv(int x){
	return modpow(x, MOD - 2);
}

inline int C(int n, int k){
	return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

signed main(){
	cin >> N;
	fact[0] = 1;
	for(int i = 1; i <= 2 * N; i++) fact[i] = i * fact[i - 1] % MOD;
	for(int i = 0; i < 2 * N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + 2 * N);
	for(int i = 0; i < 2 * N; i++){
		arr[i] %= MOD;
	}
	int ans = 0;
	for(int i = 0; i < N; i++) ans = sub(ans, arr[i]);
	for(int i = N; i < 2 * N; i++) ans = add(ans, arr[i]);
	cout << C(2 * N, N) * ans % MOD << endl;
}
