#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e6 + 326, M = 1e9 + 7;
int fact[maxN], ifact[maxN];

inline int modexp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % M;
		b = b * b % M;
	}
	return r;
}

inline int inv(int x){
	return modexp(x, M - 2);
}

inline int C(int n, int k){
	return (fact[n] * ifact[k] % M) * ifact[n - k] % M;
}

inline int add(int a, int b){
	return (a + b >= M ? a + b - M : a + b);
}

signed main(){
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < maxN; i++){
		fact[i] = i * fact[i - 1] % M;
		ifact[i] = inv(fact[i]);
	}
	int N;
	cin >> N;
	int num = 0, den = 0;
	for(int k = 0; k <= N - 2; k++) num = add(num, (C(N - 2, k) * modexp(N - 1, N - 2 - k) % M) * ((k) * (k + 1) % M) % M);
	//cout << "num = " << num << endl;
	den = inv(modexp(N, N - 3)) * inv(2) % M;
	cout << num * den % M << endl;
}

