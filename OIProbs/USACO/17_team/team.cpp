#include <iostream>
#include <algorithm>
#include <fstream>
#define cin infile
#define cout outfile
using namespace std;

const int maxN = 1e3 + 326, MOD = 1e9 + 9;

int dp[maxN][maxN], fj[maxN], fp[maxN], M, N, K, lim[maxN], last[maxN][maxN];

ifstream infile;
ofstream outfile;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

signed main(){
	infile.open("team.in");
	outfile.open("team.out");
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++) cin >> fj[i]; 
	for(int i = 1; i <= M; i++) cin >> fp[i]; 
	sort(fj + 1, fj + N + 1);
	sort(fp + 1, fp + M + 1);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(fj[i] > fp[j]) last[i][j] = add(last[i][j], 1);
			last[i][j] = add(add(last[i - 1][j], last[i][j - 1]), add(last[i][j], MOD - last[i - 1][j - 1]));
		}
	}
	K--;
	while(K--){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(fj[i] > fp[j]){
					dp[i][j] = last[i - 1][j - 1];
				}
				dp[i][j] = add(add(dp[i - 1][j], dp[i][j - 1]), add(dp[i][j], MOD - dp[i - 1][j - 1]));
			}
		}
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++){
			last[i][j] = dp[i][j];
			dp[i][j] = 0;
		}
	}
	cout << last[N][M] << endl;
}
