#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
int go[2][2] = {
	{2, 2},
	{0, 4}
}, cur[2][2], ret[2][2] = {
	{1, 0},
	{0, 1}
};

int N, D;

inline int modpow(int b, int e){
	int r = 1;
	for(int i = 0; i < 64; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

signed main(){
	cin >> N >> D;	
	cout << modpow(4, D) << endl;
}
