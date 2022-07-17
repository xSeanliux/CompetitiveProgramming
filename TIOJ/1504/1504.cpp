#include <iostream>
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 526, trials = 4, MOD = 1299709;
int N, M, arr[maxN][maxN], adj[maxN][maxN], u, v, inv[MOD];

inline int modpow(int b, int e){
	int r = 1;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline int Inv(int x){
	return modpow(x, MOD - 2);
}

inline int gauss(){
	for(int i = 0; i < N; i++){
		if(!arr[i][i]){
			for(int j = i + 1; j < N; j++) if(arr[j][i]){
				for(int k = 0; k < N; k++) swap(arr[i][k], arr[j][k]);	
				break;
			}  
		}
		if(!arr[i][i]) continue;
		for(int j = i + 1; j < N; j++){
			int fact = inv[arr[i][i]] * arr[j][i] % MOD;
			for(int k = 0; k < N; k++){
				arr[j][k] = (arr[j][k] + MOD - arr[i][k] * fact % MOD) % MOD;	
			}
		}
	}
	int rank = 0;
	for(int i = 0; i < N; i++) rank += (arr[i][i] != 0);
	return rank;
}

inline void solve(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) arr[i][j] = adj[i][j] = 0;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u][v] = adj[v][u] = 1;
	}
	
	int ans = 0;
	for(int t = 0; t < trials; t++){
		for(int i = 0; i < N; i++) for(int j = i; j < N; j++) if(adj[i][j]){
			arr[i][j] = rand() % MOD;
			arr[j][i] = (MOD - arr[i][j]) % MOD;
		} else arr[i][j] = 0;
		//for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cout << arr[i][j] << " \n"[j == N - 1];
		ans = max(ans, gauss());
	}
	cout << ans / 2 << endl;
}

//N % i = -(N / i) * i
//
//N - N % i = (N / i) * i

signed main(){
	srand(time(NULL));
	ericxiao
	inv[1] = 1;
	for(int i = 2; i < MOD; i++){
		inv[i] = (MOD - (MOD / i)) * inv[MOD % i] % MOD;
	}
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
