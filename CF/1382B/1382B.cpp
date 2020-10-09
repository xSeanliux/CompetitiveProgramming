#include <iostream>
using namespace std;

const int maxN = 1e5 + 226;
int T, N, stone[maxN];

inline void solve(){
	cin >> N;
	for(int i = N - 1; i >= 0; i--){
		cin >> stone[i];
	}
	bool firstWin = true;
	for(int i = 1; i < N; i++){
		if(stone[i] > 1){
			firstWin = true;
		} else {
			firstWin ^= 1;
		}
	}
	cout << (firstWin ? "First" : "Second") << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
