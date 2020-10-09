#include <iostream>
#include <iomanip>
#define double long double
using namespace std;

const int maxN = 8e3 + 326;
int T, N, c;
double P, dp[maxN][maxN];

inline double C2(int a){
	return a * 1.0 * (a - 1) / 2.0;
}
inline void solve(){
	cin >> N >> P;
	for(int j = 1; j <= N; j++)
		for(int i = 1; i <= j; i++) dp[i][j] = 0;

	for(int j = 2; j <= N; j++){
		for(int i = 1; i <= j; i++){
			//Didn't choose me
			dp[i][j] += C2(j - i) / C2(j) * (dp[i][j - 1] + 1);
			dp[i][j] += C2(i - 1) / C2(j) * (dp[i - 1][j - 1] + 1);
			dp[i][j] += (i - 1) * (j - i) / C2(j) * (1 - P) * (dp[i][j - 1] + 1);
			dp[i][j] += (i - 1) * (j - i) / C2(j) * P * (dp[i - 1][j - 1] + 1);

			//Chose me and I won
			dp[i][j] += (i - 1) * P * (dp[i - 1][j - 1] + 1) / C2(j);
			dp[i][j] += (j - i) * (1 - P) * (dp[i][j - 1] + 1) / C2(j);

			//Chose me and I lost 
			dp[i][j] += (i - 1) * (1 - P) * 1 / C2(j);
			dp[i][j] += (j - i) * (P) * 1 / C2(j);
		}
	}
	cout << "Case #" << ++c << ":\n";
	for(int i = 1; i <= N; i++){
		cout << fixed << setprecision(10) << dp[i][N] << '\n';
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
