#include <iostream>
#define int long long int
using namespace std;

int T, x, y;

inline bool can(int m){
	int les = 0, points = m;
	while(points >= x && les < y){
		int e = points / x;
		les += e;
		points %= x;
		points += e;
	}
	return les >= y;
}

inline void solve(){
	cin >> x >> y;
	if(x == 1){
		cout << 1 << endl;
		return;
	}
	int l = 0, r = x * y + 1, m;
	while(r - l > 1){
		m = l + (r - l) / 2;
		if(can(m)) r = m;
		else l = m;
	}
	cout << r << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
