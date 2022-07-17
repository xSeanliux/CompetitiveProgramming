#include <iostream>
#define int long long int
using namespace std;

int Q;

inline void solve(){
	int K;
	cin >> K;
	if(K <= 9){
		cout << K << endl;
		return;
	}
	int d = 1, roll = 9, jizz = 1;
	//10 * d * (10^(d - 1) - 1)
	while(true){
		if(K > d * roll){
			K -= d * roll;
			d++;
			roll *= 10;
			jizz *= 10;
		} else {
			cout << to_string((K - 1) / d + jizz)[(K - 1) % d] << endl;
			return;
		}
	}
}

signed main(){
	cin >> Q;
	while(Q--){
		solve();
	}
}
