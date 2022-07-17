#include <iostream>
#define int long long int
using namespace std;

const int maxB = 126, maxC = 1e4 + 326, MOD = 998244353;
int ways[maxB][maxC], g, v, a, b, c, Q, N, B;

inline int add(int a, int b){
	return (a + b < MOD) ? a + b : a + b - MOD;
}

signed main(){
	cin >> B >> N >> Q;
	for(int i = 1; i <= B; i++) ways[i][0] = 1;
	for(int i = 0; i < N; i++){
		cin >> g >> v;
		for(int i = maxC - v - 1; i >= 0; i--){
			ways[g][i + v] = add(ways[g][i + v], ways[g][i]);	
		}
	}
	while(Q--){
		cin >> a >> b >> c;
		int r = 0;
		for(int i = 0; i <= c; i++){
			r = add(r, ways[a][i] * ways[b][c - i] % MOD);
		}
		cout << r << endl;
	}
}
