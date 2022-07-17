#include <iostream>
#include <numeric>
#define int long long int
using namespace std;

const int maxN = 1e6 + 326, B = 101, MOD = 1e9 + 7;
int N, K, p[maxN], bk[maxN], pos[maxN], x[maxN], y[maxN], hshA, hshB, base[maxN];
int ans[maxN], head = 0;

inline int add(int a, int b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

inline int sub(int a, int b){
	return a >= b ? a - b : a - b + MOD;
}


void fS(int a, int b){
	hshA = sub(hshA, base[a] * p[a] % MOD);
	hshA = sub(hshA, base[b] * p[b] % MOD);
	swap(p[a], p[b]);
	hshA = add(hshA, base[a] * p[a] % MOD);
	hshA = add(hshA, base[b] * p[b] % MOD);
}

void bS(int a, int b){
	hshB = sub(hshB, base[a] * bk[a] % MOD);	
	hshB = sub(hshB, base[b] * bk[b] % MOD);	
	swap(bk[a], bk[b]);
	hshB = add(hshB, base[a] * bk[a] % MOD);	
	hshB = add(hshB, base[b] * bk[b] % MOD);	
}

void initHsh(){
	for(int i = 1; i <= N; i++){
		hshA = add(hshA, base[i] * p[i] % MOD);
		hshB = add(hshB, base[i] * bk[i] % MOD);
	}
}

signed main(){
	base[0] = 1;
	cin >> N >> K;
	for(int i = 1; i <= N; i++) base[i] = base[i - 1] * B % MOD;
	for(int i = 1; i <= N; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= K; i++){
		cin >> x[i] >> y[i];
	}
	iota(bk, bk + N + 1, 0);
	for(int i = K; i > 1; i--){
		swap(bk[x[i]], bk[y[i]]);
	}
	initHsh();
	for(int id = 1; id <= K; id++){ 
		//cout << "id = " << id << ", hshA = " << hshA << ", B = " << hshB << endl;
		if(hshA == hshB) ans[head++] = id;		
		//do id, undo id + 1
		if(id + 1 <= K) bS(x[id + 1], y[id + 1]);	
		fS(x[id], y[id]);
	}
	for(int i = 0; i < head; i++) cout << ans[i] << " \n"[i == head - 1];
}
