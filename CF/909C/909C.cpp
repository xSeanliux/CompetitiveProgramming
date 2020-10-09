#include <iostream>
using namespace std;

const int maxN = 5e3 + 326, MOD = 1e9 + 7;

int N, dp[maxN], nxtdp[maxN];
char c[maxN];

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> c[i];
	dp[0] = 1;
	for(int i = 1; i < N; i++){
		if(c[i - 1] == 'f'){
			for(int j = 1; j < N; j++){
				nxtdp[j] = dp[j - 1];
			}
		} else {
			int s = 0;
			for(int j = N; j >= 0; j--){
				s = add(s, dp[j]);
				nxtdp[j] = s;
			}
		}
		for(int j = 0; j <= N; j++){
			dp[j] = nxtdp[j];
			nxtdp[j] = 0;
			//cout << "dp[" << i << "][" << j << "] = " << dp[j] << endl;	
		}
	}
	int a = 0;
	for(int i = 0; i <= N; i++) a = add(a, dp[i]);
	cout << a << endl;
}
