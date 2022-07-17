#include <iostream>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326, MOD = 1e9 + 7;
int N, p[maxN], e[maxN], ndiv2[maxN][2];

inline int modexp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline int inv(int x){
	return modexp(x, MOD - 2);
}

signed main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> p[i] >> e[i];
	}
	int sdiv = 1, ndiv = 1, pdiv = 1;
	ndiv2[0][0] = ndiv2[N + 1][1] = 1;
	for(int i = 1; i <= N; i++){
		ndiv = ndiv * (e[i] + 1) % MOD;
		sdiv = sdiv * (((modexp(p[i], e[i] + 1) + MOD - 1) % MOD) * inv(p[i] - 1) % MOD) % MOD;
		ndiv2[i][0] = ndiv2[i - 1][0] * (e[i] + 1) % (MOD - 1);
		ndiv2[N - i + 1][1] = ndiv2[N - i + 2][1] * (e[N - i + 1] + 1) % (MOD - 1);
	}
	cout << ndiv << " " << sdiv << " ";
	for(int i = 1; i <= N; i++){
		int a = e[i] * (e[i] + 1) / 2 % (MOD - 1), b = ndiv2[i - 1][0] * ndiv2[i + 1][1] % (MOD - 1); 
		//cout << p[i] << "^(" << a << "*" << b << ")" << endl; 
		int k = modexp(p[i], a * b % (MOD - 1));
		pdiv = (pdiv * k % MOD); 
	}
	cout << pdiv << endl;
}
