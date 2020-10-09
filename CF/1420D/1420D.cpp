#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326, MOD = 998244353;
int N, K, l[maxN], r[maxN], fact[maxN], invfact[maxN]; 
vector<int> lisan, st[maxN], ed[maxN];

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = b * r % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline int inv(int x){
	return exp(x, MOD - 2);
}

inline int choose(int n, int k){
	if(n < 0 || n < k) return 0;
	return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD;
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

signed main(){
	ericxiao;
	cin >> N >> K;
	fact[0] = invfact[0] = 1;
	for(int i = 1; i <= N; i++){
		fact[i] = fact[i - 1] * i % MOD;
		invfact[i] = inv(fact[i]);
		//cout << i << "!^-1 = " << invfact[i] << endl;
	}
	for(int i = 0; i < N; i++){
		cin >> l[i] >> r[i];
		lisan.push_back(l[i]);
		lisan.push_back(r[i]);
	}
	sort(lisan.begin(), lisan.end());
	int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(int i = 0; i < N; i++){
		l[i] = lower_bound(lisan.begin(), lisan.begin() + sz, l[i]) - lisan.begin();
		r[i] = lower_bound(lisan.begin(), lisan.begin() + sz, r[i]) - lisan.begin();
		st[l[i]].push_back(i);
		ed[r[i]].push_back(i);
	}
	int ans = 0, cnt = 0;
	for(int i = 0; i < sz; i++){
		//cout << "i = " << i << endl;
		for(int x : st[i]){
			//cout << "cnt = " << cnt << endl;
			//cout << cnt << "C" << K - 1 << " = " << choose(cnt, K - 1) << endl;
			ans = add(ans, choose(cnt, K - 1));
			cnt++;
		}
		cnt -= ed[i].size();
		//cout << "at the end of time " << i << ", cnt = " << cnt << endl;
	}
	cout << ans << endl;
}
