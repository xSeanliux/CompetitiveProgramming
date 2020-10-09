#include <iostream>
#include <vector>
#include <fstream>
#define int long long int
using namespace std;

string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/pokemon/", dir;

ifstream infile;
ofstream outfile;

const int maxN = 2e5 + 226, MOD = 998244353;
int N, M, a[maxN], b[maxN], fact[maxN], invfact[maxN], ans, K;
vector<int> lisan;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1){
			r = r * b % MOD;
		}
		b = b * b % MOD;
	}
	return r;
}

inline int inv(int x){
	return exp(x, MOD - 2);
}

inline int C(int a, int b){
	if(b > a) return 0;
	return (fact[a] * invfact[a - b]) % MOD * invfact[b] % MOD;
}

struct BIT{
	int bit[maxN * 2];	
	BIT(){}
	inline void reset(){
		fill(bit, bit + 2 * maxN, 0);
	}
	inline void modify(int p, int x){
		for(; p < maxN * 2; p += p & -p) bit[p] = add(bit[p], x);
	}
	inline int query(int p){
		int r = 0;
		for(; p; p -= p & -p) r = add(r, bit[p]);
		return r;
	}
} bit;

inline void solve(string folder, int tc){
	dir = _dir + folder + "/" + to_string(tc); 
	outfile.open(dir + ".out");
	ans = 0;
	infile.open(dir + ".in");
	vector<int>().swap(lisan);
	fact[0] = invfact[0] = 1;
	for(int i = 1; i < maxN; i++){
		fact[i] = i * fact[i - 1] % MOD;
		invfact[i] = inv(fact[i]);
	}
	infile >> N >> M >> K;
	for(int i = 0; i < N; i++){
		infile >> a[i];
		lisan.push_back(a[i]);
	}
	for(int i = 0; i < M; i++){
		infile >> b[i];
		lisan.push_back(b[i]);
	}
	sort(lisan.begin(), lisan.end());
	int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(int i = 0; i < N; i++) a[i] = lower_bound(lisan.begin(), lisan.begin() + sz, a[i]) - lisan.begin() + 1;
	for(int i = 0; i < M; i++) b[i] = lower_bound(lisan.begin(), lisan.begin() + sz, b[i]) - lisan.begin() + 1;
	sort(a, a + N);
	sort(b, b + M);
	for(int r = 1; r <= K; r++){
		bit.reset();
		for(int i = r - 1; i < M; i++){
			bit.modify(b[i], C(i, r - 1) * C(M - i - 1, K - r) % MOD);
		}
		for(int i = r - 1; i < N; i++){
			ans = add(ans, bit.query(a[i]) * C(i, r - 1) % MOD * C(N - i - 1, K - r) % MOD); 
		}
	}
	outfile << ans * inv(C(N, K) * C(M, K) % MOD) % MOD << endl;
	infile.close();
	outfile.close();
	cout << "Solved: " << folder << " / " << tc << endl;
}

signed main(){
	for(int t = 51; t <= 60; t++) solve("alltest", t);
}

