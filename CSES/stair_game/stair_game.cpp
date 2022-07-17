#include <iostream>
using namespace std;

inline void solve(){
	int N, x, s = 0;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> x;
		if((i & 1) == 0) s ^= x;
	}
	cout << (s ? "first" : "second") << endl;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
