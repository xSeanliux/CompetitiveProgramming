#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e6 + 226, M = 998244353 ;
int N, p, k, coefs[maxN], fact[maxN], invfact[maxN];

long long MOD(long long x) {
    if((x %= M) < 0) x += M;
    return (x < M-x) ? x : x - M;
}

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1){
			r = (r * b) % M;
		}
		b = b * b % M;
	}
	return r;
}

signed main(){
	ericxiao;
	cin >> N >> p >> k;
	fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
	for(int i = 2; i <= N; i++){
		fact[i] = i * fact[i - 1] % M;
		invfact[i] = exp(fact[i], M - 2);
	}
	for(int i = 0; i <= N; i++){
		cin >> coefs[i];
		coefs[i] = (MOD(coefs[i]) + M) % M;
	}
	int ans = 0;
	for(int i = N; i >= k - 1; i--){
		ans = (((fact[i] * invfact[i - k + 1]) % M * coefs[i] % M) + ans * p % M) % M;	
	}
	cout << MOD(ans * invfact[k - 1]) << endl;
}
