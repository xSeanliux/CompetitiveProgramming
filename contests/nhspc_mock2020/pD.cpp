#pragma gcc optimize("Ofast", "unroll-loops")
#include <iostream>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<int, int> mp;

const int maxN = 5e5 + 326, INF = 2e9;
int N, K, arr[maxN], mx = -INF, mn = INF;
long long int ans;

inline void add(int x){
	mp[x]++;
	mx = max(mx, x);
	mn = min(mn, x);
}

inline void del(int x){
	mp[x]--;
	if(!mp[x]) mp.erase(x);
	if(!mp.size()){
		mx = -INF;
		mn = INF;
		return;
	}
	if(x == mn){
		mn = mp.begin()->F;
	}
	if(x == mx){
		mx = mp.rbegin()->F;
	}
}

int main(){
	ericxiao
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> arr[i];
	int R = -1;
	for(int L = 0; L < N; L++){
		if(R < L){
			add(arr[L]);
			R = L;
		}
		while(R + 1 < N && max(arr[R + 1], mx) - min(arr[R + 1], mn) <= K){
			add(arr[++R]);	
		}
		//[L, R]
		ans += (R - L + 1);	
		del(arr[L]);
	}
	cout << ans << '\n';
}
