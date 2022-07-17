#include <iostream>
#include <algorithm>
#define int long long int
#define ll __int128
using namespace std;


const ll M1 = 36e11, M2 = 6e10, INV = 2135593220339, F = 12 * 1e10, M = 360 * 12 * 1e10;
int arr[3], h, m, s, ns, c = 0;

inline ll Abs(ll x){
	return (x < 0 ? -x : x);
}

inline bool go(ll A, ll B, ll C){
	if(C % 12 != B % 12) return false;
	ll k1 = (60 * B - C + M1) % M1;
	ll k2 = (12 * A - B + M2) % M2;
	ll x = INV * k1 % M1;
	if(11 * x % M2 != k2) return false;
	//cout << "x = " << (int)(x) << endl;
	A = (A - x + M) % M;
	B = (B - x + M) % M;
	C = (C - x + M) % M;
	if(B % 12 || C % 720) return false;
	for(int i = 0; i < 25; i++){
		ll _A = (A + M1 * i) % M;
		ll _B = (_A % M1) * 12;
		ll _C = (_A % M2) * 720;
		//cout << "i = " << i << ", _A = " << (int)(_A) << ", B = " << (int)(_B) << ", C = " << (int)(_C) << endl;
		if((_A - _B + M) % M == (A - B + M) % M && (_A - _C + M) % M == (A - C + M) % M){
			ns = _A % (int)1e9;
			_A /= (int)1e9;
			s = _A % 60;
			_A /= 60;
			m = _A % 60;
			_A /= 60;
			h = _A % 12;
			return true;
		}
	}
	return false;
}

inline void solve(){
	cin >> arr[0] >> arr[1] >> arr[2];
	do{
		if(go(arr[0], arr[1], arr[2])){
			cout << "Case #" << ++c << ": " << h << " " << m << " " << s << " " << ns << endl;
			return;
		}
	} while(next_permutation(arr, arr + 3));
}

signed main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}

