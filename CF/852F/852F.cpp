#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;
int N, M, a, Q, fact[maxN], ifact[maxN], pas[maxN], phi, ans[maxN];

inline int exp(int b, int e, int m){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1){
			r = r * b % m;
		}
		b = b * b % m;
	}
	return r;
}

signed main(){
	cin >> N >> M >> a >> Q;
	for(phi = 1;; phi++){
		if(exp(a, phi, Q) == 1){
			break;
		}
	}
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < maxN; i++){
		fact[i] = i * fact[i - 1] % phi;
		ifact[i] = exp(fact[i], phi - 2, phi);
	}
	for(int i = 0; i <= M; i++) {
		pas[i] = (fact[M] * ifact[i] % phi) * ifact[M - i] % phi;
	}
	for(int i = 0; i < N; i++){
		if(i) pas[i] = (pas[i - 1] + pas[i]) % phi;
		ans[i] = exp(a, pas[i], Q);
	}
	for(int i = N - 1; i >= 0; i--) cout << ans[i] << " ";	
}

