#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 326, maxLog = 20;
const long long int MOD = 1e9 + 7;

int pa[maxN], anc[maxLog][maxN], l[maxN], r[maxN], N, M, u, v, dep[maxN], hsh[maxN];

inline void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	anc[0][u] = p;
	for(int i = 1; i < maxLog; i++) anc[i][u] = anc[i - 1][anc[i - 1][u]];
	if(l[u]){
		hsh[l[u]] = 2 * hsh[u] % MOD;
		dfs(u, l[u]);	
	}
	if(r[u]){
		hsh[r[u]] = (2 * hsh[u] + 1) % MOD;
		dfs(u, r[u]);	
	}
}

int main(){
	ericxiao
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> l[i] >> r[i];
	}
	dfs();
	cin >> M;
	while(M--){
		cin >> u >> v;
		if(hsh[u] == hsh[v]){
			cout << "TAK" << endl;
			continue;
		}
		for(int i = maxLog - 1; i >= 0; i--){
			if(hsh[anc[i][u]] != hsh[anc[i][v]]){
				u = anc[i][u];
				v = anc[i][v];
			}
		}
		if(r[anc[0][u]] == u){
			cout << "TAK" << endl;
		} else {
			cout << "NIE" << endl;
		}
	}
}

