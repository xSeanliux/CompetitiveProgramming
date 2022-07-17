#include <iostream>
using namespace std;

int T, N, K;

inline void solve(){
	cin >> N >> K;
	if(!K){
		cout << "1 1" << endl;
		return;
	}
	int bc = 0;
	for(int i = 0; i < N; i++) bc += ((K >> i) & 1);
	cout << bc + 1 << " " << (1 << N) - ((K & -K) - 1) << endl;
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
