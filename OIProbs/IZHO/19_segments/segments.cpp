#include <iostream>
#include <utility>
#include <algorithm>
#include <deque>
#define pii pair<int,int> 
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int N, arr[maxN], tag[maxN << 2];

pii seg[maxN << 2]; //gap, ans

inline void pull(int id){
	if(seg[2 * id + 2].F < maxN) seg[id] = seg[2 * id + 2];
	else seg[id] = seg[2 * id + 1];
}

inline void push(int id, int l, int r){
	if(!tag[id]) return;
	if(r - l > 1){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	seg[id].F += tag[id];
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = maxN){
	if(l + 1 == r){
		if(!l){
			seg[id] = {0, 0}; 	
		} else {
			seg[id] = {1e15, l};
		}
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void add(int id, int ql, int qr, int l, int r, int v){
	push(id, l, r);
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		tag[id] += v;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(2 * id + 1, ql, qr, l, m, v);
	add(2 * id + 2, ql, qr, m, r, v);
	pull(id);
}

int dp[maxN], ans;

signed main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	fill(dp, dp + N + 1, 1e16);
	dp[1] = arr[1];
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= N; j++){
			dp[j] += arr[i] - arr[i - 1];
		}
		for(int j = 0; j <= N; j++){
			if(dp[j] < arr[i] - arr[i - 1] && dp[j + 1] >= arr[i] - arr[i - 1]){
				dp[j + 1] = arr[i] - arr[i - 1];
				break;
			}
		}
		for(int j = 0; j <= N; j++) cout << dp[j] << " \n"[j == N];
	}
	for(int i = 1; i <= N; i++) if(dp[i] < 1e16) ans = i;
								else break;
	cout << ans << endl;
}
