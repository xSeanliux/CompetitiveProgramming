#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 326, MOD = 1e9 + 7;
int N, M, ans;

int l[maxN], r[maxN], x[maxN], dp[maxN][maxN][maxN];
vector<int> rights[maxN];

inline int add(int a, int b){
	return (a + b) >= MOD ? a + b - MOD : a + b;
}

signed main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> l[i] >> r[i] >> x[i];
		rights[r[i]].push_back(i);
	}
	for(int r = 0; r <= N; r++){
		for(int g = 0; g <= N; g++){
			for(int b = 0; b <= N; b++){
				if((r && g && r == g) || (r && b && r == b) || (g && b && g == b)) continue;
				int k = max(r, max(g, b));	
				bool f = true;
				for(int i : rights[k]){
					int xv = (r >= l[i]) + (g >= l[i]) + (b >= l[i]); 
					if(xv != x[i]){
						dp[r][g][b] = 0;
						f = false;
						break;
					}
				}
				if(r == 1&& !g && !b) dp[r][g][b] = f;
				if(!r && g == 1 && !b) dp[r][g][b] = f;
				if(!r && !g && b == 1) dp[r][g][b] = f;
				//cout << "dp[" << r << "][" << g << "][" << b << "] = " << dp[r][g][b] << endl;
				if(!f){
					dp[r][g][b] = 0;
					continue;
				}
				dp[k + 1][g][b] = add(dp[k + 1][g][b], dp[r][g][b]);
				dp[r][k + 1][b] = add(dp[r][k + 1][b], dp[r][g][b]);
				dp[r][g][k + 1] = add(dp[r][g][k + 1], dp[r][g][b]);
				if(k == N){
					ans = add(ans, dp[r][g][b]);
				}
			}
		}
	}
	cout << ans << endl;
}
