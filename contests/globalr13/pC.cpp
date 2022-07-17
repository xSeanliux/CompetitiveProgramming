#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 5e3 + 326;
int N, T, arr[maxN], nxt[maxN], pre[maxN];


inline void solve(){
	cin >> N;
	fill(pre, pre + N + 1, 0);
	int ans = 0, cur = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++){
		cur += pre[i];
		int o = arr[i];
		arr[i] += cur;
		if(arr[i] < 1){
			pre[i + 1] -= 1 - arr[i];
			pre[i + 2] += 1 - arr[i];
			arr[i] = 1;
		}
		if(arr[i] > 1) ans += arr[i] - 1;
		if(o > 1){
			pre[i + 2]--;
			pre[min(i + o + 1, N + 1)]++;
		}
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
