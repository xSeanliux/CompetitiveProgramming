// Knapsack DP is harder than FFT.
#include<iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll,ll> pll;
#define int long long int
#define ff first
#define ss second
#define pb emplace_back
#define AI(x) begin(x),end(x)
template<class I>bool chmax(I&a,I b){return a<b?(a=b,true):false;}
template<class I>bool chmin(I&a,I b){return b<a?(a=b,true):false;} 
#ifdef OWO
#define debug(args...) SDF(#args, args)
#define OIU(args...) ostream& operator<<(ostream&O,args)
#define LKJ(S,B,E,F) template<class...T>OIU(S<T...>s){O<<B;int c=0;for(auto i:s)O<<(c++?", ":"")<<F;return O<<E;}
LKJ(vector,'[',']',i)LKJ(deque,'[',']',i)LKJ(set,'{','}',i)LKJ(multiset,'{','}',i)LKJ(unordered_set,'{','}',i)LKJ(map,'{','}',i.ff<<':'<<i.ss)LKJ(unordered_map,'{','}',i.ff<<':'<<i.ss)
template<class...T>void SDF(const char* s,T...a){int c=sizeof...(T);if(!c){cerr<<"\033[1;32mvoid\033[0m\n";return;}(cerr<<"\033[1;32m("<<s<<") = (",...,(cerr<<a<<(--c?", ":")\033[0m\n")));}
template<class T,size_t N>OIU(array<T,N>a){return O<<vector<T>(AI(a));}template<class...T>OIU(pair<T...>p){return O<<'('<<p.ff<<','<<p.ss<<')';}template<class...T>OIU(tuple<T...>t){return O<<'(',apply([&O](T...s){int c=0;(...,(O<<(c++?", ":"")<<s));},t),O<<')';}
#else
#pragma GCC optimize("Ofast")
#define debug(...) ((void)0)
#endif

const int kN = 100000;
const int kC = 1'000'000'000;
const int MOD = 1'000'000'007;
const int INV2 = (MOD+1)/2;

inline void mad(int &u, int v){
    u = (u + v) % MOD;
}
inline int mul(int u, int v){
    return u * v % MOD;
}

int N, Q;
int m[kN+1], v[kN+1];
int EK[kN+1];

void init(){
	for(int i = 1; i <= N; ++i){
		EK[i] = mul(mul(INV2, m[i]), mul(v[i], v[i]));
	}
}

void modifyMass(int ql, int qr, int x){
	for(int i = ql; i <= qr; ++i){
		mad(m[i], x);
		EK[i] = mul(mul(INV2, m[i]), mul(v[i], v[i]));
	}
	return;
}

void modifyVelocity(int ql, int qr, int x){
	for(int i = ql; i <= qr; ++i){
		mad(v[i], x);
		EK[i] = mul(mul(INV2, m[i]), mul(v[i], v[i]));
	}
	return;
}

int queryEK(int ql, int qr){
	int res = 0;
	for(int i = ql; i <= qr; ++i)
		mad(res, EK[i]);
	return res;
}

signed main(){

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	assert(cin >> N >> Q);
	assert(1 <= N and N <= kN);
	assert(1 <= Q and Q <= kN);


	for(int i = 1; i <= N; ++i){
		assert(cin >> m[i]);
		assert(0 <= m[i] and m[i] <= kC);
	}
	for(int i = 1; i <= N; ++i){
		assert(cin >> v[i]);
		assert(0 <= v[i] and v[i] <= kC);
	}

	init();

	for(int i = 0; i < Q; ++i){
		int t, l, r, x, y;
		assert(cin >> t);
		assert(1 <= t and t <= 3);
		if(t == 1){
			assert(cin >> l >> r >> x);
			assert(1 <= l and l <= r and r <= N);
			assert(0 <= x and x <= kC);
			modifyMass(l, r, x);
		} else if(t == 2){
			assert(cin >> l >> r >> y);
			assert(0 <= l and l <= r and r <= N);
			assert(0 <= y and y <= kC);
			modifyVelocity(l, r, y);
		} else {
			assert(cin >> l >> r);
			assert(0 <= l and l <= r and r <= N);
			cout << queryEK(l, r) << '\n';
		}
	}

	return 0;
}
