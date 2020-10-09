#include <iostream>
#include <math.h>
#include <iomanip>
#define double long double
using namespace std;

const int maxN = 3260;
int N;

double x[maxN], y[maxN], dp[maxN][maxN][2];

inline double d(int i, int j){
	return hypot(x[i] - x[j], y[i] - y[j]);
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for(int l = 1; l < N; l++){
		for(int i = 0; i < N; i++){
			if(l == 1){
				dp[i][i][0] = dp[i][i][1] = 0;
				continue;
			}
			int r = (i + l - 1) % N;
			dp[i][r][0] = max(dp[(i + 1) % N][r][0] + d(i, (i + 1) % N), dp[(i + 1) % N][r][1] + d(i, r));
			dp[i][r][1] = max(dp[i][(r + N - 1) % N][0] + d(r, i), dp[i][(r + N - 1) % N][1] + d(r, (r+ N - 1) % N));
			//cout << "dp[" << i << "][" << r <<"] = " << dp[i][r] << endl;
		}
	}
	double ans = 0;
	for(int i = 0; i < N; i++){
		ans = max(ans, max(dp[(i + 1) % N][(i + N - 1) % N][0] + d(i, (i + 1) % N), dp[(i + 1) % N][(i + N - 1) % N][1] + d(i, (i + N - 1) % N)));
	}
	cout << setprecision(10) << ans << endl;
}

