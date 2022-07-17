#include <iostream>
#define int long long int
using namespace std;

int dp[18][2], a, b;

inline int get(int x){
	if(x < 0) return 0;
	//cout << "x = " << x << endl;
	string s = to_string(x);
	//cout << "s = " << s << endl;
	dp[0][0] = max(0, s[0] - '1');
	dp[0][1] = 1;
	for(int i = 1; i < s.length(); i++){
		dp[i][0] = 9 * dp[i - 1][0];
		dp[i][1] = 0;
		for(char c = '0'; c <= '9'; c++){
			if(c < s[i] && c != s[i - 1]) dp[i][0] += dp[i - 1][1];
			if(c == s[i] && s[i] != s[i - 1]) dp[i][1] += dp[i - 1][1];
		}
		//cout << "i: " << i << ": " << dp[i][0] << ", " << dp[i][1] << endl;
	}
	int res = dp[s.length() - 1][0] + dp[s.length() - 1][1];
	//cout << "res: " << res << endl;
	int r = 9;
	for(int i = 0; i < (int)s.length() - 1; i++){
		res += r;
		r = r * 9;
	}
	//cout << "Final: " << res << endl;
	return res + (x > 0);
}

signed main(){
	cin >> a >> b;
	cout << get(b) - get(a - 1) << endl;
}
