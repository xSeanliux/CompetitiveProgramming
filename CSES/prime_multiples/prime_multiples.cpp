#include <iostream>
#define int long long int
using namespace std;


const int maxN = 26;
int N, K, arr[maxN], ans;

void dfs(int now = 0, int cp = 1, bool cnt = 0){
	if(now == K){
		if(cnt) ans += N / cp;	
		else ans -= N / cp;
		return;
	}
	if(arr[now] <= N / cp)
		dfs(now + 1, cp * arr[now], cnt ^ 1);			
	dfs(now + 1, cp, cnt);			
}

signed main(){
	cin >> N >> K;
	for(int i = 0; i < K; i++) cin >> arr[i];
	dfs();
	cout << N + ans << endl;
}
