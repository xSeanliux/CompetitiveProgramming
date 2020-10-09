#include <iostream>
#define int long long int
using namespace std;

int T, M, l, r;

inline void solve(){
	cin >> l >> r >> M;
	for(int a = l; a <= r; a++){
		if((M % a) <= r - l){
			int c = l, b = l + (M % a); 
			if((M + c - b) > 0){
				cout << a << " " << b << " " << c << endl;
				return;
			}
		}
		if((a - M % a) <= r - l){
			int c = l + a - (M % a), b = l;
			if((M + c - b) > 0){
				cout << a << " " << b << " " << c << endl;
				return;
			}
		}
	}
	return;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
