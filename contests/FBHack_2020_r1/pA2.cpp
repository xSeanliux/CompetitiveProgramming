#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e6 + 326, MOD = 1e9 + 7;

set<pii> st;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a > b ? a - b : a - b + MOD);
}

int T, N, K, W[maxN], H[maxN], L[maxN], A, B, C, D, c;

inline bool intersect(int a, int b, int c, int d){
	return !(b < c || d < a);
}

inline int intlen(int a, int b, int c, int d){
	return max(0LL, min(b, d) - max(a,c ));
}

inline void solve(){
	cin >> N >> K;
	st = set<pii>();
	for(int i = 0; i < K; i++) cin >> L[i];
	cin >> A >> B >> C >> D;
	A %= D, B %= D, C %= D;
	for(int i = K; i < N; i++) L[i] = (L[i - 2] * A + L[i - 1] * B + C) % D + 1;
	for(int i = 0; i < K; i++) cin >> W[i];
	cin >> A >> B >> C >> D;
	A %= D, B %= D, C %= D;
	for(int i = K; i < N; i++) W[i] = (W[i - 2] * A + W[i - 1] * B + C) % D + 1; 
	for(int i = 0; i < K; i++) cin >> H[i];
	cin >> A >> B >> C >> D;
	A %= D, B %= D, C %= D;
	for(int i = K; i < N; i++) H[i] = (H[i - 2] * A + H[i - 1] * B + C) % D + 1;

	int per = 2 * (H[0] + W[0]) % MOD, pd = per;
	//cout << "per[0] = " << per << endl;
	st.insert({L[0], L[0] + W[0]});
	//cout << "Pushing: " << L[0] << ", " << L[0] + W[0] << endl;
	for(int i = 1; i < N; i++){
		//cout << "i = " << i << ", L = " << L[i] << ", W = " << W[i] << ", H = " << H[i] << endl;
		vector<pii> v;
		auto it = st.lower_bound({L[i], -1});	 
		if(it != st.begin()) --it;
		//cout << "FOund: " << it->F << ", " << it->S << endl;
		for(; it != st.end(); it++){
			if(it->F > L[i] + W[i]) break;
			if(intersect(L[i], L[i] + W[i], it->F, it->S)) v.push_back(*it);
			//cout << "Pushing: " << it->F << ", " << it->S << endl;
		}
		if(v.size()){
			for(auto x : v) st.erase(x);
			st.insert({min((v.front()).F, L[i]), max((v.back()).S, L[i] + W[i])});
			per = add(per, 2 * W[i]);
			for(int j = 0; j < v.size() - 1; j++){
				per = sub(per, 2 * H[i]);
				//cout << "sub: " << 2 * H[i] << endl;
				per = sub(per, 2 * intlen(L[i], L[i] + W[i], v[j].F, v[j].S));
				//cout << "Then sub " <<  2 * intlen(L[i], L[i] + W[i], v[j].F, v[j].S) << endl;
			}
			per = sub(per, 2 * intlen(L[i], L[i] + W[i], v.back().F, v.back().S));
			//cout << "Then sub " << 2 * intlen(L[i], L[i] + W[i], v.back().F, v.back().S) << endl;
		} else {
			st.insert({L[i], L[i] + W[i]});
			per = add(per, 2 * (W[i] + H[i]));
		}
		//cout << "per[" << i << "] = " << per << endl;
		pd = pd * per % MOD;
	}
	cout << "Case #" << ++c << ": " << pd << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
