#include <iostream>
using namespace std;

const int maxK = 30;
int T, K, N, x, basis[maxK];

inline void Insert(int x){
	for(int i = K - 1; i >= 0; i--){
		if(!((x >> i) & 1)) continue;
		if(basis[i] == -1){
			basis[i] = x;
			return;
		}
		x ^= basis[i];
	}
}

inline void solve(){
	cin >> K >> N;
	for(int i = 0; i < K; i++) basis[i] = -1;
	for(int i = 0; i < N; i++){
		cin >> x;
		Insert(x);
	}
	x = 0;
	for(int i = 0; i < K; i++) if(basis[i] == -1) x++;
	cout << (1 << x) << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
