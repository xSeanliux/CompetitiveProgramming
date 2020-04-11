#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <ostream>
#define vv vector<vector<int> >
#define int long long int
using namespace std;

const int MOD = 1e9 + 9;
int N, M, s, t, K, u, v;
vv I, adj, res;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline vv operator*(vv a, vv b){
	res.resize(N);
	for(int i = 0; i < N; i++){
		res[i].resize(N);
		for(int j = 0; j < N; j++){
			res[i][j] = 0;
			for(int k = 0; k < N; k++){
				res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
			}
		}
	}
	return res;
}

inline vv operator^(vv b, int e){
	if(!e) return I;
	vv r = b ^ (e / 2);
	r = r * r;
	if(e % 2 == 1) r = r * b;
	return r;
}

inline int modpow(int b, int e){
	if(!e) return 1;
	int r = modpow(b, e / 2);
	r = r * r % MOD;
	if(e % 2 == 1) r = r * b % MOD;
	return r;
}

inline int inv(int x){
	return modpow(x, MOD - 2);
}

string dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/jokebomb/testcases/T";
ifstream infile;
ofstream outfile;
set<int> _adj[101];

void solve(){
	infile >> N >> M >> s >> K;	
	s--;
	//cout << "N = " << N << ", M = " << M << ", s = " << s << ", K = " << K << endl;
	adj.resize(N);
	I.resize(N);
	for(int i = 0; i < N; i++){
		adj[i].resize(N);
		_adj[i] = set<int>();
		I[i].resize(N);
		for(int j = 0; j < N; j++) adj[i][j] = 0;
		I[i][i] = 1;
	}
	while(M--){
		infile >> u >> v;
		u--;
		v--;
		_adj[u].insert(v);
	}
	for(int i = 0; i < N; i++){
		for(int v : _adj[i]){
			adj[i][v] = inv(_adj[i].size() + 1);	
		}
		adj[i][i] = inv(_adj[i].size() + 1);
	}
	adj = adj ^ (K);
	for(int i = 0; i < N; i++){
		outfile << adj[s][i] << " \n"[i == N - 1]; 
	}
}

signed main(){
	for(int subtask = 1; subtask <= 5; subtask++){
		for(int tc = 10 * (subtask - 1) + 1; tc <= 10 * subtask; tc++){
			cout << dir + to_string(subtask) + "/" + to_string(tc) + ".in" << endl;
			infile.open(dir + to_string(subtask) + "/" + to_string(tc) + ".in");	
			outfile.open(dir + to_string(subtask) + "/" + to_string(tc) + ".out");	
			solve();
			infile.close();
			outfile.close();
		}
	}
}
