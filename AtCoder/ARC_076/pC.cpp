#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 1e5 + 326;

int A, B, fact[maxN];

signed main(){
	fact[0] = 1;
	for(int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i % MOD;
	cin >> A >> B;
	if(A < B) swap(A, B);
	if(A > B + 1){
		cout << 0 << endl;
		return 0;
	}
	if(A == B + 1){
		cout << fact[A] * fact[B] % MOD << endl;
	} else {
		cout << 2 * fact[A] * fact[B] % MOD << endl;
	}
}
