#include <iostream>
#define int long long int
using namespace std;

int T;

inline void solve(){
	int x, y, d;
	cin >> d >> x >> y;
	if(d > 1000){
		cout << "1000000000000000001\n";
		return;
	}
	int ans = 0;
	for(int i = 0; i <= d; i++){
		int a = x + i, b = y + i;
		bool f = true;
		while(a | b){
			if(((a % 3) & 1) ^ ((b % 3) & 1)){
				f = false;
				break;
			}
			a /= 3;
			b /= 3;
		}
		if(f){
			ans++;
		}
	}
	cout << ans << endl;
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
