#include <iostream>
using namespace std;

const int maxN = 500 + 326;
int T, t, M, a[maxN], b[maxN];

struct Obj{
	int val, last;
	Obj(){}
	Obj(int a = 0, int b = -1): val(a), last(b){}
} dp[maxN][maxN];

void solve(){
	cin >> M;
	for(int i = 1; i <= M; i++) cin >> a[i];
	for(int i = 1; i <= M; i++) cin >> b[i];
	for(int i = 1; i <= M; i++) for(int j = 1; j <= M; j++){
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	
		if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][i - 1] + 1);
	}
	cout << M - dp[M][M] << endl;
}

int main(){
	cin >> T >> t;
	while(T--){
		solve();
	}
}
