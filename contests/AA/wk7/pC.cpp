#include <iostream>
#include <numeric>
using namespace std;

const int maxN = 2e5 + 326;
int dsu[maxN], deg[maxN], odd[maxN], ans[maxN], sz[maxN], N, M, u[maxN], v[maxN], curans;

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	odd[x] = odd[dsu[x]];
	sz[x] = sz[dsu[x]];
	dsu[x] = dsu[dsu[x]];
}

inline int f(int x){
	if(sz[x] == 1) return 0;
	if(odd[x] == 0) return 1;
	return (odd[x]) / 2;
}

inline void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]){
		curans -= f(dsu[a]);			
		odd[dsu[a]] -= deg[a];  
		odd[dsu[b]] -= deg[b];  
		deg[a] ^= 1;
		deg[b] ^= 1;
		odd[dsu[a]] += deg[a];  
		odd[dsu[b]] += deg[b];  
		curans += f(dsu[a]);			
	} else {
		curans -= f(dsu[a]);
		curans -= f(dsu[b]);

		odd[dsu[a]] -= deg[a];  
		odd[dsu[b]] -= deg[b];  
		deg[a] ^= 1;
		deg[b] ^= 1;
		odd[dsu[a]] += deg[a];  
		odd[dsu[b]] += deg[b];  

		sz[dsu[b]] += sz[dsu[a]];
		odd[dsu[b]] += odd[dsu[a]];
		dsu[dsu[a]] = dsu[b];

		curans += f(dsu[b]);
	}
}

int main(){
	cin >> N >> M;
	iota(dsu, dsu + N + 1, 0);
	fill(sz, sz + N + 1, 1);
	for(int i = 0; i < M; i++){
		cin >> u[i] >> v[i];
	}
	for(int i = M - 1; i >= 0; i--){
		Merge(u[i], v[i]);
		ans[i] = curans;
	}
	for(int i = 0; i < M; i++) cout << ans[i] << endl;
}
