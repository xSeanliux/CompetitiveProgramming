#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 3000 + 226, MOD = 998442353;

int dp[maxN][maxN], dp2[maxN][maxN], ans;
string a, b;
char c;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}
int main(){
	cin >> a >> b;
	for(int i = 0; i < b.length(); i++) dp[i][i] = 2 * (b[i] == a[0]);
	for(int l = b.length() - 1; l >= 0; l--){
		for(int r = l + 1; r < b.length(); r++){
			c = a[r - l];
			if(b[r] == c){
				dp[l][r] = add(dp[l][r], dp[l][r - 1]);
			}
			if(b[l] == c){
				dp[l][r] = add(dp[l][r], dp[l + 1][r]);	
			}
			cout << "dp[" << l << "][" << r << "] = " << dp[l][r] << endl;
		}
	}
	dp2[a.length()][0] = 1;
	for(int i = a.length() - 1; i >= 0; i--){
		dp2[i][0] = dp2[i + 1][0] + 1;
		cout << "dp2[" << i << "][0] = " << dp2[i][0] << endl;
	}
	for(int i = a.length() - 1; i >= 0; i--){
		for(int m = 1; m <= b.length(); m++){
			dp2[i][m] = dp2[i + 1][m];
			if(a[i] == b[m - 1]){
				dp2[i][m] = add(dp2[i][m], dp2[i + 1][m - 1]);	
			}
			cout << "dp2[" << i << "][" << m << "] = " << dp2[i][m] << endl;
		}
	}
	ans = dp2[1][b.length()];
	for(int i = 1; i < b.length(); i++){
		cout << "dp[" << b.length() - i << "][" << b.length() - 1 << "] * dp2[" << i + 1 << "][" << b.length() - i << "]" << endl;
		ans = add(ans, dp[b.length() - i][b.length() - 1] * dp2[i + 1][b.length() - i]);
	}
	ans = add(ans, dp[0][b.length() - 1] * dp2[b.length()][0]);
	cout << ans << endl;
}
