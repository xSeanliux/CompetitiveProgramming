#include <iostream>
#include <cassert>
#define int long long int
using namespace std;

int T, l, r, x, m;
int ans = 0, t;

inline int mp(int b, int e){
	if(!e) return 1;
	int r = 1, c = b;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1){
			r = r * c % m;
		}
		c = c * c % m;
	}
	return r;
}

inline int inv(int x){
	return mp(x, m - 2);
}

//1 + a + ... + a^p = (a^(p + 1) - 1) / (a - 1)

signed main(){
	cin >> T;
	while(T--){
		cin >> x >> l >> r >> m;
		int ans = (mp(x, r - l + 1) - 1 + m) % m;
		ans = ans * inv(x - 1) % m;
		ans = ans * mp(x, l) % m;
		cout << ans << endl;
	}
}
