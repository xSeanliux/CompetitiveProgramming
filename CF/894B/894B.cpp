#include <iostream>
#define int unsigned long long int
using namespace std;

const int MOD = 1e9 + 7;

inline int exp(int b, int e, int M){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % M;
		b = b * b % M;
	}
	return r;
}

int N, M, K;

signed main(){
	cin >> N >> M >> K;
	if((N ^ M) & 1 && K == -1){
		cout << 0 << endl;
		return 0;
	}
	N--, M--;
	N %= (MOD - 1);
	M %= (MOD - 1);
	N = exp(2, N * M % (MOD - 1), MOD);
	cout << N << endl;
}
