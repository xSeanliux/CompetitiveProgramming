#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxN = 21;
int dp[1 << maxN], w[maxN][1 << maxN], cnt[maxN][maxN], log2[1 << maxN];
int b[30];

string s;

int main(){
	cin >> s;
	for(char c : s) b[c - 'a'] = 1;
	for(int i = 1; i < 26; i++) b[i] += b[i - 1];
	for(char &c : s) c = b[c - 'a'] + 'a' - 1;
	int W = b[25];
	//cout << s << W << endl;
	for(int i = 0; i < W; i++) log2[1 << i] = i;
	for(int i = 0; i < s.length() - 1; i++) cnt[s[i] - 'a'][s[i + 1] - 'a']++;
	for(int i = 0; i < W; i++){
		w[i][0] = 0;
		for(int j = 1; j < (1 << W); j++){
			w[i][j] = w[i][j - (j & -j)] + cnt[i][log2[j & -j]];
		//cout << "w[" << i << "][" << j << "] = " << w[i][j] << endl;
		}
	}
	dp[0] = 0;
	for(int i = 1; i < (1 << W); i++){
		dp[i] = 2 * s.length();
		for(int j = 0; j < W; j++){
			if((i >> j) & 1)
				dp[i] = min(dp[i], dp[i ^ (1 << j)] + w[j][i]);
		}
		//cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	cout << 1 + dp[(1 << W) - 1] << endl;
}
