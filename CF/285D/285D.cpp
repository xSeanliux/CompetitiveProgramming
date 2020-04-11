#include <iostream>
#define int long long int
using namespace std;


const int MOD = 1e9 + 7, maxN = 20;

int N, ans;
bool usedSum[maxN], used[maxN];
int fact[maxN];

void dfs(int pos = 1){
	if(pos == N + 1){
		ans++;
		if(ans == MOD) ans = 0;
		return;
	}
	for(int i = 1; i <= N; i++){
		if(!usedSum[(pos - 1 + i - 1) % N + 1] && !used[i]){
			used[i] = true;
			usedSum[(pos - 1 + i - 1) % N + 1] = true;
			dfs(pos + 1);
			used[i] = false;
			usedSum[(pos - 1 + i - 1) % N + 1] = false;
		}
	}
}

inline int solve(){
	if((N & 1) == 0) return 0;
	ans = 0;
	fill(usedSum, usedSum + maxN, false);
	fill(used, used + maxN, false);
	dfs();
	return fact[N] * ans % MOD;
}


signed main(){
	/*
	fact[0] = 1;
	for(int i = 1; i < maxN; i++){
		fact[i] = fact[i - 1] * i % MOD;
	}
	for(N = 0; N <= 13; N++){
		cout << solve() << ",";
	}
	cout << fact[15] * 36362925 % MOD << endl;
	cout << endl;
	*/
	int _ans[17] = {0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788, 0, 150347555, 0};
	cin >> N;
	cout << _ans[N] << endl;
}
