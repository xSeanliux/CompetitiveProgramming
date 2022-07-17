#include <iostream>
#define int long long int 
using namespace std;

const int MOD = 1e9 + 7, I2 = 5e8 + 4;
int N, ans;

inline int add(int a, int b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

signed main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		int j = N / (N / i);
		int c = (j - i + 1) % MOD;
		c = c * ((i + j) % MOD) % MOD;
		c = c * I2 % MOD;
		c = c * (N / i) % MOD;
		//cout << i << " - " << j << ": " << N / i << endl;
		ans = add(ans, c);	
		i = j;
	}
	cout << ans << endl;
}
