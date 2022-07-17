#include <iostream>
#include <algorithm>
#include <fstream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define cin infile
#define cout outfile
using namespace std;

const int maxN = 21;

int dp[1 << maxN], N, C[maxN], l[maxN], st[maxN][1004], L, D[maxN], bc[1 << maxN];

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("movie.in");
	outfile.open("movie.out");
}

signed main(){
	IO();
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		cin >> D[i] >> C[i];
		for(int j = 0; j < C[i]; j++) cin >> st[i][j];
	}
	dp[0] = 0;
	int ans = maxN;
	for(int i = 1; i < (1 << N); ++i){
		bc[i] = bc[i - (i & -i)] + 1;
		for(int j = 0; j < N; ++j){
			if((i >> j) & 1){ //maybe use lowbit
				int t = dp[i ^ (1 << j)];
				int find = upper_bound(st[j], st[j] + C[j], t) - st[j];
				if(find){
					--find;
					dp[i] = max(dp[i], max(st[j][find] + D[j], dp[i ^ (1 << j)]));
				} 
			}
		}
		if(dp[i] >= L) ans = min(ans, bc[i]);
		//cout << "bc[" << i << "] = " << bc[i] << endl;
		//cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	cout << (ans == maxN ? -1 : ans) << endl;
}
