#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 1e5 + 226, W = 'z' + 26;

string strings[maxN];
int N, dp[W], cnt, nxtDp[W];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> strings[i];
	for(int i = 0; i < strings[0].length(); i++){
		if(i && strings[0][i] != strings[0][i - 1]) cnt = 0;
		cnt++;
		dp[strings[0][i]] = max(cnt, dp[strings[0][i]]);
	}
	//for(int i = 'a'; i <= 'z'; i++){
	//	if(dp[i]){
	//		cout << (char)(i) << ": " << dp[i] << endl;
	//	}
	//}
	for(int i = 1; i < N; i++){
		fill(nxtDp, nxtDp + W, 0);
		for(int j = 'a'; j <= 'z'; j++){
			nxtDp[j] = (dp[j] > 0);
		}
		cnt = 0;
		for(int j = 0; j < strings[i].length(); j++){
			if(j && strings[i][j] != strings[i][j - 1]) cnt = 0;
			cnt++;
			nxtDp[strings[i][j]]= max(cnt, nxtDp[strings[i][j]]);
		}
		int f = 0, b = 0;
		while(f < strings[i].length() && strings[i][f] == strings[i][0]) f++;
		while(b < strings[i].length() && strings[i][strings[i].length() - b - 1] == strings[i][strings[i].length() - 1]) b++;
		//cout << "f = " << f << ", b = " << b << endl;
		if(strings[i][0] == strings[i][strings[i].length() - 1]){
			if(f == strings[i].length()){
				nxtDp[strings[i][0]] = strings[i].length() * (dp[strings[i][0]] + 1) + dp[strings[i][0]];
			} else if(dp[strings[i][0]]){
				nxtDp[strings[i][0]] = max(nxtDp[strings[i][0]], f + b + 1); 
			}
		} else {
			if(dp[strings[i][0]]){
				nxtDp[strings[i][0]] = max(nxtDp[strings[i][0]], f + 1);
			}
			if(dp[strings[i][strings[i].length() - 1]]){
				nxtDp[strings[i][strings[i].length() - 1]] = max(nxtDp[strings[i][strings[i].length() - 1]], b + 1);
			}
		}
		for(int j = 'a'; j <= 'z'; j++) dp[j] = nxtDp[j];
		//for(int j = 'a'; j <= 'z'; j++){
		//	if(dp[j]){
		//		cout << (char)(j) << ": " << dp[j] << endl;
		//	}
		//}
	}
	int a = 0;
	for(int j = 'a'; j <= 'z'; j++) a = max(a, dp[j]);
	cout << a << endl;
}
