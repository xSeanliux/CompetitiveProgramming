#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;
int T, N, K, s[maxN], x[maxN], y[maxN], c, A, B, C, D;

inline void solve(){
	cin >> N >> K; 
	int mo = 0, mu = 0, ans = 0, rm = 0;
	for(int i = 0; i < K; i++) cin >> s[i];
	cin >> A >> B >> C >> D;
	for(int i = K; i < N; i++) s[i] = (A * s[i - 2] + B * s[i - 1] + C) % D;
	for(int i = 0; i < K; i++) cin >> x[i];
	cin >> A >> B >> C >> D;
	for(int i = K; i < N; i++) x[i] = (A * x[i - 2] + B * x[i - 1] + C) % D;
	for(int i = 0; i < K; i++) cin >> y[i];
	cin >> A >> B >> C >> D;
	for(int i = K; i < N; i++) y[i] = (A * y[i - 2] + B * y[i - 1] + C) % D;
	
	for(int i = 0; i < N; i++){
		if(s[i] < x[i]){
			mu += x[i] - s[i];
		} else if(s[i] > x[i] + y[i]){
			mo += s[i] - (x[i] + y[i]);
		}
	}
	if(mu >= mo){
		ans = mo;
		mu -= mo;
		for(int i = 0; i < N; i++){ //solve overs
			if(s[i] > x[i] + y[i]) s[i] = x[i] + y[i];
			rm += max(0LL, s[i] - x[i]);
		}
		if(rm >= mu){
			ans += mu;
		} else {
			ans = -1;
		}
	} else {
		ans = mu;
		mo -= mu;
		for(int i = 0; i < N; i++){ //solve unders
			if(s[i] < x[i]){
				s[i] = x[i];
			}
			rm += max(0LL, x[i] + y[i] - s[i]);
		}
		if(rm >= mo){
			ans += mo;
		} else {
			ans = -1;
		}
	}
	cout << "Case #" << ++c << ": " << ans << endl;

}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
