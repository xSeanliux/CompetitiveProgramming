#pragma gcc optimize ("O3")
#include <iostream>
#include <fstream>
#define cin infile
#define cout outfile
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 326, INF = 1e9;

int N, M, dp[maxN][maxN], upd[maxN][maxN][maxN], l, r, x;

ifstream infile;
ofstream outfile;


int main(){
	ericxiao
	int i, j, k, m;
	infile.open("pieaters.in");
	outfile.open("pieaters.out");
	cin >> N >> M;
	for(i = 0; i < M; i++){
		cin >> x >> l >> r;
		for(m = l; m <= r; m++) upd[l][r][m] = max(upd[l][r][m], x);
	}
	for(i = N; i; i--) for(j = i; j <= N; j++) for(k = i; k <= j; k++){
		upd[i][j][k] = max(upd[i][j][k], max(upd[i][j - 1][k], upd[i + 1][j][k]));
	}
	int ans = 0;
	for(i = N; i; i--){
		for(j = i; j <= N; j++){
			for(k = i; k <= j; k++) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			for(k = i; k <= j; k++) dp[i][j] = max(dp[i][j], dp[i][k - 1] + upd[i][j][k] + dp[k + 1][j]);
		}
	}
	cout << dp[1][N] << '\n';
}
