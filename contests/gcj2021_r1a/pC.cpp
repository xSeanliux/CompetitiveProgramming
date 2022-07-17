#include <iostream>
#include <algorithm>
#include <string.h>
#define int long long int
using namespace std;

const int maxQ = 26;
int T, C, N, Q, sc[2];
string ans[2];

int gcd(int a, int b){
	return !b ? a : gcd(b , a % b);
}

struct Frac{
	int a, b;
	Frac(){}
	Frac(int a, int b): a(a), b(b){
		if(b < 0){
			a = -a;
			b = -b;
		}
		int g = gcd(a, b);
		if(!g) return;
		a /= g;
		b /= g;
	}
	Frac operator+(const Frac &f) {
		return Frac(a*f.b + f.a*b, b * f.b); 
	}
	Frac operator-(const Frac &f) {
		return Frac(a*f.b - f.a*b, b * f.b); 
	}
	Frac operator*(const Frac &f) {
		return Frac(a * f.a, b * f.b);
	}
	const bool operator<(const Frac &f) const {
		return a * f.b < f.a * b;
	}
};

struct Obj{
	Frac ev;
	bool putT; 
	int cnt;
	Obj(){
		ev = Frac(0, 1);
		cnt = 0;
		putT = false;
	}
} dp[maxQ][maxQ][maxQ];

inline void solve(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> ans[i] >> sc[i];
		ans[i] = 'Z' + ans[i];
	}
	Q++;
	if(N == 1){
		ans[1] = ans[0];
		sc[1] = sc[0];
	}
	for(int i = 0; i < Q; i++) for(int j = 0; j < Q; j++) for(int k = 0; k < Q; k++){
		dp[i][j][k].ev = Frac(-1000000, 1);
	}
	dp[0][0][0] = Obj();
	dp[0][0][0].cnt = 1;
	Frac pt, pf;
	for(int i = 1; i < Q; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= i; k++){
				dp[i][j][k].cnt = 0;
				pt = pf = Frac(-1, -1);	
				if((j - (ans[0][i] == 'T')) >= 0 && (k - (ans[1][i] == 'T')) >= 0){
					dp[i][j][k].cnt += dp[i - 1][j - (ans[0][i] == 'T')][k - (ans[1][i] == 'T')].cnt;
				}
				if((j - (ans[0][i] == 'F')) >= 0 && (k - (ans[1][i] == 'F')) >= 0){
					dp[i][j][k].cnt += dp[i - 1][j - (ans[0][i] == 'F')][k - (ans[1][i] == 'F')].cnt;
				}
				if((j - (ans[0][i] == 'T')) >= 0 && (k - (ans[1][i] == 'T')) >= 0){
					pt = (dp[i - 1][j - (ans[0][i] == 'T')][k - (ans[1][i] == 'T')].ev + Frac(1, 1)) * Frac(dp[i - 1][j - (ans[0][i] == 'T')][k - (ans[1][i] == 'T')].cnt, dp[i][j][k].cnt);
				}
				if((j - (ans[0][i] == 'F')) >= 0 && (k - (ans[1][i] == 'F')) >= 0){
					pf = (dp[i - 1][j - (ans[0][i] == 'F')][k - (ans[1][i] == 'F')].ev + Frac(1, 1)) * Frac(dp[i - 1][j - (ans[0][i] == 'F')][k - (ans[1][i] == 'F')].cnt, dp[i][j][k].cnt);
				}
				if(pf < pt){
					dp[i][j][k].ev = pt;
					dp[i][j][k].putT = true;	
				} else {
					dp[i][j][k].ev = pf;
					dp[i][j][k].putT = false;	

				}
				cout << "ev of " << i << ", " << j << ", " << k << " is " << dp[i][j][k].ev.a << "/" << dp[i][j][k].ev.b << ", putT: " << dp[i][j][k].putT << ",cnt = " << dp[i][j][k].cnt << endl;
			}
		}
	}
	string bestAns = "";
	int A = sc[0], B = sc[1];
	for(int i = Q - 1; i; i--){
		if(dp[i][A][B].putT){
			bestAns += 'T';
			A -= (ans[0][i] == 'T');
			B -= (ans[1][i] == 'T');
		} else {
			bestAns += 'F';
			A -= (ans[0][i] == 'F');
			B -= (ans[1][i] == 'F');
		}
	}
	reverse(bestAns.begin(), bestAns.end());
	cout << "Case #" << ++C << ": " << bestAns << " " << dp[Q - 1][sc[0]][sc[1]].ev.a << "/" << dp[Q - 1][sc[0]][sc[1]].ev.b << endl;
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}

