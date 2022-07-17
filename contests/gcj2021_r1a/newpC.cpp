#include <iostream>
#define int long long int
using namespace std;

int C, N, Q, sc[2], T;
string res[2];

int gcd(int a, int b){
	return !b ? a : gcd(b , a % b);
}

inline void solve(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> res[i] >> sc[i];
	}
	if(N == 1){
		res[1] = res[0];
		sc[1] = sc[0];
	}
	int denom = 0, cnt[Q], nume = 0;
	fill(cnt, cnt + Q, 0);
	for(int i = 0; i < (1 << Q); i++){
		int A = 0, B = 0;
		for(int j = 0; j < Q; j++){
			if(((i >> j) & 1) ^ (res[0][j] == 'T')) A++;
			if(((i >> j) & 1) ^ (res[1][j] == 'T')) B++;
		}
		if(A == sc[0] && B == sc[1]){
			for(int j = 0; j < Q; j++){
				if(((i >> j) & 1)) cnt[j]++;
			}
			denom++;
		}
	}
	string ans = "";
	for(int i = 0; i < Q; i++){
		if(cnt[i] > denom - cnt[i]){
			ans += 'F';
		} else ans += 'T';
		nume += max(cnt[i], denom - cnt[i]);
	}
	int g = gcd(denom, nume);
	if(!g){
		denom = 1;
		nume = 0;
	} else {
		denom /= g;
		nume /= g;
	}
	cout << "Case #" << ++C << ": " << ans << " " << nume << "/" << denom << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
