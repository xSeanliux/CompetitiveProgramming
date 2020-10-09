#include <iostream>
using namespace std;

const int maxN = 2e5 + 226;
int T, N, arr[maxN];

inline void solve(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for(int l = 30; l >= 0; l--){
		int z = 0, o = 0;
		for(int i = 0; i < N; i++){
			((arr[i] >> l) & 1 ? o : z)++;
		}
		/*
		if(o){
			cout << "l = " << l << ", o = " << o << endl;
		}
		*/
		if(o % 2 == 1){
			if(z % 2 == 0 && o % 4 == 3){
				cout << "LOSE\n";
				return;
			} else {
				cout << "WIN\n";
				return;
			}
		}
	}
	cout << "DRAW\n";
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}

